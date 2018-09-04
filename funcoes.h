void listarConsulta(int *crm);
void listarConsultaDia(int *crm);
void espera_limpa();
void menu();


void menu()
{
    textbackground(COR_FUNDO);
    clrscr();
    textcolor(BLACK);
    logo();
    barraNotificacao();
    int opcao;
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
            system("cls");
            break;
        default:
            gotoxy(38,22);
            textcolor(RED);
            cout << "OPCAO INVALIDA !!";
            break;
    }

    system("pause");
}





//Listar consultas

void listarConsulta(int *crm)
{
     crm = new int;

    fstream arq_consulta;
    clinica m,c;
    int dia, mes, ano;
    char consultDataHoje[9],listaCpf[10][12],turnoPac[10],listaNome[10][40];
    dateSystem(dia, mes,ano);


    consulta buscaConsulta;
    int tot=0;
    *crm=123;
    //*crm = buscaConsulta.crm;

    //criar vetor[10] para armazenar qtd consultas do dia

    arq_consulta.open("consultas.txt",ios::in);
    arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(*crm==buscaConsulta.crm)
        {
           strcpy(listaCpf[tot],buscaConsulta.cpfCli);
           turnoPac[tot]=buscaConsulta.turno;
           tot++;
           //cout << buscaConsulta.cpfCli << endl;
        }
        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    }
    arq_consulta.close();
    cliente buscaCliente;

    //===============================
    int j=0;


    for (j=0; j<=tot; j++)
    {
        arq_consulta.open("clientes.txt",ios::in);
        arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
        while(arq_consulta && !arq_consulta.eof())
        {
            if(strcmp(listaCpf[j],buscaCliente.cpf)==0)
                {
                    strcpy(listaNome[j],buscaCliente.nome)==0;
                }
            arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
        }
        arq_consulta.close();
    }

    if(tot==0)
        {
            cout<<"Nao ha pacientes para o dia de hoje";
            getch();
            return menu();
        }
    else{

        arq_consulta.open("clientes.txt",ios::in);
        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
        int contador = 0, y=11;
        while(arq_consulta && !arq_consulta.eof())
        {
            if(buscaCliente.ativo)
                contador ++;
             arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));

        }
        arq_consulta.close();

        int numLinhas;

        numLinhas = contador*6;
        if(numLinhas%30 != 0)
            numLinhas = numLinhas + (30 - (numLinhas%30));
        clrscr();

        criaMenu(numLinhas,100,1,1,COR_FUNDO,COR_LETRA2);
        criaMenu(numLinhas,80,11,8,COR_LOGO,COR_LETRA2);
        criaMenu(5,100,1,1,COR_LOGO,COR_LETRA2);
        gotoxy(42,3);
        cout << "CONSULTAS";

        sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);
        gotoxy(80,3);
        cout << "DATA DE HOJE: " << consultDataHoje;

        for(int i=0; i<=tot; i ++)
        {
            arq_consulta.open("consultas.txt",ios::in);
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            while(arq_consulta && !arq_consulta.eof())
            {

                if(strcmp(listaCpf[i],buscaConsulta.cpfCli)==0)
                {
                    gotoxy(15,y++);
                    cout << "CRM.: " << buscaConsulta.crm << endl;
                    gotoxy(15,y++);
                    if (turnoPac[i] == 0)
                        cout << "Turno: Manha" << endl;
                    else
                        cout << "Turno: Tarde " << endl;
                    gotoxy(15,y++);
                    cout << "NOME: "<< listaNome[i]<< endl;
                    gotoxy(15,y++);
                    cout << "CPF.: "<< buscaConsulta.cpfCli << endl;
                    gotoxy(15,y++);
                    cout << "Data: "<<buscaConsulta.dataConsulta << endl << endl;
                    gotoxy(15,y++);
                    cout << "==================================================" << endl;
                    y++;
                    i++;
                    getch();
                    gotoxy(15,y++);
                }
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            }
            arq_consulta.close();
        }
        getch();
        menu();

    }


}



// Listar pacientes do dia
//=====================================



void listarConsultaDia(int *crm)
{
    crm = new int;

    fstream arq_consulta;
    clinica m,c;
    int dia, mes, ano;
    char consultDataHoje[9],listaCpf[10][12],turnoPac[10],listaNome[10][40];
    dateSystem(dia, mes,ano);
    textcolor(BLACK);
    cout << dia << mes << ano;
    sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);

    consulta buscaConsulta;
    int tot=0;
    *crm=123;
    //*crm = buscaConsulta.crm;

    //criar vetor[10] para armazenar qtd consultas do dia
    arq_consulta.open("consultas.txt",ios::in);
    arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(strcmp(buscaConsulta.dataConsulta,consultDataHoje)==0 && *crm==buscaConsulta.crm)
        {
           strcpy(listaCpf[tot],buscaConsulta.cpfCli);
           turnoPac[tot]=buscaConsulta.turno;
           tot++;
        }

        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    }
    arq_consulta.close();
    cliente buscaCliente;

    //===============================
    int j=0;
    arq_consulta.open("clientes.txt",ios::in);
    arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
    cout << consultDataHoje;
    cout << "PACIENTES DO DIA";
    int contador=0, y=11;
    for (j=0; j<tot; j++)
    {
        while(arq_consulta && !arq_consulta.eof())
        {
            if(strcmp(listaCpf[j],buscaCliente.cpf)==0)
                strcpy(listaNome[j],buscaCliente.nome);

            arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
        }
    }
    arq_consulta.close();

    int numLinhas;

    numLinhas = contador*6;
    if(numLinhas%30 != 0)
        numLinhas = numLinhas + (30 - (numLinhas%30));
    clrscr();

    criaMenu(numLinhas,100,1,1,COR_FUNDO,COR_LETRA2);
    criaMenu(numLinhas,80,11,8,COR_LOGO,COR_LETRA2);
    criaMenu(5,100,1,1,COR_LOGO,COR_LETRA2);
    gotoxy(42,3);
    cout << "PACIENTES DO DIA";

	sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    gotoxy(80,3);
    cout << "DATA DE HOJE: " << consultDataHoje;

    if(tot==0)
    {
        gotoxy(35,6);
        cout<<"Nao ha pacientes para o dia de hoje !!!";
    }

    else{
        arq_consulta.open("consultas.txt",ios::in);
        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
        for(int i=0; i<tot; i ++)
        {
            while(arq_consulta && !arq_consulta.eof())
            {
                if(strcmp(listaCpf[i],buscaConsulta.cpfCli)==0)
                {
                    gotoxy(15,y++);
                    cout<<"CRM: " << buscaConsulta.crm << endl;
                    gotoxy(15,y++);
                    if (turnoPac[i] == 0)
                        cout << "Turno: Manha" << endl;
                    else
                        cout << "Turno: Tarde " << endl;
                    gotoxy(15,y++);
                    cout << "NOME: "<< buscaCliente.nome<< endl;
                    gotoxy(15,y++);
                    cout << "CPF: "<< buscaConsulta.cpfCli << endl;
                    gotoxy(15,y++);
                    cout<<"Data: "<< buscaConsulta.dataConsulta << endl;
                    gotoxy(15,y++);
                    cout<<"=========================================";
                    y++;
                    i++;
                }
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            }
        }

      arq_consulta.close();
    }

    //parte do relatorio
    char opcao;

    cout << "\nDeseja mostrar relatorio ? (S/N): " << endl;
    cin >> opcao;

    if(opcao == 's' || opcao == 'S')
    {
        system("cls");
        cout << "\t\t\t\n\n ATENDIMENTO" << endl;
        int i,valida=0;
        char cpfProcura[12];
        do{

              cout << "CPF: "  << endl;
              fflush(stdin);
              cin.getline(cpfProcura,12);
              for( i =0; i<tot; i++ )
              {
                  if(strcmp(cpfProcura,listaCpf[i])==0)
                  {
                      valida = 1;
                      break;
                  }
              }
              if (valida==0)
                cout<<"inexistente";
              }while(valida==0);
          cout << "Paciente selecionado: " << endl;

            arq_consulta.open("consultas.txt",ios::in);
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
                while(arq_consulta && !arq_consulta.eof())
                {
                    if(strcmp(cpfProcura,buscaConsulta.cpfCli)==0)
                    {
                        if (turnoPac[i] == 0)
                            cout << "Turno: Manha" << endl;
                        else
                            cout << "Turno: Tarde " << endl;
                        int k;
                        for(k=0; k<tot; k++){
                            if(strcmp(cpfProcura,listaCpf[i])==0)
                                break;
                        }
                        cout << "NOME: "<< listaNome[k]<< endl;
                        cout << "CPF: "<< buscaConsulta.cpfCli << endl;
                        cout<<"Data: "<<buscaConsulta.dataConsulta << endl << endl;
                        cout<<"\n=========================================\n";
                        i++;
                    }
                arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
                }
                arq_consulta.close();

                relatorio insereDado;
                strcpy(insereDado.cpf,cpfProcura);
                insereDado.crm = *crm;
                strcpy(insereDado.dataConsulta,consultDataHoje);
                cout << "Sintomas do paciente: " << endl;
                cin.getline(insereDado.sintomas,50);
                cout << "Observacao: " << endl;
                cin.getline(insereDado.observacoes,50);
                cout << "Conclusao: " << endl;
                cin.getline(insereDado.conclusao,50);

                ofstream insereRelatorio;
                insereRelatorio.open ("relatorio.txt",ios::in | ios::app);
                    insereRelatorio.write((const char*)(&insereRelatorio),sizeof(relatorio));
                    insereRelatorio.close();


                cout << "Retornando ao menu inicial !!" << endl;
                getch();
                return menu();
    }
    else
        system("cls");
        return menu();

}



//função para apenas limpar tela
//======================================================


void espera_limpa()
{
    // cout<<endl<<endl;
    system("pause");
    system("cls");
}



