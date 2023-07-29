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
#pragma once
#include <iostream>
#include <regex>
#include <string>

/************************************************************
    Definição da Clase Atividade
************************************************************/
class Atividade {
  /************************************************************
      Construtor principal
  ************************************************************/
public:
  Atividade(std::string titulo, std::string descricao, std::string url);

  // getters
  std::string getTitulo() const;
  std::string getDescricao() const;
  std::string getUrl() const;
  float getSistema() const;
  float getNarrativa() const;
  float getAgencia() const;
  // Funções para imprimir na tela
  void imprime() const;
  void imprimeNarrativa() const;
  void imprimeAgencia() const;
  void impMaiorSistema() const;
  void impMaiorNarrativa() const;
  void impMaiorAgencia() const;
  // setters
  bool setSistema(float valor);
  bool setNarrativa(float valor);
  bool setAgencia(float valor);

  /************************************************************
      Variáveis privadas
  ************************************************************/
private:
  std::string m_titulo;
  std::string m_descricao;
  std::string m_url;
  std::string url;
  float m_sistema;
  float m_narrativa;
  float m_agencia;
};

/************************************************************
  Funções aplicando o conceito de sobrecarga de operadores
************************************************************/

bool operator<(Atividade izq, Atividade dir);

bool compareNarrativa(Atividade izq, Atividade dir);

bool compareAgencia(Atividade izq, Atividade dir);

// bool maiorAtividade(Atividade izq, Atividade dir);

bool urlValido(std::string url);
