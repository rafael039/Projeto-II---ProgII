#include <iostream>
#include <windows.h>
#include <string.h>
#include <sstream>

#include <fstream>
#include <conio2.h>
#include <time.h>


using namespace std;

#include "struct.h"
#include "design.h"
#include "consultas.h"
#include "funcoes.h"



int main()
{
    int opcao;
    cout << "Escolha as opcoes: " << endl;
    cout << "[1] Exibir Consultas do dia: " << endl;
    cout << "[2] Relatorio do medico: " << endl;
    cout << "[3] Pacientes do dia: " << endl;
    cout << "[4] Sair" << endl;

    cin >> opcao;
    int *crm;
    switch(opcao)
    {
    case 1:
        listarConsulta(crm);
        espera_limpa();
        break;
    case 2:
        relatorioMedico();
        espera_limpa();
        break;
    case 3:
        listarConsultaDia(crm);
        espera_limpa();
        break;
    case 4:
        espera_limpa();
        break;
    }

    return 0;
}
