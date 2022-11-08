#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute)
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chute == letra)
        {
            return true;
        }
    }
    return false;
}

bool nao_acertou()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (!chutou[letra])
        {
            return true;
        }
    }
    return false;
}

bool nao_enforcou()
{
    return chutes_errados.size() < 5; // se for menor que 5 retorna verdadeiro
}

void exibir_cabecalho()
{
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl
         << endl;
}

void imprime_chutes_errados()
{
    cout << "Chutes errados: ";
    for (char letra : chutes_errados)
    {
        cout << letra << " ";
    }
    cout << endl;
}

void imprime_palavra()
{
    for (char letra : PALAVRA_SECRETA)
    {
        if (chutou[letra])
        {
            cout << letra << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chute_usuario()
{
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute))
    {
        cout << "Voce acertou! Seu chute esta na palavra!" << endl;
    }
    else
    {
        cout << "Voce errou! Seu chute nao esta na palavra" << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

vector<string> ler_arquivo()
{
    ifstream arquivo;
    arquivo.open("palavras.txt");
    int quantidade_de_palavras;
    arquivo >> quantidade_de_palavras;

    vector<string> palavras_do_arquivo;

    for (int i = 0; i < quantidade_de_palavras; i++)
    {
        string palavra_lida;
        arquivo >> palavra_lida;

        palavras_do_arquivo.push_back(palavra_lida);
    }

    return palavras_do_arquivo;
}

int main()
{
    exibir_cabecalho();

    ler_arquivo();

    while (nao_acertou() && nao_enforcou())
    {
        imprime_chutes_errados();

        imprime_palavra();

        chute_usuario();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra eh: " << PALAVRA_SECRETA << endl;
    if (nao_acertou())
    {
        cout << "Voce perdeu!" << endl;
    }
    else
    {
        cout << "Voce acertou a palavra secreta!" << endl;
    }
}