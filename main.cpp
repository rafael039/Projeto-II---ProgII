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

#include "fnConsultas.h"
#include "funcoes.h"



int main()
{
    int opcao;
    textbackground(COR_FUNDO);
    clrscr();
    textcolor(BLACK);
    logo();
    barraNotificacao();
    menu();

}
