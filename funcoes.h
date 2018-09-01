void listarConsulta(int *crm);
void listarConsultaDia(int *crm);
void espera_limpa();
void relatorioMedico();
void escolhasPacientes();


//Listar medicos por dia

void listarConsulta(int *crm)
{
    crm = new int;
    fstream arq_consulta;
    clinica m,c;
    consulta buscaConsulta;
    int i=0;
    int tot_med=0;

    *crm=123;


    arq_consulta.open("consultas.txt",ios::in);
    arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(*crm == buscaConsulta.crm)
        {
            break;

        }
        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    }
    arq_consulta.close();
    cliente buscaCliente;

    //===============================
    arq_consulta.open("clientes.txt",ios::in);
    arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(strcmp(buscaConsulta.cpfCli,buscaCliente.cpf)==0)
        {
            break;

        }
        arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
    }
    arq_consulta.close();

    cout<<"CRM: " << buscaConsulta.crm << endl;
        if (buscaConsulta.turno == 0)
            cout << "Turno: Manha" << endl;
        else
            cout << "Turno: Tarde " << endl;
    cout << "NOME: "<< buscaCliente.nome<< endl;
    cout << "CPF: "<< buscaConsulta.cpfCli << endl;
    cout<<"Data: "<<buscaConsulta.dataConsulta << endl << endl;


}

void listarConsultaDia(int *crm)
{
    crm = new int;

    fstream arq_consulta;
    clinica m,c;
    int dia, mes, ano;
    char consultDataHoje[9],listaPacDia[12][10],turnoPac[10];
    dateSystem(dia, mes,ano);

    sprintf(consultDataHoje,"%d%s%d%s%d",dia,"/",mes,"/",ano);
    cout << "A data e: " << consultDataHoje << endl;

    consulta buscaConsulta;
    int i=0;
    *crm=123;

    //criar vetor[10] para armazenar qtd consultas
    arq_consulta.open("consultas.txt",ios::in);
    arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(strcmp(buscaConsulta.dataConsulta,consultDataHoje)==0)
        {
           strcpy(listaPacDia[i],buscaConsulta.cpfCli);
           turnoPac[i]=buscaConsulta.turno;
           i++;

        }

        arq_consulta.read((char *)(&buscaConsulta),sizeof(consulta));
    }
    arq_consulta.close();
    cliente buscaCliente;

    //===============================
    arq_consulta.open("clientes.txt",ios::in);
    arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(strcmp(buscaConsulta.dataConsulta,buscaCliente.cpf)==0)
        {
            break;

        }
        arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
    }
    arq_consulta.close();
    if(i==0)
        cout<<"Nao ha pacientes para o dia de hoje";
    //j<=i ||  j<i
    else{
        arq_consulta.open("clientes.txt",ios::in);
        arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
        while(arq_consulta && !arq_consulta.eof())
        {
            if(strcmp(listaPacDia[i],buscaCliente.cpf)==0)
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
            arq_consulta.read((char *)(&buscaCliente),sizeof(cliente));
      }
      arq_consulta.close();
    }
}


void espera_limpa()
{
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

// data do sistema



// Relatorio


void relatorioMedico()
{
    fstream relatorio;
    int i;
    cliente nome, descricao,m;
    relatorio.open("relatorio.txt",ios::in);  // in::out::ate;

    if (relatorio.fail()){
        cout<<"Erro na execução do programa. Falha no arquivo \"relatorios.txt\" \n";
        system("pause");
        return;
    }

    while(relatorio && !relatorio.eof())
    {
        relatorio.read((char *)(&m),sizeof(cliente));
        cout << "\nNome: " <<  nome.nome;
        cout << "\nDescricao: " << descricao.obs;
    }
    relatorio.close();
}


//pacientes do dia




