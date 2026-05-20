#include <iostream>
#include <string>
#include <windows.h>
using namespace std;


int main() 
{

SetConsoleOutputCP(65001);

//Entrada - Declaração das variáveis

string nomes[20];

int qAlunos;

float notas[20][5];

float media[20];

int qDisciplinas;

//Processamento

cout << " --------- SISTEMA DE NOTAS v4.0 --------- " << endl;

do 

{

cout << "Digite a quantidade de alunos ( sendo eles de 1 a 20 ): " << endl;

cin >> qAlunos;

} while (qAlunos < 1 || qAlunos > 20);

cin.ignore();

for (int i = 0; i < qAlunos; i++)

{
    cout << "Digite o nome do aluno " << i + 1 << ": " << endl;

    getline(cin, nomes[i]);
}

do

{

  cout << "\nDigite a quantidade de disciplinas ( 1 a 5 ): " << endl;
  
  cin >> qDisciplinas;

} while (qDisciplinas < 1 || qDisciplinas > 5);

cin.ignore();

for (int i = 0; i < qAlunos; i++)

{
cout << "\nNotas de " << nomes[i] << ": " << endl;

float soma = 0;

for (int j = 0; j < qDisciplinas; j++)

{

do 

{

cout << "Disciplina " << j + 1 << " ( 1 a 5 ): ";

cin >> notas[i][j];

} while (notas[i][j] < 0 || notas[i][j] > 10 );

soma += notas[i][j];

}

media[i] = soma / qDisciplinas;

}

//Saída

cout << "\nAlunos cadastrados: " << endl;

for (int i = 0; i < qAlunos; i++)

cout << "  " << i + 1 << ". " << nomes[i] << endl;

    return 0;

}