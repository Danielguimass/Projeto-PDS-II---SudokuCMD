#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
//#include <ctime>

using namespace std;

/*
class Usuario{
    private:
        string _nome;
        double _pontuacao;
    public:
        Usuario();
        Usuario(string nome, double pontuacao);
        ~Usuario();

        string getNome();
        double getPontuacao();
        void setNome(string nome);
        void setPontuacao(double pontuacao);

        void calcularPontuacao(time_t tempo, int dificuldade, int vidas);
};
*/

class Estatisticas {
    private:
        string _path_usuarios;
        int _pontuacao_total;
        int _partidas;
        int _vitorias;
        int _ultimo_desafio_diario;
        
    public:
        Estatisticas();
        Estatisticas(string path_usuarios);
        ~Estatisticas();

        int getPontuacaoTotal();
        int getPartidas();
        int getVitorias();
        int getUltimoDesafioDiario();
        void setPontuacaoTotal(int pontuacao_total);
        void setPartidas(int partidas);
        void setVitorias(int vitorias);
        void setUltimoDesafioDiario(int ultimo_desafio_diario);


        void carregarEstatisticas();
            //carrega as estatisticas do usuarios.txt
        void enviarEstatisticas();        
            //envia as estatisticas para o usuarios.txt
};

class Usuario {
    private:
        string _nome;
        Estatisticas* _estatisticas;

    public:
        Usuario();
        Usuario(string path_usuarios);
        ~Usuario();

        string getNome();
        Estatisticas* getEstatisticas();
        void setNome(string nome);
        void setEstatisticas(Estatisticas* estatisticas);

        bool carregarUsuario(string nome, string senha);
            //retorne true se o login foi bem sucessido, false caso contrário
        bool criarUsuario(string nome, string senha);
            //retorne true se a conta foi criada, false caso contrário
};

#endif