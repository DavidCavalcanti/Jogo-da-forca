#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "nao_acertou.hpp"
#include "letra_existe.hpp"
#include "adiciona_palavra.hpp"
#include "chute_usuario.hpp"
#include "exibir_cabecalho.hpp"
#include "imprime_chutes_errados.hpp"
#include "imprime_palavra.hpp"
#include "ler_arquivo.hpp"
#include "nao_enforcou.hpp"
#include "salva_arquivo.hpp"
#include "sorteia_palavra.hpp"

using namespace std;

string palavra_secreta;
map<char, bool> chutou;
vector<char> chutes_errados;


int main()
{
    exibir_cabecalho();

    ler_arquivo();

    sorteia_palavra();

    while (nao_acertou() && nao_enforcou())
    {
        imprime_chutes_errados();

        imprime_palavra();

        chute_usuario();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra eh: " << palavra_secreta << endl;
    if (nao_acertou())
    {
        cout << "Voce perdeu!" << endl;
    }
    else
    {
        cout << "Voce acertou a palavra secreta!" << endl;

        cout << "Voce deseja adicionar uma nova palavra ao banco de palavras? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S')
        {
            adiciona_palavra();
        }
    }
}