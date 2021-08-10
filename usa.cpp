#include <iostream>
#include <stdio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <ctype.h>

using namespace std;

#include "fila_dinamica.hpp"
#include "pilhaDin.hpp"
int main()
{
    setlocale(LC_ALL,"Portuguese");
    Fila filaEst, filaServ;
    ofstream file;
    ifstream read;
    Pilha vacinados;
    initQ(&filaEst);
    initQ(&filaServ);
    initPilha(&vacinados);
    Registro reg;

    int escolha = -1;

    while (escolha != 0)
    {
        cout <<"-----------------------------------------------------" << endl;
        cout <<"MENU" <<endl;
        cout <<"Digite a opção desejada: " << endl;
        cout <<"[1] - Cadastrar SERVIDOR ou ALUNO na fila" << endl;
        cout <<"[2] - Mostrar fila ESTUDANTES" << endl;
        cout <<"[3] - Mostrar fila SERVIDORES" << endl;
        cout <<"[4] - VACINAR " << endl;
        cout <<"[5] - Mostrar pilha dos VACINADOS " << endl;
        cout <<"[6] - Listar pessoas da fila ESTUDANTES " << endl;
        cout <<"[7] - Listar pessoas da fila SERVIDORES " << endl;
        cout <<"[8] - Listar todas as pessoas VACINADAS " << endl;
        cout <<"[9] - Listar todas os SERVIDORES vacinados " << endl;
        cout <<"[10] - Listar todos os ESTUDANTES vacinados " << endl;
        cout <<"[11] - Calcular média de IDADE das pessoas VACINADAS " << endl;
        cout <<"[12] - Mostrar número de vacinados por TIPO DE VACINA" << endl;
        cout <<"[13] - Mostrar arquivo texto" << endl;
        cout <<"0 - SAIR " << endl;
        cout <<"-----------------------------------------------------" << endl;
        cin >> escolha;
        while (escolha < 0 or escolha > 13)
        {
            cout <<"Você não selecionou nenhuma das opções do menu. Digite sua escolha novamente: " << endl;
            cin >> escolha;
        }
        fflush(stdin);
        system("cls");

        if (escolha == 1)
        {
            cout <<"Digite a categoria do cadastrado: " << endl;
            cout <<" [1] - ESTUDANTE" << endl;
            cout <<" [2] - SERVIDOR" << endl;
            cout <<"Sua escolha (1 ou 2): ";
            cin >> reg.userType;
            fflush(stdin);

            while (!(reg.userType == 1 or reg.userType == 2)) ///testa se o tipo do usuário (servidor ou estudante está correto
            {
                cout <<"Sua entrada está incorreta. Informe novamente seguindo os campos abaixo: " << endl;
                cout <<"[1] - ESTUDANTE" << endl;
                cout <<"[2] - SERVIDOR" << endl;

                cout <<"Sua escolha (1 ou 2)";
                cin >> reg.userType;
                system("cls");
                fflush(stdin);
            }
            if (reg.userType == 1) ///se o tipo do usuário selecionado for estudante
            {
                cout <<"Digite o nome do estudante: ";
                getline(cin,reg.name);
                fflush(stdin);

                cout <<"Digite a idade do estudante: ";
                cin >> reg.idade;
                fflush(stdin);

                cout <<"Informe a data agendada para vacinação (formato 00/00/00): ";
                getline(cin,reg.date);
                fflush(stdin);

                cout <<"Digite o tipo da vacina de acordo com a especificação abaixo: " << endl;
                cout <<"[1] - CoronaVac ou ";
                cout <<"[2] - AstraZeneca  " << endl;

                cout <<"Sua escolha: ";
                cin >> reg.type;
                fflush(stdin);

                while (!(reg.type == 1 or reg.type == 2)) ///se o tipo de vacina for incorreto, não deixará o usuário continuar até informar os dados corretos
                {
                    cout <<"Sua entrada está incorreta. Informe novamente seguindo os campos abaixo: " << endl;
                    cout <<"[1] - CoronaVac ou ";
                    cout <<"[2] - AstraZeneca  " << endl;
                    cout <<"Sua escolha: ";

                    cin >> reg.type;
                    fflush(stdin);
                    system("cls");
                }
                enqueue(&filaEst,reg);
            }
            else ///se for servidor
            {
                cout <<"Digite o nome do servidor: ";
                getline(cin,reg.name);
                fflush(stdin);

                cout <<"Digite a idade do servidor: ";
                cin >> reg.idade;
                fflush(stdin);

                cout <<"Informe a data agendada para vacinação (formato 00/00/00): ";
                getline(cin,reg.date);
                fflush(stdin);

                cout <<"Digite o tipo da vacina de acordo com a especificação abaixo: " << endl;
                cout <<"[1] - CoronaVac ou ";
                cout <<"[2] - AstraZeneca  " << endl;

                cout <<"Sua escolha: ";
                cin >> reg.type;
                fflush(stdin);

                while (!(reg.type == 1 or reg.type == 2)) ///se o tipo de vacina for incorreto, não deixará o usuário continuar até informar os dados corretos
                {
                    cout <<"Sua entrada está incorreta. Informe novamente seguindo os campos abaixo: " << endl;
                    cout <<"[1] - CoronaVac ou ";
                    cout <<"[2] - AstraZeneca  " << endl;
                    cout <<"Sua escolha: ";

                    cin >> reg.type;
                    fflush(stdin);
                    system("cls");

                }
                enqueue(&filaServ,reg);
            }

        }
        if (escolha == 2)
        {
            if(!isEmptyQ(&filaEst))
            {
                cout <<"Esses são os usuários cadastrados na fila de ESTUDANTES: " << endl;
                showQ(&filaEst);
            }
            else
            {
                cout <<"A fila de ESTUDANTES está vazia." << endl;
            }
        }
        if (escolha == 3)
        {
            if (!isEmptyQ(&filaServ))
            {
                cout <<"Esses são os usuários cadastrados na fila de SERVIDORES: " << endl;
                showQ(&filaServ);
            }
            else
            {
                cout <<"A fila de SERVIDORES está vazia" << endl;
            }
        }
        if (escolha == 4)
        {

            if (checkQueues(&filaServ, &filaEst)) ///função que verifica se as pilhas estão vazias, se estiverem não será possível fazer nenhuma operação enquanto não for adicionado usuarios...
            {
                cout <<"Não existem ou já foram retirados os cadastrados nas pilhas." << endl;

            }
            else
            {
                int choice = -1;
                cout <<"Você deseja vacinar SERVIDOR ou ESTUDANTE? " << endl;
                cout <<" [1] - ESTUDANTE" << endl;
                cout <<" [2] - SERVIDOR" << endl;
                cin >> choice;
                fflush(stdin);

                if ((choice == 1) and (!isEmptyQ(&filaServ))) ///Se a escolha for == 1 (Estudante) e a fila dos SERVIDORES NÃO estiver empty, do...
                {
                    cout <<"Não será possível vacinar o ESTUDANTE. Ainda existem SERVIDORES na fila. " << endl;
                }
                else if ((choice == 1) and (isEmptyQ(&filaServ))) ///Senão, quando a escolha for == 1 (Estudante) e a fila dos SERVIDORES estiver LIVRE, do...

                {
                    dequeue(&filaEst,&reg);
                    file.open("dados.txt",ios::app);
                    if (!file.is_open()) ///conseguiu abrir o arquivo? Se não, vai dar a mensagem de erro
                    {
                        cout <<"O sistema não conseguiu gerar o arquivo de texto para incluir os dados." << endl;
                    }
                    else ///Se não houver erros, vai escrever as informações retiradas da pilha
                    {
                        file << "Nome: " << reg.name << endl;
                        file << "Data de vacinação: " << reg.date << endl;
                        if (reg.type == 1)
                        {
                            file <<"Tipo de vacina: CoronaVac" << endl;
                        }
                        else
                        {
                            file <<"Tipo de vacina: AstraZeneca" << endl;
                        }
                        file << "Idade: " << reg.idade << endl;
                        file << "Classificação de usuário: " << reg.userType <<" = ESTUDANTE" <<endl;
                        file << "----------------------------------------------" << endl;
                        file.close();
                    }
                    push(&vacinados, reg);
                    cout <<"ESTUDANTE " <<reg.name <<" vacinado" << endl;
                    cout <<"Pressione ENTER voltar ao menu inicial";
                    cout << endl;
                    getchar();
                    system("cls");
                }
                else if ((choice == 2) and (!isEmptyQ(&filaServ))) /// Se a escolha for == 2 e a fila SERVIDORES for diferente de empty(), do...
                {
                    dequeue(&filaServ,&reg);

                    file.open("dados.txt",ios::app);
                    if (!file.is_open())
                    {
                        cout <<"O sistema não conseguiu gerar o arquivo de texto para incluir os dados." << endl;
                    }
                    else
                    {
                        file << "Nome: " << reg.name << endl;
                        file << "Data de vacinação: " << reg.date << endl;
                        if (reg.type == 1)
                        {
                            file <<"Tipo de vacina: CoronaVac" << endl;
                        }
                        else
                        {
                            file <<"Tipo de vacina: AstraZeneca" << endl;
                        }
                        file << "Idade: " << reg.idade << endl;
                        file << "Classificação de usuário: " << reg.userType <<" = ESTUDANTE" <<endl;
                        file << "----------------------------------------------" << endl;
                        file.close();
                    }
                    push(&vacinados, reg);
                    cout <<"SERVIDOR " << reg.name <<" vacinado" << endl;
                    cout <<"Pressione ENTER voltar ao menu inicial";
                    cout << endl;
                    getchar();
                    system("cls");
                }
                else if ((choice == 2) and (isEmptyQ(&filaServ))) /// se o usuário selecionar '2' para vacinar servidor,  quando a fila de estudantes for diferente de NULL e a fila de servidores estiver empty, o print será uma mensagem de erro
                {
                    cout <<"Não será possível vacinar o SERVIDOR, a fila encontra-se vazia" << endl;
                }

            }
        }
        if (escolha == 5) ///mostra vacinados na pilha
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum SERVIDOR ou ESTUDANTE e adicionados na pilha" << endl;
            }
            else
            {
                show(&vacinados);
            }
        }
        if (escolha == 6)
        {
            if (!isEmptyQ(&filaEst))
            {
                listQueue(&filaEst);
                cout <<" ESTUDANTES" << endl;
            }
            else
            {
                cout <<"Não existem cadastrados ou já foram vacinados todos presentes na fila ESTUDANTES" << endl;
            }
        }
        if (escolha == 7)
        {
            if (!isEmptyQ(&filaServ))
            {
                listQueue(&filaServ);
                cout <<" SERVIDORES" << endl;

            }
            else
            {
                cout <<"Não existem cadastrados ou já foram vacinados todos presentes na fila SERVIDORES" << endl;

            }
        }
        if (escolha == 8)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
            }
            else
            {
                checkVaccinated(&vacinados);
            }
        }
        if (escolha == 9)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
            }
            else
            {
                listServidores(&vacinados);
            }

        }
        if (escolha == 10)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;

            }
            else
            {
                listEstudantes(&vacinados);

            }
        }
        if (escolha == 11)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
            }
            else
            {
                calcMedia(&vacinados);
            }
        }

        if (escolha == 12)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
            }
            else
            {
                showType(&vacinados);
            }

        }
        if (escolha == 13)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda não foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados ao arquivo." << endl;
            }
            else
            {
                string linha;
                cout <<"Esses são os vacinados presentes no arquivo: " << endl;
                read.open("dados.txt",ios::in);
                if (read.is_open())
                {
                    while(getline(read,linha))
                    {
                        cout << linha << endl;
                    }
                }
                else
                {
                    cout <<"Houve um erro na abertura do arquivo." << endl;
                }
                read.close();
            }
        }
    }
}



