#ifndef SUDOKU_H
#define SUDOKU_H

/*
Este módulo implementa todas as classes que fazem parte de um jogo de sudoku, tanto para a modalidade normal quanto para o desafio diário.
Faz uso dos módulos "usuario" e "tabela".
*/

#include "../users/usuario.hpp"
#include "../users/tabela.hpp"
#include "cronometro.hpp"
#include "gerador.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <memory>

using namespace std;

class Jogador : public Usuario {
    private:
        int _vidas;
        int _pontos_obtidos;
        int _vitoria_obtida;


    public:
        Jogador();
        ~Jogador();

        int getVidas();
        int getPontosObtidos();
        int getVitoriaObtida();
        void setVidas(int vidas);  
        void setPontosObtidos(int pontos_obtidos);
        void setVitoriaObtida(int vitoria_obtida); 

        void mensagem();  

        void atualizarEstatisticas();   
};


class Celula {
    private:
        int _valor, _x, _y;
        vector<int> _possiveis_valores;
        bool _visivel;

    public:
        Celula(int valor, bool visivel, int x, int y);
        Celula(const Celula& celula_original);
        ~Celula();

        int getValor();
        int getX();
        int getY();
        vector<int> getVetor();
        bool getVisivel();

        void mensagem();  

        void setValor(int valor);
        void setVetor(vector<int> possiveis_valores);
        void setVisivel(bool visivel);
    };

class Tabuleiro {
    private:
        vector<vector<shared_ptr<Celula>>> _matriz;

    public:
        Tabuleiro();
        ~Tabuleiro();

        void mensagem();  

        bool criarTabuleiroNormal(string path);
            //retorna false se não conseguiu criar o tabuleiro.
        bool criarTabuleiroDesafio(string path);
            //retorna false se não conseguiu criar o tabuleiro.

        void exibirTabuleiro();
            //apenas exibe o tabuleiro na tela.
        bool verificarJogada(int i, int j, int valor);
            //se a jogada foi um acerto, atualiza o tabuleiro e retorna true, se errou retorna false.
        bool verificarVitoria();
            //se o tabuleiro estiver completo, retorna true.
};

class Partida {
    private:
        Tabuleiro* _tabuleiro;
        shared_ptr<Jogador> _jogador;
        Cronometro* _cronometro;
        bool _jogando;

    public:
        Partida(shared_ptr<Jogador> jogador);
        ~Partida();

        Tabuleiro* getTabuleiro();
        shared_ptr<Jogador> getJogador();
        Cronometro* getCronometro();
        bool getJogando();
        void setJogando(bool jogando);

        void mensagem();  

        bool virtual iniciarPartida() = 0;

        void virtual calcularPontosObtidos(time_t tempo) = 0;

        void fazerJogada(int i, int j, int valor);
            //se acertou, atualiza o tabuleiro, exibe ele novamente e verifica se o jogo terminou.
            //se errou, tira uma vida e verifica se vidas = 0, caso afirmativo, o jogo termina como derrota.
};

class PartidaNormal : public Partida {
    private:
        int _dificuldade;

    public:
        PartidaNormal(int dificuldade, shared_ptr<Jogador> jogador);
        ~PartidaNormal();

        void mensagem();  

        bool iniciarPartida() override;
            //retorna false se não conseguiu iniciar a partida.

        void calcularPontosObtidos(time_t tempo) override;
            //chamar no final da partida para calcular os pontos obtidos.
};

class PartidaDesafio : public Partida {
    private:
        int _tempo_limite;
    
    public:
        PartidaDesafio(int tempo_limite, shared_ptr<Jogador> jogador);
        ~PartidaDesafio();
        
        void mensagem();  

        bool iniciarPartida() override;
            //retorna false se não conseguiu iniciar a partida.

        void calcularPontosObtidos(time_t tempo) override;
            //chamar no final da partida para calcular os pontos obtidos.
};

#endif