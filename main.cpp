#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "funcoes.h"
using namespace std;

int main()
{
    int opcao;
    cout << "Escolha as opcoes: " << endl;
    cout << "[1] Exibir Consultas do dia: " << endl;
    cout << "[2] Relatorio do medico: " << endl;
    cout << "[3] Pacientes do dia: " << endl;
    cout << "[4] Sair" << endl;

    cin >> opcao;
    switch(opcao)
    {
    case 1:
        listarConsultaDia();
        espera_limpa();
        break;
    case 2:
        relatorioMedico();
        espera_limpa();
        break;
    case 3:
        escolhasPacientes();
        break;
    case 4:
        exit;
        espera_limpa();
        break;
    }
    return 0;
}
