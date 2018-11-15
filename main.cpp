/*FALTA COLOCAR OS NA MESMA MATRIZ
FAZER UM GERADOR DE TABULEIRO
00 01 02 03 04 05 06 07  8
 9 10 11 12 13 14 15 16 17
18 19 20 21 22 23 24 25 26
27 28 29 30 31 32 33 34 35
36 37 38 39 40 41 42 43 44
45 46 47 48 49 50 51 52 53
54 55 56 57 58 59 60 61 62
63 64 65 66 67 68 69 70 71
72 73 74 75 76 77 78 79 80
*/

#include <iostream>
#include <vector>

using namespace std;

void gerar_lista();
void imprimir();
int pop_numeros_possiveis(int);
int preencher_tabuleiro(int);
//void procurar();
//void push(int*, int);
int verificar(int);

int volta = 0;
int lista[81][20];
//int numeros_possiveis_inicial[81][9];
int numeros_possiveis[81][9];
int imprime = 0;

/*int tabuleiro[81] = {
        8,0,0,4,0,6,0,0,7,
        0,0,0,0,0,0,4,0,0,
        0,1,0,0,0,0,6,5,0,
        5,0,9,0,3,0,7,8,0,
        0,0,0,0,7,0,0,0,0,
        0,4,8,0,2,0,1,0,3,
        0,5,2,0,0,0,0,9,0,
        0,0,1,0,0,0,0,0,0,
        3,0,0,9,0,2,0,0,5
    };*/
/*int tabuleiro[81] = {
        0,0,7,0,0,0,0,8,0,
        0,5,0,0,0,4,0,0,1,
        1,0,0,0,0,0,4,6,0,
        4,0,0,0,9,6,0,1,0,
        0,6,0,0,1,3,0,0,2,
        8,0,0,0,2,5,0,3,0,
        6,0,0,0,0,0,7,9,0,
        0,2,0,0,0,7,0,0,4,
        0,0,8,0,0,0,0,2,0
    };*/

/*int tabuleiro[81] =
{
    6,0,0,0,0,0,2,9,5,
    7,0,0,4,9,0,6,0,0,
    2,8,0,0,5,0,0,0,0,
    0,0,0,9,2,7,0,3,0,
    0,9,2,8,0,5,7,1,0,
    0,4,0,1,6,3,0,0,0,
    0,0,0,0,3,0,0,5,9,
    0,0,3,0,7,8,0,0,2,
    4,2,8,0,0,0,0,0,7
};*/

/*int tabuleiro[81] =
{
    5,3,4,6,7,8,9,1,2,
    6,7,2,1,9,5,3,4,8,
    1,9,8,3,4,2,5,6,7,
    8,5,9,7,6,1,4,2,3,
    4,2,6,8,5,3,7,9,1,
    7,1,3,9,2,4,8,5,6,
    9,6,1,5,3,7,2,8,4,
    2,8,7,4,1,9,6,3,5,
    3,4,5,2,8,6,1,7,9
};*/

int tabuleiro[81] =
{
    5,0,4,0,7,0,9,0,2,
    6,7,2,1,9,5,3,4,8,
    1,9,8,3,4,2,5,6,7,
    8,5,9,7,6,1,4,2,3,
    4,2,6,8,5,3,7,9,1,
    7,1,3,9,2,4,8,5,6,
    9,6,1,0,0,0,2,8,4,
    2,8,7,0,0,0,6,3,5,
    0,0,0,0,0,0,0,0,0
};

int main()
{
    //lista de adjacência usada para representar o grafo
    gerar_lista();

    for(int i = 0; i < 81; i++)
    {
        if(!tabuleiro[i])
            for(int j = 0; j < 9; j++)
                numeros_possiveis[i][j] = j + 1;
        else
            numeros_possiveis[i][0] = -1;
    }

    //procurar(tabuleiro);
    //for(int i = 0; i < 20; i++)
        //cout << lista[80][i] << " ";

    /*for(int i = 0; i < 81; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cout << numeros_possiveis[i][j];
        }
        cout << endl;
    }*/

    if(preencher_tabuleiro(0))
        imprimir();

    return 0;
}

void gerar_lista()
{
    int linha = 1;
    int coluna = 1;
    int contador = 0;
    for(int i = 0; i < 81; i++)
    {
        //linha
        for(int j = i - coluna + 1; j < i + 10 - coluna; j++)
        {
            if(j != i)
                lista[i][contador++] = j;
        }
        //coluna
        for(int j = coluna - 1; j < 81; j+=9)
        {
            if(j != i)
                lista[i][contador++] = j;
        }
        //quadrante
        if(coluna == 1 || coluna == 4 || coluna == 7)
        {
            if(linha == 1 || linha == 4 || linha == 7)
            {
                lista[i][16] = i + 10;
                lista[i][17] = i + 11;
                lista[i][18] = i + 19;
                lista[i][19] = i + 20;
            }
            else if(linha == 2 || linha == 5 || linha == 8)
            {
                lista[i][16] = i - 8;
                lista[i][17] = i - 7;
                lista[i][18] = i + 10;
                lista[i][19] = i + 11;
            }
            else
            {
                lista[i][16] = i - 17;
                lista[i][17] = i - 16;
                lista[i][18] = i - 8;
                lista[i][19] = i - 7;
            }
        }
        else if(coluna == 2 || coluna == 5 || coluna == 8)
        {
            if(linha == 1 || linha == 4 || linha == 7)
            {
                lista[i][16] = i + 8;
                lista[i][17] = i + 10;
                lista[i][18] = i + 17;
                lista[i][19] = i + 19;
            }
            else if(linha == 2 || linha == 5 || linha == 8)
            {
                lista[i][16] = i - 10;
                lista[i][17] = i - 8;
                lista[i][18] = i + 8;
                lista[i][19] = i + 10;
            }
            else
            {
                lista[i][16] = i - 19;
                lista[i][17] = i - 17;
                lista[i][18] = i - 10;
                lista[i][19] = i - 8;
            }
        }
        else
        {
            if(linha == 1 || linha == 4 || linha == 7)
            {
                lista[i][16] = i + 7;
                lista[i][17] = i + 8;
                lista[i][18] = i + 16;
                lista[i][19] = i + 17;
            }
            else if(linha == 2 || linha == 5 || linha == 8)
            {
                lista[i][16] = i - 11;
                lista[i][17] = i - 10;
                lista[i][18] = i + 7;
                lista[i][19] = i + 8;
            }
            else
            {
                lista[i][16] = i - 20;
                lista[i][17] = i - 19;
                lista[i][18] = i - 11;
                lista[i][19] = i - 10;
            }
        }

        if(++coluna == 10)
        {
            coluna = 1;
            linha++;
        }
        contador = 0;
    }
}

void imprimir()
{
    for(int i = 0; i < 81; i+=9)
    {
        for(int j = 0; j < 9; j++)
        {
            if(tabuleiro[i+j])
                cout << tabuleiro[i+j] << " ";
            else
                cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int pop_numeros_possiveis(int posicao)
{
    int aux, i;
    for(i = 0; i < 9; i++)
    {
        //cout << endl << numeros_possiveis[posicao][i] << " " << endl;
        if(numeros_possiveis[posicao][i] == 0)
        {
            aux = numeros_possiveis[posicao][i-1];
            numeros_possiveis[posicao][i-1] = 0;
            return aux;
        }
    }

        //cout << "fim" << endl;
    aux = numeros_possiveis[posicao][i-1];
    numeros_possiveis[posicao][i-1] = 0;
    return aux;
}

int preencher_tabuleiro(int posicao)
{
    //++iteracoes;
    if (posicao == 81)
        return 1;
    if (posicao == -1)
    {
        //volta = 0;
        return 0;
    }
    if(numeros_possiveis[posicao][0] > -1)
    {
        //volta = 0;
        if(tabuleiro[posicao] = pop_numeros_possiveis(posicao))
        {
            if(verificar(posicao))
            {
                if (imprime)
                    imprimir();
                return preencher_tabuleiro(posicao+1);
            }
            else
            {
                if (imprime)
                    imprimir();
                //volta = 1;
                return preencher_tabuleiro(posicao);
            }
        }
        else
        {
            for(int i = 0; i < 9; i++)
                numeros_possiveis[posicao][i] = i + 1;
            tabuleiro[posicao] = 0;
            if (imprime)
                    imprimir();
            //volta = 1;
            return preencher_tabuleiro(posicao-1);
        }
    }
    else
    {
        if (imprime)
            imprimir();
        return preencher_tabuleiro(posicao+1);
    }
}

/*void procurar()
{
    for(int posicao = 0; posicao < 81; posicao++){
        if(!tabuleiro[posicao])
        {
            for(int j = 1; j <= 9; j++){
                for(int i = 0; i < 24; i++)
                {
                    if (j == tabuleiro[lista[posicao][i]])
                    {
                        break;
                    }
                    else if(i == 23){
                        push(numeros_possiveis_inicial[posicao], j);
                    }
                }
            }
        }
    }
}*/

/*void push(int* vetor, int valor)
{
    int i = 0;
    while(vetor[i] > 0)
    {
        i++;
    }
    vetor[i] = valor;
}*/

int verificar(int posicao)
{
    for(int i = 0; i < 20; i++)
    {
        if (tabuleiro[posicao] == tabuleiro[lista[posicao][i]])
        {
            return 0;
        }
    }
    return 1;
}
