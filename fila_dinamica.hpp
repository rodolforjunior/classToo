typedef struct registro
{
    string name;
    int idade;
    string date;
    int type;
    int userType;

} Registro;

typedef struct no
{
    Registro reg;
    no *prox;
} No;

typedef struct fila
{
    No *frente;
    No *re;
} Fila;

/// fun��es: initQ, enqueue, dequeue, showQ,  resetQ, peekQ

void initQ(Fila *f)
{
    f->frente = NULL;
    f->re = NULL;
}

bool enqueue(Fila *f, Registro reg)
{
    No *novo = new No();
    if (novo == NULL) /// n�o conseguiu alocar mem�ria
        return false;
    novo->reg = reg;
    novo->prox = NULL;
    if (f->frente == NULL)/// fila estava vazia
        f->frente = novo;
    else
        f->re->prox = novo;
    f->re = novo;
    return true;
}


bool dequeue(Fila *f, Registro *reg = NULL)
{
    if (f->frente == NULL)
        return false;
    if (reg != NULL)
        *reg = f->frente->reg;
    No *apagar = f->frente;
    f->frente = f->frente->prox; /// atualiza a frente da fila
    delete(apagar); /// apagar elemento
    if (f->frente == NULL)
        f->re = NULL;
    return true;
}

void showQ(Fila *f)/// mostrar a fila
{
    No *nodo = f->frente;
    while(nodo != NULL)
    {
        cout <<"Nome: " << nodo->reg.name << endl;
        cout <<"Idade: " << nodo->reg.idade << endl;
        cout <<"Data para vacinacao: " << nodo->reg.date << endl;
        cout <<"Tipo de vacina: ";
        if(nodo->reg.type == 1)
        {
            cout <<"CoronaVac" << endl;
        }
        else
        {
            cout <<"AstraZeneca" << endl;
        }
        cout <<"------------------------------------" << endl;
        nodo = nodo->prox;
    }
    cout << "\n";
}


No *peekQ(Fila *f)
{
    No *nodo = f->frente;
    return nodo;
}

void resetQ(Fila *f) ///excluir todos os nodos da fila - liberar mem�ria
{
    No *nodo = f->frente;
    while (nodo != NULL)
    {
        No *apagar = nodo;
        nodo = nodo->prox;
        delete(apagar);
    }
    f->frente = NULL;
    f->re = NULL;
}

bool isEmptyQ(Fila *f)
{
    if (f->frente == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool checkQueues(Fila *f, Fila *f2)
{
    if (f->frente == NULL and f2->frente == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void listQueue(Fila *f)
{
    No *nodo = f->frente;
    int x = 0;
    while(nodo != NULL)
    {
        x++;
        cout <<"Nome: " << nodo->reg.name << endl;
        nodo = nodo->prox;

    }
    cout <<"Total de pessoas na fila: " << x;
}




