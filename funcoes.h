void listarConsulta(int *crm);
void listarConsultaDia(int *crm);
void espera_limpa();

//Listar consultas por dia

void listarConsulta(int *crm)
{
     crm = new int;

    fstream arq_consulta;
    clinica m,c;
    int dia, mes, ano;
    char consultDataHoje[9],listaCpf[10][12],turnoPac[10],listaNome[10][40];
    dateSystem(dia, mes,ano);

    sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    cout << "A data e: " << consultDataHoje << endl;

    consulta buscaConsulta;
    int tot=0;
    *crm=444;

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
        cout<<"Nao ha pacientes para o dia de hoje";
    else{


        for(int i=0; i<=tot; i ++)
        {
              arq_consulta.open("consultas.txt",ios::in);
             arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            while(arq_consulta && !arq_consulta.eof())
            {
                if(strcmp(listaCpf[i],buscaConsulta.cpfCli)==0)
                {
                    cout<<"CRM: " << buscaConsulta.crm << endl;
                        if (turnoPac[i] == 0)
                            cout << "Turno: Manha" << endl;
                        else
                            cout << "Turno: Tarde " << endl;
                    cout << "NOME: "<< listaNome[i]<< endl;
                    cout << "CPF: "<< buscaConsulta.cpfCli << endl;
                    cout<<"Data: "<<buscaConsulta.dataConsulta << endl << endl;
                    cout<<"\n=========================================\n";
                    i++;
                }
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            }

            arq_consulta.close();
        }


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

    sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    cout << "A data e: " << consultDataHoje << endl;

    consulta buscaConsulta;
    int tot=0;
    *crm=444;

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
           //cout << buscaConsulta.cpfCli << endl;
        }

        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    }
    arq_consulta.close();
    cliente buscaCliente;

    //===============================
    int j=0;
    arq_consulta.open("clientes.txt",ios::in);
    arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
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
    if(tot==0)
        cout<<"Nao ha pacientes para o dia de hoje";
    else{
        arq_consulta.open("consultas.txt",ios::in);
        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
        for(int i=0; i<tot; i ++)
        {
            while(arq_consulta && !arq_consulta.eof())
            {
                if(strcmp(listaCpf[i],buscaConsulta.cpfCli)==0)
                {
                    cout<<"CRM: " << buscaConsulta.crm << endl;
                        if (turnoPac[i] == 0)
                            cout << "Turno: Manha" << endl;
                        else
                            cout << "Turno: Tarde " << endl;
                    cout << "NOME: "<< buscaCliente.nome<< endl;
                    cout << "CPF: "<< buscaConsulta.cpfCli << endl;
                    cout<<"Data: "<<buscaConsulta.dataConsulta << endl << endl;
                    cout<<"\n=========================================\n";
                    i++;
                }
            arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
            }
        }

      arq_consulta.close();
    }

    //parte do relatorio

    cout << "\t\t\t\n\n Atendimento" << endl;
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
}



//função para apenas limpar tela
//======================================================


void espera_limpa()
{
    cout<<endl<<endl;
    system("pause");
    system("cls");
}



