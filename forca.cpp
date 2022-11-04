#include <iostream>
#include <string>
using namespace std;

const string PALAVRA_SECRETA = "MELANCIA";

bool letra_existe(char chute)
{
    for (int i = 0; i < PALAVRA_SECRETA.size(); i++)
    {
        if (chute == PALAVRA_SECRETA[i])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    

    bool nao_acertou = true;  // no começo não acertou a palavra secreta, então o valor é true
    bool nao_enforcou = true; // no começo ainda não perdeu, então recebe true;

    while (nao_acertou && nao_enforcou)
    {
        char chute;
        cin >> chute;

        if (letra_existe(chute))
        {
            cout << "Voce acertou! Seu chute esta na palavra!" << endl;
        }
        else
        {
            cout << "Voce errou! Seu chute nao esta na palavra" << endl;
        }
    }
}