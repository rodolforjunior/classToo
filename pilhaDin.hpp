
typedef struct pilha
{
    No *topo;
} Pilha;

void initPilha(Pilha *p)
{
    p->topo = NULL; ///pilha vazia /// (*p).topo
}

bool isEmpty(Pilha *p) /// verifica se a pilha está vazia
{
    if (p->topo == NULL)
        return true;
    else
        return false;
}

bool push(Pilha *p, Registro registro) /// empilhar
{
    No *novo =  new No();
    if (!novo) /// sistema n�o conseguiu alocar a mem�ria
        return false;
    novo->reg = registro;
    novo->prox = p->topo;
    p->topo = novo;
    return true;
}

bool pop (Pilha *p, Registro *reg) /// desempilhar
{
    if (isEmpty(p))
        return false;
    *reg = p->topo->reg; ///(*p).(*topo).reg
    No *apagar = p->topo;
    p->topo = p->topo->prox;
    delete apagar;  /// libera a mem�ria
    return true;
}

void show(Pilha *p)
{
    No *no = p->topo;
    cout << "A pilha contendo os VACINADOS do IFSUL PF: " << endl;
    int x = -1;
    while (no != NULL)
    {
        x++;
        cout <<"Nome: " << no->reg.name << endl;
        cout <<"Idade: " << no->reg.idade << endl;
        cout <<"Data de vacinacao: " << no->reg.date << endl;
        cout <<"Classificacao do usuario: ";
        if (no->reg.userType == 1)
        {
            cout <<"Estudante";
        }
        else
        {
            cout <<"Servidor";
        }
        cout << endl;
        cout <<"Tipo da vacina: ";
        if (no->reg.type == 1)
        {
            cout <<"CoronaVac";
        }
        else
        {
            cout <<"AstraZeneca";
        }
        cout << endl;
        cout << "-----------------------------------------" <<endl;
        no = no->prox;

    }
    cout << endl;
}

bool peek(Pilha* p, Registro *reg)
{
    if (p->topo != NULL)
    {
        *reg= p->topo->reg;
        return true;
    }
    else
        return false;
}

void checkVaccinated (Pilha *p)
{
    No *no = p->topo;
    cout <<"As pessoas vacinadas sao: " << endl;
    int x = 0;
    while (no != NULL)
    {
        x++;
        cout <<"Nome: " << no->reg.name << endl;

        no = no->prox;
        cout << endl;

    }
    cout <<"Total de vacinados: " << x <<" pessoas." << endl;
    cout << endl;
}
void listServidores (Pilha *p)
{
    No *no = p->topo;
    int x = 0,flag=-1;
    while (no != NULL)
    {

        if (no->reg.userType == 2)
        {
            if (flag == -1)
            {
                cout <<"Os SERVIDORES vacinados sao: " << endl;
                flag++;
            }
            cout <<"Nome: " << no->reg.name << endl;
            x++;

        }
        no = no->prox;

    }
    if (flag == -1)
    {
        cout <<"Existem somente ESTUDANTES vacinados na pilha." << endl;
    }
    else
    {
        cout <<"Total de vacinados: " << x <<" pessoas." << endl;
        cout << endl;
    }
}
void listEstudantes (Pilha *p)
{
    No *no = p->topo;
    int x = 0,flag=-1;
    while (no != NULL)
    {

        if (no->reg.userType == 1)
        {
            if (flag == -1)
            {
                cout <<"Os ESTUDANTES vacinados sao: " << endl;
                flag++;
            }
            cout <<"Nome: " << no->reg.name << endl;
            x++;

        }
        no = no->prox;


    }
    if (flag == -1)
    {
        cout <<"Só existem SERVIDORES vacinados na pilha." << endl;
    }
    else
    {
        cout <<"Total de vacinados: " << x <<" pessoas." << endl;
        cout << endl;
    }
}

void calcMedia (Pilha *p)
{
    No *no = p->topo;
    double valor= 0;
    cout <<"A media de idade das pessoas vacinadas e: " << endl;
    int x = 0;
    while (no != NULL)
    {
        x++;
        valor = no->reg.idade+valor;
        no = no->prox;

    }
    valor = valor / x;
    cout <<"A media de idade dos VACINADOS E: " << valor <<" anos.";
    cout << endl;
}

void showType (Pilha *p)
{
    No *no = p->topo;
    int cv = 0, az =0;
    cout <<"O total de vacinados por tipo de vacina e: " << endl;
    while (no != NULL)
    {

        if (no->reg.type == 1)
        {
            cv++;
        }
        else
        {
            az++;
        }
        no = no->prox;

    }

    cout <<"CoronaVac total de: " << cv <<" vacinados." << endl;
    cout <<"AstraZeneca total de: " << az <<" vacinados. " << endl;
}

