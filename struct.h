#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED

typedef struct{
    int cod; // 0-Deletado ou Não cadastrado | 1-Cadastrado
    int senha;
    int idade;
    char nome[50];
    char cpf[15];
    char rg[15];
    char cidade[25];
    char endereco[25];
    int telefone;
    char cargo[11];
    int crm;  // Primary key {Medico}
    int idSecrt; // Primary key {Secretária}
    double taxa; // Para Médico valor da Consulta | Para Secretária valor do salário

    char especialidade[20];
    int diaConsulta[5]={0,0,0,0,0};
    int turno;// 0 - manhâ | 1  - tarde | 2 - manhã/tarde

    int numConsultaDia[3]; // Se for 0 número de consultas manhã... | 1 - número de consultas pela tarde | 2 - número de consultas manhã e tarde
    int totConsulta; // Total de consultas atendidas pelo médico
}clinica;

typedef struct{
  char nome[30]=" ";
  char cpf[12]=" ";
  char sexo[15]=" ";
  char dataNasc[10]=" ";
  char telefone[20]=" ";
  char celular[20]=" ";
  char nomePai[30]=" ";
  char nomeMae[30]=" ";
  char endRua[25]=" ";
  char endBairro[25]=" ";
  char cidade[25]=" ";
  char UF[3]=" ";
  char email[20]=" ";
  char observacoes[50]=" ";
}cliente;

#endif // STRUCT_H_INCLUDED
