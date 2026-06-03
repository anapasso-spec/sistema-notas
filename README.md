# 📊 Sistema de Notas v4.1

> **Status do Projeto:** Concluído 🚀

Este é um sistema robusto desenvolvido em **C++** para o gerenciamento de notas escolares. O programa oferece uma interface de terminal inteligente que permite cadastrar alunos, registrar notas de múltiplas disciplinas, calcular médias aritméticas automaticamente e exportar relatórios detalhados para arquivos externos, além de permitir a leitura de relatórios previamente salvos.

---

## 🛠️ Tecnologias e Badges

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

---

## 🚀 Funcionalidades Principais

* **💾 Persistência de Dados:** Menu inicial interativo com opção de carregar o último relatório salvo (`relatorio.txt`) ou iniciar um novo.
* **🛡️ Validação Inteligente:** Sistema blindado contra entradas inválidas (limite de 1 a 20 alunos, 1 a 5 disciplinas e notas estritamente entre 0 e 10).
* **🧮 Processamento Automático:** Cálculo dinâmico da média de cada aluno individualmente.
* **🌐 Suporte a Caracteres Especiais:** Configuração nativa via `SetConsoleOutputCP(65001)` para garantir a acentuação correta no terminal Windows (UTF-8).
* **📅 Registro de Auditoria:** Relatório exportado automaticamente com carimbo de **data e hora** exatos do fechamento das notas.
* **ℹ️ Menu Informativo:** Tela "Sobre o Sistema" integrada diretamente na interface principal do terminal.
* **📊 Estatísticas de Fechamento:** Gera um resumo final com a contagem exata de alunos aprovados, de recuperação e reprovados.

---

## 📋 Regras de Negócio (Critérios de Avaliação)

O sistema classifica automaticamente o estudante com base na média final calculada:

| Média Final | Status | Indicador Visual |
| :--- | :--- | :---: |
| Média $\ge$ 7.0 | **Aprovado** | 🟢 |
| 5.0 $\le$ Média < 7.0 | **Recuperação** | 🟡 |
| Média < 5.0 | **Reprovado** | 🔴 |

---

## ℹ️ Sobre o Sistema

* **Versão atual:** v4.1
* **Desenvolvido por:** Ana Julia Ledier
* **Turma:** LOPAL 2026 - SENAI-SP