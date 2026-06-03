#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);

    string nomes[20];
    int qAlunos = 0;
    int opcao = 0;
    float notas[20][5] = {0};
    float media[20] = {0};
    int qDisciplinas = 0;

    cout << " --------- SISTEMA DE NOTAS v4.0 --------- " << endl;
    cout << "1 - Novo relatório" << endl;
    cout << "2 - Ver relatório salvo" << endl;
    cout << "3 - Ver sobre o sistema" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    switch (opcao)
    {
    case 1:
    {
        do
        {
            cout << "Digite a quantidade de alunos (1 a 20): ";
            cin >> qAlunos;
        } while (qAlunos < 1 || qAlunos > 20);

        for (int i = 0; i < qAlunos; i++)
        {
            cout << "Digite o nome do aluno " << i + 1 << ": ";
            getline(cin, nomes[i]);
        }

        do
        {
            cout << "\nDigite a quantidade de disciplinas (1 a 5): ";
            cin >> qDisciplinas;
        } while (qDisciplinas < 1 || qDisciplinas > 5);

        for (int i = 0; i < qAlunos; i++)
        {
            cout << "\nNotas de " << nomes[i] << ": " << endl;
            float soma = 0;

            for (int j = 0; j < qDisciplinas; j++)
            {
                do
                {
                    cout << "Disciplina " << j + 1 << " (0 a 10): ";
                    cin >> notas[i][j];
                } while (notas[i][j] < 0 || notas[i][j] > 10);

                soma += notas[i][j];
            }

            media[i] = soma / qDisciplinas;
        }

        cout << "\nAlunos cadastrados: " << endl;
        for (int i = 0; i < qAlunos; i++)
            cout << "  " << i + 1 << ". " << nomes[i] << endl;

        cout << "\n --------- RELATÓRIO --------- " << endl;
        int aprovados = 0, recuperacao = 0, reprovados = 0;

        for (int i = 0; i < qAlunos; i++)
        {
            cout << nomes[i] << " - Média: " << media[i] << " - ";

            if (media[i] >= 7)
            {
                cout << "Aprovado" << endl;
                aprovados++;
            }
            else if (media[i] >= 5)
            {
                cout << "Recuperação" << endl;
                recuperacao++;
            }
            else
            {
                cout << "Reprovado" << endl;
                reprovados++;
            }
        }

        cout << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados" << endl;

        ofstream arquivo("relatorio.txt");
        if (arquivo.is_open())
        {
            arquivo << "=== RELATÓRIO ===" << endl;
            for (int i = 0; i < qAlunos; i++)
            {
                arquivo << nomes[i] << " - Média: " << media[i] << " - ";
                if (media[i] >= 7)
                    arquivo << "Aprovado" << endl;
                else if (media[i] >= 5)
                    arquivo << "Recuperação" << endl;
                else
                    arquivo << "Reprovado" << endl;
            }
            arquivo << "\nResumo: " << aprovados << " aprovados, " << recuperacao << " em recuperação, " << reprovados << " reprovados." << endl;
            arquivo.close();
            cout << "\nRelatório salvo em relatorio.txt" << endl;
        }
        else
        {
            cout << "Erro ao criar arquivo." << endl;
        }
        break;
    }
    case 2:
    {
        ifstream leitura("relatorio.txt");
        if (leitura.is_open())
        {
            string linha;
            cout << "\nConteúdo do relatório salvo:" << endl;
            while (getline(leitura, linha))
                cout << linha << endl;
            leitura.close();
        }
        else
        {
            cout << "Não foi possível abrir relatorio.txt" << endl;
        }
        break;
    }
    case 3:
        cout << "3 - Ver sobre o sistema" << endl;
        cout << "--- SOBRE ---" << endl;
        cout << "Sistema de Notas v4.1" << endl;
        cout << "Desenvolvido por: Ana Julia Ledier" << endl;
        cout << "Turma: LOPAL 2026 - SENAI-SP" << endl;
        break;
    default:
        cout << "Opção inválida!" << endl;
        break;

        return 0;
    }

    return 0;
}
