#include <iostream>
#include <string>
#include <map>
#include <vector>
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

int main()
{

    cout << "*********************" << endl;
    cout << "*** Jogo da Forca ***" << endl;
    cout << "*********************" << endl
         << endl;

    while (nao_acertou() && nao_enforcou())
    {
        cout << "Chutes errados: ";
        for (char letra : chutes_errados)
        {
            cout << letra << " ";
        }
        cout << endl;
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