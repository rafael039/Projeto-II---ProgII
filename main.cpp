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
    gotoxy(40,15);
    cout << "ESCOLHA AS OPCOES" << endl << endl;
    criaMenu(5,30,34,16,COR_LETRA2,COR_LETRA1);
    gotoxy(35,16);
    cout << "[1] Exibir Consultas" << endl;
    gotoxy(35,17);
    cout << "[2] Exibir Pacientes do Dia" << endl;
    gotoxy(35,18);
    cout << "[3] Sair" << endl;

    criaMenu(2,30,34,20,COR_LOGO,COR_LETRA2);
    gotoxy(40,21);
    cout << "OPCAO ESCOLHIDA: ";
    cin >> opcao;
    gotoxy(38,20);



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
