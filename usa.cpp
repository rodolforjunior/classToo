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
        cout <<"Digite a op��o desejada: " << endl;
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
        cout <<"[11] - Calcular m�dia de IDADE das pessoas VACINADAS " << endl;
        cout <<"[12] - Mostrar n�mero de vacinados por TIPO DE VACINA" << endl;
        cout <<"[13] - Mostrar arquivo texto" << endl;
        cout <<"0 - SAIR " << endl;
        cout <<"-----------------------------------------------------" << endl;
        cin >> escolha;
        while (escolha < 0 or escolha > 13)
        {
            cout <<"Voc� n�o selecionou nenhuma das op��es do menu. Digite sua escolha novamente: " << endl;
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

            while (!(reg.userType == 1 or reg.userType == 2)) ///testa se o tipo do usu�rio (servidor ou estudante est� correto
            {
                cout <<"Sua entrada est� incorreta. Informe novamente seguindo os campos abaixo: " << endl;
                cout <<"[1] - ESTUDANTE" << endl;
                cout <<"[2] - SERVIDOR" << endl;

                cout <<"Sua escolha (1 ou 2)";
                cin >> reg.userType;
                system("cls");
                fflush(stdin);
            }
            if (reg.userType == 1) ///se o tipo do usu�rio selecionado for estudante
            {
                cout <<"Digite o nome do estudante: ";
                getline(cin,reg.name);
                fflush(stdin);

                cout <<"Digite a idade do estudante: ";
                cin >> reg.idade;
                fflush(stdin);

                cout <<"Informe a data agendada para vacina��o (formato 00/00/00): ";
                getline(cin,reg.date);
                fflush(stdin);

                cout <<"Digite o tipo da vacina de acordo com a especifica��o abaixo: " << endl;
                cout <<"[1] - CoronaVac ou ";
                cout <<"[2] - AstraZeneca  " << endl;

                cout <<"Sua escolha: ";
                cin >> reg.type;
                fflush(stdin);

                while (!(reg.type == 1 or reg.type == 2)) ///se o tipo de vacina for incorreto, n�o deixar� o usu�rio continuar at� informar os dados corretos
                {
                    cout <<"Sua entrada est� incorreta. Informe novamente seguindo os campos abaixo: " << endl;
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

                cout <<"Informe a data agendada para vacina��o (formato 00/00/00): ";
                getline(cin,reg.date);
                fflush(stdin);

                cout <<"Digite o tipo da vacina de acordo com a especifica��o abaixo: " << endl;
                cout <<"[1] - CoronaVac ou ";
                cout <<"[2] - AstraZeneca  " << endl;

                cout <<"Sua escolha: ";
                cin >> reg.type;
                fflush(stdin);

                while (!(reg.type == 1 or reg.type == 2)) ///se o tipo de vacina for incorreto, n�o deixar� o usu�rio continuar at� informar os dados corretos
                {
                    cout <<"Sua entrada est� incorreta. Informe novamente seguindo os campos abaixo: " << endl;
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
                cout <<"Esses s�o os usu�rios cadastrados na fila de ESTUDANTES: " << endl;
                showQ(&filaEst);
            }
            else
            {
                cout <<"A fila de ESTUDANTES est� vazia." << endl;
            }
        }
        if (escolha == 3)
        {
            if (!isEmptyQ(&filaServ))
            {
                cout <<"Esses s�o os usu�rios cadastrados na fila de SERVIDORES: " << endl;
                showQ(&filaServ);
            }
            else
            {
                cout <<"A fila de SERVIDORES est� vazia" << endl;
            }
        }
        if (escolha == 4)
        {

            if (checkQueues(&filaServ, &filaEst)) ///fun��o que verifica se as pilhas est�o vazias, se estiverem n�o ser� poss�vel fazer nenhuma opera��o enquanto n�o for adicionado usuarios...
            {
                cout <<"N�o existem ou j� foram retirados os cadastrados nas pilhas." << endl;

            }
            else
            {
                int choice = -1;
                cout <<"Voc� deseja vacinar SERVIDOR ou ESTUDANTE? " << endl;
                cout <<" [1] - ESTUDANTE" << endl;
                cout <<" [2] - SERVIDOR" << endl;
                cin >> choice;
                fflush(stdin);

                if ((choice == 1) and (!isEmptyQ(&filaServ))) ///Se a escolha for == 1 (Estudante) e a fila dos SERVIDORES N�O estiver empty, do...
                {
                    cout <<"N�o ser� poss�vel vacinar o ESTUDANTE. Ainda existem SERVIDORES na fila. " << endl;
                }
                else if ((choice == 1) and (isEmptyQ(&filaServ))) ///Sen�o, quando a escolha for == 1 (Estudante) e a fila dos SERVIDORES estiver LIVRE, do...

                {
                    dequeue(&filaEst,&reg);
                    file.open("dados.txt",ios::app);
                    if (!file.is_open()) ///conseguiu abrir o arquivo? Se n�o, vai dar a mensagem de erro
                    {
                        cout <<"O sistema n�o conseguiu gerar o arquivo de texto para incluir os dados." << endl;
                    }
                    else ///Se n�o houver erros, vai escrever as informa��es retiradas da pilha
                    {
                        file << "Nome: " << reg.name << endl;
                        file << "Data de vacina��o: " << reg.date << endl;
                        if (reg.type == 1)
                        {
                            file <<"Tipo de vacina: CoronaVac" << endl;
                        }
                        else
                        {
                            file <<"Tipo de vacina: AstraZeneca" << endl;
                        }
                        file << "Idade: " << reg.idade << endl;
                        file << "Classifica��o de usu�rio: " << reg.userType <<" = ESTUDANTE" <<endl;
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
                        cout <<"O sistema n�o conseguiu gerar o arquivo de texto para incluir os dados." << endl;
                    }
                    else
                    {
                        file << "Nome: " << reg.name << endl;
                        file << "Data de vacina��o: " << reg.date << endl;
                        if (reg.type == 1)
                        {
                            file <<"Tipo de vacina: CoronaVac" << endl;
                        }
                        else
                        {
                            file <<"Tipo de vacina: AstraZeneca" << endl;
                        }
                        file << "Idade: " << reg.idade << endl;
                        file << "Classifica��o de usu�rio: " << reg.userType <<" = ESTUDANTE" <<endl;
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
                else if ((choice == 2) and (isEmptyQ(&filaServ))) /// se o usu�rio selecionar '2' para vacinar servidor,  quando a fila de estudantes for diferente de NULL e a fila de servidores estiver empty, o print ser� uma mensagem de erro
                {
                    cout <<"N�o ser� poss�vel vacinar o SERVIDOR, a fila encontra-se vazia" << endl;
                }

            }
        }
        if (escolha == 5) ///mostra vacinados na pilha
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda n�o foram vacinados nenhum SERVIDOR ou ESTUDANTE e adicionados na pilha" << endl;
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
                cout <<"N�o existem cadastrados ou j� foram vacinados todos presentes na fila ESTUDANTES" << endl;
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
                cout <<"N�o existem cadastrados ou j� foram vacinados todos presentes na fila SERVIDORES" << endl;

            }
        }
        if (escolha == 8)
        {
            if (isEmpty(&vacinados))
            {
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
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
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
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
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;

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
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
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
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados a pilha." << endl;
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
                cout <<"Ainda n�o foram vacinados nenhum ESTUDANTE ou SERVIDOR e adicionados ao arquivo." << endl;
            }
            else
            {
                string linha;
                cout <<"Esses s�o os vacinados presentes no arquivo: " << endl;
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



