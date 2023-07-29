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
#include "atividades.h"
#include <iostream>
#include <regex>

/************************************************************
    Construtor principal
************************************************************/
Atividade::Atividade(std::string titulo, std::string descricao, std::string url)
    : m_titulo(titulo), m_descricao(descricao), m_url(url), m_sistema(0.0),
      m_narrativa(0.0), m_agencia(0.0) {
  // construtor vazio
}
/************************************************************
   Getters
************************************************************/
std::string Atividade::getTitulo() const { return m_titulo; }

std::string Atividade::getDescricao() const { return m_descricao; }
std::string Atividade::getUrl() const { return m_url; }
float Atividade::getSistema() const { return m_sistema; }
float Atividade::getNarrativa() const { return m_narrativa; }
float Atividade::getAgencia() const { return m_agencia; }
/******************************************************************
  Funções para imprimir as listas por Sistema, Narrativa e Agencia
*******************************************************************/
void Atividade::imprime() const {
  std::cout << m_titulo << "\t"<< m_descricao << "\t" << m_url
            << "\t" << m_sistema << "\t" << m_narrativa
            << "\t" << m_agencia << std::endl;
}
void Atividade::imprimeNarrativa() const {
  std::cout << m_titulo << "\t" << m_descricao << "\t" << m_url
            << "\t" << m_sistema << "\t" << m_narrativa
            << "\t" << m_agencia << std::endl;
}
void Atividade::imprimeAgencia() const {
  std::cout << m_titulo << "\t"<< m_descricao << "\t" << m_url
            << "\t"<< m_sistema << "\t" << m_narrativa
            <<"\t"<< m_agencia << std::endl;
}
/*********************************************
       Funções para imprimir o valor maximo
**********************************************/
void Atividade::impMaiorSistema() const {
  std::cout << std::endl;
  std::cout << "Valor MAXIMO de Sistema - Narrativa - Agencia\t"
            << m_sistema;
}
void Atividade::impMaiorNarrativa() const {
  std::cout << "\t"<< m_narrativa;
}
void Atividade::impMaiorAgencia() const {
  std::cout << "\t"<< m_agencia << std::endl;
}
/************************************************************
    Setters
************************************************************/
bool Atividade::setSistema(float valor) {
  if (valor < 0.0 || valor > 1.0) {
    return false;
  }
  m_sistema = valor;
  return true;
}

bool Atividade::setNarrativa(float valor) {
  if (valor < 0.0 || valor > 1.0) {
    return false;
  }
  m_narrativa = valor;
  return true;
}
bool Atividade::setAgencia(float valor) {
  if (valor < 0.0 || valor > 1.0) {
    return false;
  }
  m_agencia = valor;
  return true;
}
/*****************************************************************
   O algoritmo de ordenaçao utiliza por padrao o simbolo <
 nestas Funções aplicamos o conceito de sobrecarga de operadores
******************************************************************/

bool operator<(Atividade izq, Atividade dir) {
  return izq.getSistema() < dir.getSistema();
}
bool compareNarrativa(Atividade izq, Atividade dir) {
  return izq.getNarrativa() < dir.getNarrativa();
}
bool compareAgencia(Atividade izq, Atividade dir) {
  return izq.getAgencia() < dir.getAgencia();
}


/************************************************************
    Função para validar o URL utilizado RegEx
************************************************************/
bool urlValido(std::string url) {
  // Aqui este Regex valida url como correcto
  const std::regex pattern(
      "((http|https)://)(www.)?[a-zA-Z0-9@:%._\\+~#?&//"
      "=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%._\\+~#?&//=]*)");
  if (url.empty()) {
    // Se url estiver vazio retorna falso
    return false;
  }
  // Retorna true se o url coicide com o pattern do regex
  if (regex_match(url, pattern)) {
    return true;
  } else {
    // Retorna false se o url coicide com o pattern do regex
    return false;
  }
}
