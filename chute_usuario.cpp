#include <iostream>
#include <map> 
#include <vector>
#include "letra_existe.hpp"

extern std::map<char, bool> chutou; // informando que a variável será utilizada aqui, porém foi definida em outro lugar
extern std::vector<char>chutes_errados;
void chute_usuario()
{
    std::cout << "Seu chute: ";
    char chute;
    std::cin >> chute;

    chutou[chute] = true;

    if (letra_existe(chute))
    {
        std::cout << "Voce acertou! Seu chute esta na palavra!" << std::endl;
    }
    else
    {
        std::cout << "Voce errou! Seu chute nao esta na palavra" << std::endl;
        chutes_errados.push_back(chute);
    }
    std::cout << std::endl;
}