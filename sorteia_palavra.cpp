#include <string>
#include <vector>
#include <ctime>
#include "ler_arquivo.hpp"

extern std::string palavra_secreta;

void sorteia_palavra()
{
    std::vector<std::string> palavra = ler_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavra.size();

    palavra_secreta = palavra[indice_sorteado];
}