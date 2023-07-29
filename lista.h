#pragma once
#include "atividades.h"

#include <vector>


class Lista
{
public:
    void adicionar(Atividade valor);
    void ordena();
    void imprime();
private:
      std::vector<Atividade> m_atividades;


};


