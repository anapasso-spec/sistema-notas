#include <iostream>

#include <string>

#include <windows.h>

#include <fstream>

using namespace std;

int main()
{

    SetConsoleOutputCP(65001);

    // Entrada - Declaração das variáveis

    string nomes[20];

    int qAlunos;

    float notas[20][5];

    float media[20];

    int qDisciplinas;

    int opInicial;

    // Processamento

    // Leitura de alunos (Commit 1)

    cout << " --------- SISTEMA DE NOTAS v4.0 --------- " << endl;

    cout << " 1 - Novo relatório "  << endl;

    cout << " 2 - Ver relatório salvo "  << endl;

    cout << "Escolha uma opção: " << endl;

    cin >> opInicial; 

    // Leitura de arquivo (Commit 5)

    if (opInicial == 2)

    {

ifstream leitura("relatorio.txt");

if (leitura.is_open())

{

string linha;

cout << "\n";

while (getline(leitura, linha))

{

cout << linha << endl;

}

leitura.close();

}

else 

{

    cout << "Nenhum relatório encontrado. " << endl;

}

return 0;

    }
    // Notas e médias (Commit 2)

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

    // cin.ignore();

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

            } while (notas[i][j] < 0 || notas[i][j] > 10);

            soma += notas[i][j];
        }

        media[i] = soma / qDisciplinas;
    }

    // Saída

    cout << "\nAlunos cadastrados: " << endl;

    for (int i = 0; i < qAlunos; i++)

        cout << "  " << i + 1 << ". " << nomes[i] << endl;

    // Classificação e relatório (Commit 3)

    cout << "\n --------- RELATÓRIO --------- " << endl;

    int aprovados = 0, recuperacao = 0, reprovados = 0;

    for (int i = 0; i < qAlunos; i++)

    {

        cout << nomes[i] << " - Média: " << media[i] << " - " << endl;

        if (media[i] >= 7)
        {

            cout << "Aprovado " << endl;

            aprovados++;
        }

        else if (media[i] >= 5)

        {

            cout << "Recuperação " << endl;

            recuperacao++;
        }

        else

            cout
                << "Reprovado " << endl;

        reprovados++;
    }

    cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados " << endl;

    // Salvar em arquivo (Commit 4)

    ofstream arquivo("relatorio.txt");

    if (arquivo.is_open())

    {

        arquivo << "=== RELATÓRIO ===" << endl;

        for (int i = 0; i < qAlunos; i++)

        {

            arquivo << nomes[i] << " - Média: " << media[i] << " - ";

            if (media[i] >= 7)

            {

                arquivo << "Aprovado" << endl;
            }

            else if (media[i] >= 5)

            {

                arquivo << "Recuperação" << endl;
            }

            else

            {

                arquivo << "Reprovado" << endl;
            }
        }

        arquivo << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;

        arquivo.close();

        cout << "\nRelatório salvo em arquivo.txt" << endl;
    }

    else

    {

        cout << "Erro ao criar arquivo." << endl;
    }

    return 0;
}
