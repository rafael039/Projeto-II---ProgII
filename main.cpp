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
    cout << "Escolha as opcoes: " << endl << endl;
    cout << "[1] Exibir Consultas: " << endl;
    cout << "[2] Relatorio do Medico: " << endl;
    cout << "[3] Exibir Pacientes do Dia: " << endl;
    cout << "[4] Sair" << endl;

    cin >> opcao;
    int *crm;
    switch(opcao)
    {
    case 1:
        listarConsulta(crm);
        espera_limpa();
        break;
    case 3:
        listarConsultaDia(crm);
        espera_limpa();
        break;
    case 4:
        cout << "Tchau !!!";
        espera_limpa();
        break;
    }

    return 0;
}
