#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "struct.h"
#include <string.h>

using namespace std;

void listarConsultaDia();
void espera_limpa();
void relatorioMedico();
void escolhasPacientes();


//Listar medicos por dia

void listarConsultaDia()
{
    fstream arq_medico;
    fstream arq_consulta;
    clinica m,c;
    int i=0;
    int tot_med=0;

    //Conta os registros do arquivo medico
    arq_medico.open("medicos.txt",ios::in);
    arq_medico.read((char *)(&m),sizeof(clinica));
    while(arq_medico && !arq_medico.eof())
    {
        arq_medico.read((char *)(&m),sizeof(clinica));
        tot_med++;
    }
    arq_medico.close();

    //Criar um vetor dinamico
    clinica vet[tot_med];

    //Carregar do arquivo para o vetor do tipo CLINICA
    arq_medico.open("medicos.txt",ios::in);
    arq_medico.read((char *)(&m),sizeof(clinica));
    while(arq_medico && !arq_medico.eof())
    {
        vet[i]=m;
        i++;
        arq_medico.read((char *)(&m),sizeof(clinica));
    }
    arq_medico.close();

    //Compara a o vetor com os dados do arquivo consulta
    i=0;
    arq_consulta.open("consultas.txt",ios::in);
    arq_consulta.read((char *)(&c),sizeof(clinica));
    while(arq_consulta && !arq_consulta.eof())
    {
        if(vet[i].crm == c.crm)
        {
            cout<<"Medicos: "<<vet[i].crm<<endl;
            cout<<"    Consulta: "<<c.crm<<endl<<endl;
        }
        i++;
        arq_consulta.read((char *)(&c),sizeof(clinica));
    }
    arq_consulta.close();
}
void espera_limpa()
{
    cout<<endl<<endl;
    system("pause");
    system("cls");
}

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
        cout << "\nDescricao: " << descricao.observacoes;
    }
    relatorio.close();
}


//pacientes do dia

void CadsClientes();
void listarClientes();
void atualizarcliente();
void deletarcliente();
void pesquisaCliente();


void escolhasPacientes()
{
    int operacao;
    while(true){
        cout <<"\n\t\t\t=========================="<<endl;
        cout <<"\t\t\t|     MODULO CLIENTE     |"<<endl;
        cout <<"\t\t\t=========================="<<endl<<endl;
        cout <<" 1 - Cadastra Cliente\n";
        cout <<" 2 - Listar Todos os Clientes\n";
        cout <<" 3 - Pesquisar Clientes por CPF\n";
        cout <<" 4 - Renomear Cadastro de Cliente\n";
        cout <<" 5 - Deletar Cadastro de Cliente\n";
        cout <<" 6 - Sair do Sistema\n\n";
        cout <<"Opcão:";
        cin >> operacao;

        switch (operacao){
            case 1:
                system("cls");
                CadsClientes();
                break;
            case 2:
                system("cls");
                listarClientes();
                break;
            case 3:
                system("cls");
                pesquisaCliente();
                break;
            case 4:
                atualizarcliente();
                break;
            case 5:
                deletarcliente();
                break;
            case 6:
                cout <<"\n\t\t\t=================================="<<endl;
                cout <<"\t\t\t| Sair do Sistema - Volte Sempre |"<<endl;
                cout <<"\t\t\t=================================="<<endl;
                exit(0);
                break;
            default:
                cout <<"\n\t\t\Você informou um opção incorreta. Por favor tente novamente\n"<<endl;
                system ("pause");
                break;
        }
        system("cls");
    }
}


void CadsClientes(){
    ofstream registropessoal("dadosclientes.txt", ios::app | ios::binary);
	clinica pessoal;

	cout <<"\n\t\tPreencha Corretamente os dados do Cliente\n\n";
    pessoal.cod = 1;
	cout <<"Informe o Nome:";
	cin.ignore();
    cin.getline(pessoal.nome,50);
        for(int i = 0; i<=50; i++){
                pessoal.nome[i]=toupper(pessoal.nome[i]);
        }

    cout <<"Informe o Idade do Cliente:";
	cin >> pessoal.idade;
	cin.ignore();

	cout <<"Informe o CPF:";
	cin.getline(pessoal.cpf,15);

	cout <<"Informe o RG:";
	cin.getline(pessoal.rg,15);

	cout <<"Informe Cidade:";
	cin.getline(pessoal.cidade,25);

    for(int j = 0; j<=30; j++){
                pessoal.cidade[j]=toupper(pessoal.cidade[j]);
        }

    cout <<"Informe o Endereço:";
	cin.getline(pessoal.endereco,25);
        for(int j = 0; j<=50; j++){
                pessoal.endereco[j]=toupper(pessoal.endereco[j]);
        }

	registropessoal.write((char*)&pessoal,sizeof(clinica));
    registropessoal.close();
}

void listarClientes(){

	ifstream lerrcliente("dadosclientes.txt", ios::in | ios::binary);
    clinica pessoal;

	cout <<"\n\t\t\t========================"<<endl;
	cout <<"\t\t\t|     CLIENTES ATIVOS     |"<<endl;
	cout <<"\t\t\t========================"<<endl<<endl;
        if(lerrcliente.fail()){
             cout<<"\n\n\t\t\tOps! Não existe Arquivo.\n\n"<<endl;
             system("PAUSE");
             return;
             }
	lerrcliente.read((char*)&pessoal,sizeof(clinica));
    while (!lerrcliente.eof()) {

    	if(pessoal.cod == 1){
            cout<<"Nome do Cliente:";
            cout<<pessoal.nome<<endl;
            cout<<"Idade do Cliente:";
            cout<<pessoal.idade<<endl;
            cout<<"CPF:";
            cout<<pessoal.cpf<<endl;
            cout<<"RG:";
            cout<<pessoal.rg<<endl;
            cout<<"Cidade:";
            cout<<pessoal.cidade<<endl;
            cout<<"Endereço:";
            cout<<pessoal.endereco<<endl<<endl;
	    }

		lerrcliente.read((char*)&pessoal,sizeof(clinica));
	}

    system("PAUSE");
    lerrcliente.close();
}

void atualizarcliente(){
     ofstream registropessoal("dadosclientes.txt",  ios::binary | ios::in | ios::out | ios::ate);
     clinica pessoal;

         if(registropessoal.fail())
            {
                 cout<<"\n\n\t\tOps! Não existe Arquivo.\n\n"<<endl;
                 system("PAUSE");
                 return;
            }

	 int psc2;

     cout <<"Posição do Cadastro do Cliente:";
     cin >>psc2;

     registropessoal.seekp((psc2-1)*sizeof(clinica));

	 cout <<"\n\t\tPreencha Corretamente os dados do Cliente\n\n";
    pessoal.cod = 1;
	cout <<"Informe o Nome:";
	cin.ignore();
    cin.getline(pessoal.nome,50);
        for(int i = 0; i<=50; i++){
                pessoal.nome[i]=toupper(pessoal.nome[i]);
        }

    cout <<"Informe o Idade do Cliente:";
	cin >> pessoal.idade;
	cin.ignore();

	cout <<"Informe o CPF:";
	cin.getline(pessoal.cpf,15);

	cout <<"Informe o RG:";
	cin.getline(pessoal.rg,15);

	cout <<"Informe Cidade:";
	cin.getline(pessoal.cidade,25);

    for(int j = 0; j<=30; j++){
                pessoal.cidade[j]=toupper(pessoal.cidade[j]);
        }

    cout <<"Informe o Endereço:";
	cin.getline(pessoal.endereco,25);
        for(int j = 0; j<=50; j++){
                pessoal.endereco[j]=toupper(pessoal.endereco[j]);
        }

	 registropessoal.write((char*)&pessoal,sizeof(clinica));
     registropessoal.close();
}

void deletarcliente(){
     ofstream registropessoal("dadosclientes.txt",  ios::binary | ios::in | ios::out | ios::ate);
	 clinica pessoal;
	 int psc2;

         if(registropessoal.fail())
            {
                 cout<<"\n\n\t\tOps! Não existe Arquivo.\n\n"<<endl;
                 system("PAUSE");
                 return;
            }

         cout <<"Posição do Cadastro do Cliente:";
         cin >>psc2;

     registropessoal.seekp((psc2-1)*sizeof(clinica));

	 pessoal.cod = 0;

        cout <<"\n\t\t\t=================================="<<endl;
        cout <<"\t\t\t|  Cliente Deletado com sucesso  |"<<endl;
        cout <<"\t\t\t=================================="<<endl;

	 registropessoal.write((char*)&pessoal,sizeof(clinica));
     registropessoal.close();
     system ("pause");
}

void pesquisaCliente(){

    char CPF[15];
    int achou = 0;
    ifstream lerrcliente("dadosclientes.txt", ios::in | ios::binary);
    clinica pessoal;

       if(lerrcliente.fail())
        {
            cout<<"\n\n\t\tOps! Não existe Arquivo.\n\n"<<endl;
            system("PAUSE");
            return;
        }

    cout<<"\n\nEntre com o CPF do Clinte a ser pesquisado: ";
    cin>>CPF;

    lerrcliente.read((char*)&pessoal,sizeof(clinica));
    while (!lerrcliente.eof())
        {
    	if ((strcmp(CPF,pessoal.cpf)== 0)&& (pessoal.cod == 1)){
            achou = 1;
            cout<<"\n\nNome do Cliente:";
            cout<<pessoal.nome<<endl;
            cout<<"Idade do Cliente:";
            cout<<pessoal.idade<<endl;
            cout<<"CPF:";
            cout<<pessoal.cpf<<endl;
            cout<<"RG:";
            cout<<pessoal.rg<<endl;
            cout<<"Cidade:";
            cout<<pessoal.cidade<<endl;
            cout<<"Endereço:";
            cout<<pessoal.endereco<<endl<<endl;
	    }

		lerrcliente.read((char*)&pessoal,sizeof(clinica));
	}
	 if(achou == 0)
        {
        cout<<"\n\n\t\tOps! CPF não cadastrado.\n\n"<<endl;
        }
    system("PAUSE");
    lerrcliente.close();
}

