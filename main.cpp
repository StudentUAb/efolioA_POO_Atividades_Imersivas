/*
**============================================================================
** UC: 21093 - Programação por Objectos - 03
** e-fólio A  2022-23 (efolioa.cpp)
**
** Aluno: 2100927 - Ivo Baptista
** Name        : EfolioA.cpp
** Author      : Ivo Baptista
** Version     : 1.0
** Copyright   : Your copyright notice
** Description : Atividades Imersivas in C++, Ansi-style
** ===========================================================================
*/

/*Pretende-se que construa um pequeno programa para exploração simples de
atividades imersivas, guardadas com as suas três coordenadas. Cada atividade
imersiva é composta por: 1) uma string com o seu título; 2) uma string com a sua
descrição; 3) uma string com o URL de um vídeo que a apresenta; 4) três floats
que representam as coordenadas da atividade no espaço conceptual da imersão:
sistema, narrativa, agência.   */
#include <algorithm>
#include "atividades.h"
#include <iostream>
#include "lista.h"

/************************************************************
    Função para validar entre 0 e 1
    a entrada de Sistema, Narrativa e Agencia
    utilizamos o try-catch
************************************************************/
float le_valor_numerico(std::string texto) {
  while (true) {
    std::string sistematexto;
    float sistemaConvertido;
    std::cout << texto << std::endl;
    std::cin >> sistematexto;
    try {
      sistemaConvertido = std::stof(sistematexto);
      bool sucesso = sistemaConvertido >= 0 && sistemaConvertido <= 1;
      if (sucesso == true) {
        return sistemaConvertido;
      } else {
        std::cout << "O numero tem de estar entre 0 e 1" << std::endl;
      }
    } catch (...) {
      std::cout << "Valor invalido, entre com numero" << std::endl;
    }
  }
  return 0;
}
/************************************************************
              Inicio do programa
************************************************************/
int main() {
  char op = 0;
  auto lista = Lista();
  /************************************************************
     Definimos um While infinito para
     cadastrar, até selecionar (s) para sair
  ************************************************************/
  while (true) {
    std::cout << "Quer (c)adastrar ou (s)air?" << std::endl;
    std::cin >> op;
    if (op != 'c') {
      break;
    }
    /************************************************************
          Definimos Variaveis para leitura de dados
    ************************************************************/
    std::string titulo;
    std::string descricao;
    std::string url;
    /************************************************************
           Inicio da entrada de dados na Tela
    ************************************************************/
    std::cout << "Entre o Titulo:" << std::endl;
    std::cin >> titulo;
    std::cout << "Entre a Descricao;" << std::endl;
    std::cin >> descricao;
    // criamos um while para validar o Url
    while (true) {
      std::cout << "Entre a url;" << std::endl;
      std::cin >> url;
      // aqui definimos o if para Validar url
      if (urlValido(url)) {
        std::cout << "URL Valido" << std::endl;
        // criamos objeto atividadeatual
        auto atividadeatual = Atividade(titulo, descricao, url);
        // Definimos no objeto a entrada de sistema, narrativa e agencia
        // validando o valor entre 0 e 1, com a funçâo le_valor_numerico
        atividadeatual.setSistema(
            le_valor_numerico("Entre com valor de sistema"));
        atividadeatual.setNarrativa(
            le_valor_numerico("Entre com valor da narrativa"));
        atividadeatual.setAgencia(
            le_valor_numerico("Entre com valor da agencia"));
        // entrada de dados no vector
        lista.adicionar(atividadeatual);
        break;
      } else {
        std::cout << "URL não Valido" << std::endl;
      }
    }
  }
  /************************************************************
         Saida de dados na Tela ordenado
         por Sistema, Narrativa e Agencia
  ************************************************************/
  std::cout << "_______________________________________________________________"
            << std::endl;
  std::cout << "Ordenado por Sistema:" << std::endl << std::endl;
  std::cout << "Titulo"
            << "\t"
            << "Descricao"
            << "\t"
            << "Url                 "
            << "\t"
            << "Sistema"
            << "\t"
            << "Narrativa"
            << "\t"
            << "Agencia" << std::endl;
  lista.ordena();
  lista.imprime();
  std::cout << "_______________________________________________________________"
            << std::endl;
  std::cout << "Ordenado por Narrativa:" << std::endl;
  std::cout << std::endl;
  std::cout << "Titulo"
            << "\t"
            << "Descricao"
            << "\t"
            << "Url                 "
            << "\t"
            << "Sistema"
            << "\t"
            << "Narrativa"
            << "\t"
            << "Agencia" << std::endl;
  lista.ordenaNarrativa();
  lista.imprimeNarrativa();
  std::cout << "_______________________________________________________________"
            << std::endl;
  std::cout << "Ordenado por Agencia:" << std::endl;
  std::cout << std::endl;
  std::cout << "Titulo"
            << "\t"
            << "Descricao"
            << "\t"
            << "Url                 "
            << "\t"
            << "Sistema"
            << "\t"
            << "Narrativa"
            << "\t"
            << "Agencia" << std::endl;
  lista.ordenaAgencia();
  lista.imprimeAgencia();
  std::cout << "_______________________________________________________________"
            << std::endl;
  lista.MaxSistema();
  std::cout << "_______________________________________________________________"
            << std::endl;
  lista.MaxNarrativa();
  std::cout << "_______________________________________________________________"
            << std::endl;
  lista.MaxAgencia();
  std::cout << "_______________________________________________________________"
            << std::endl;
  /*********************************************
         Mostra os valores mais altos
         de Sistema, Narrativa e Agencia
  **********************************************/
  lista.mostraMaiorSistema();
  lista.mostraMaiorNarrativa();
  lista.mostraMaiorAgencia();
  return 0;
}
