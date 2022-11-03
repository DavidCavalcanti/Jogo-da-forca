#include <iostream>
#include <string>
using namespace std;

int main()
{
    string palavra_secreta = "MELANCIA";

    bool nao_acertou = true; // no começo não acertou a palavra secreta, então o valor é true
    bool nao_enforcou = true; // no começo ainda não perdeu, então recebe true;

    while (nao_acertou && nao_enforcou)
    {
        char chute;
        cin >> chute;

        cout << "Seu chute foi " << chute << endl;
    }
    
}