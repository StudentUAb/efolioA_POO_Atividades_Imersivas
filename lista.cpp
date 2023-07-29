#include "lista.h"
#include <algorithm>

void Lista::adicionar(Atividade valor){
   m_atividades.push_back(valor);//adiciona valor dentro do vetor
}
// ordena por agencia
void Lista::ordena(){
    std::sort(std::begin(m_atividades),std::end(m_atividades), compareAgencia);

}

void Lista::imprime(){
   for (const auto& valoratual : m_atividades){
       valoratual.imprime();
   }
}

