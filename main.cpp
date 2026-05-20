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

//Saída

cout << "\nAlunos cadastrados: " << endl;

for (int i = 0; i < qAlunos; i++)

cout << "  " << i + 1 << ". " << nomes [i] << endl;

    return 0;
    
}