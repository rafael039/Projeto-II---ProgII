#include <iostream>
#include <windows.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>

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
    textbackground(COR_FUNDO);
    clrscr();
    textcolor(BLACK);
    logo();
    barraNotificacao();


    criaMenu(3,30,34,14,COR_LOGO,COR_LETRA2);
    gotoxy(32,14);
    cout << "\n Escolha as opcoes: " << endl << endl;
    criaMenu(5,30,34,16,COR_LETRA2,COR_LETRA1);
    gotoxy(6,11);
    cout << "[1] Exibir Consultas: " << endl;
    gotoxy(6,12);
    cout << "[2] Exibir Pacientes do Dia: " << endl;
    gotoxy(6,13);
    cout << "[3] Sair" << endl;

    cin >> opcao;
    gotoxy(6,14);

    // Ponteiro q aponta outro ponteiro de crm, para comparar medico
    int *crm;
    switch(opcao)
    {
    case 1:
        system("cls");
        listarConsulta(crm);
        espera_limpa();
        break;
    case 2:
        system("cls");
        listarConsultaDia(crm);
        espera_limpa();
        break;
    case 3:
        system("cls");
        cout << "Tchau !!!";
        espera_limpa();
        break;
    }

    return 0;
}
