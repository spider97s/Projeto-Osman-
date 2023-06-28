// Versão que declara as empresas e marcas nos menus
// https://github.com/spider97s/Projeto-Osman-
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 1000
#define MAX_MARCAS 1000

typedef struct
{
    char fabricante[40];
    char descricao[70];
    float valorVenda;
    float valorCompra;
    float lucro;
    float porcentagemLucro;
    float peso;
} Produto;
typedef struct
{
    char marca[50];
    char site[60];
    char uf[3];
    char numero[15];
} Fabricante;

Produto produtos[MAX_PRODUTOS];
Fabricante marcas[MAX_MARCAS];
int numProdutos = 0;
int numMarcas = 0;

void cadastroFabricante()
{ // Cadastro de fabricantes
    Fabricante fabricante;
    printf("Digite o nome: ");
    fgets(fabricante.marca, sizeof(fabricante.marca), stdin);
    printf("Digite o site: ");
    fgets(fabricante.site, sizeof(fabricante.site), stdin);
    printf("Digite o telefone: ");
    fgets(fabricante.numero, sizeof(fabricante.numero), stdin);
    printf("Digite a UF: ");
    fgets(fabricante.uf, sizeof(fabricante.uf), stdin);

    marcas[numMarcas] = fabricante;
    numMarcas++;
}
void cadastroProduto()
{ // Cadastro de produtos
    Produto produto;
    printf("Digite o nome do fabricante: ");
    fgets(produto.fabricante, sizeof(produto.fabricante), stdin);
    printf("Digite a descricao: ");
    fgets(produto.descricao, sizeof(produto.descricao), stdin);
    printf("Digite o peso: ");
    scanf("%f", &produto.peso);
    printf("Digite o valor de compra: ");
    scanf("%f", &produto.valorCompra);
    printf("Digite o valor de venda: ");
    scanf("%f", &produto.valorVenda);

    // calculo do Lucro

    produto.lucro = produto.valorVenda - produto.valorCompra;
    produto.porcentagemLucro = (produto.lucro / produto.valorCompra) * 100;

    produtos[numProdutos] = produto;
    numProdutos++;
}
void todasMarcas()
{ // Lista de todas as marcas
    printf("\n\n\n");
    printf("Marcas cadastradas no sistema:\n");
    for (int i = 0; i < numMarcas; i++)
    {
        printf("Marca %d:\n", i + 1);
        printf("Nome: %s", marcas[i].marca);
        printf("Site: %s", marcas[i].site);
        printf("Telefone: %s", marcas[i].numero);
        printf("UF: %s", marcas[i].uf);
        printf("\n-------------------\n");
    }
}
void todosProdutos()
{ // Lista de todos os produtos
    printf("\n\n\n");
    printf("Todos os Produtos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Descricao: %s", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: %.2f\n", produtos[i].lucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].porcentagemLucro);
        printf("Fabricante: %s", produtos[i].fabricante);
        printf("-------------------\n");
    }
}
void produtosEstados()
{ // Lista de produtos por Estado
    printf("\n\n\n");
    char uf[3];
    printf("Digite o estado (UF): ");
    fgets(uf, sizeof(uf), stdin);

    printf("\n\n");
    printf("Produtos do estado %s:\n", uf);
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(marcas[i].uf, uf) == 0)
        {
            printf("Produto %d:\n", i + 1);
            printf("Descricao: %s", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: %.2f\n", produtos[i].lucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].porcentagemLucro);
            printf("Fabricante: %s", produtos[i].fabricante);
            printf("-------------------\n");
        }
    }
}
void listaProdutosMarca()
{ // Listar produtos por marca
    printf("\n\n\n");
    char marca[50];
    printf("Digite a marca: ");
    fgets(marca, sizeof(marca), stdin);

    printf("Produtos da marca %s:\n", marca);
    for (int i = 0; i < numProdutos; i++)
    {
        if (strcmp(produtos[i].fabricante, marca) == 0)
        {
            printf("Produto %d:\n", i + 1);
            printf("Descricao: %s", produtos[i].descricao);
            printf("Peso: %.2f\n", produtos[i].peso);
            printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
            printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
            printf("Valor do lucro: %.2f\n", produtos[i].lucro);
            printf("Percentual do lucro: %.2f%%\n", produtos[i].porcentagemLucro);
            printf("Fabricante: %s", produtos[i].fabricante);
            printf("-------------------\n");
        }
    }
}
void estadoProdutoMaisCaro()
{
    printf("\n\n\n");
    float maiorValor = produtos[0].valorVenda;

    for (int i = 1; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda > maiorValor)
        {
            maiorValor = produtos[i].valorVenda;
        }
    }

    printf("Estado com o produto mais caro:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda == maiorValor)
        {
            for (int j = 0; j < numMarcas; j++)
            {
                if (strcmp(marcas[j].marca, produtos[i].fabricante) == 0)
                {
                    printf("%s\n", marcas[j].uf);
                    break;
                }
            }
        }
    }
}
void produtoMaisBarato()
{
    float menorValor = produtos[0].valorVenda;
    int indexMenorValor = 0;

    for (int i = 1; i < numProdutos; i++)
    {
        if (produtos[i].valorVenda < menorValor)
        {
            menorValor = produtos[i].valorVenda;
            indexMenorValor = i;
        }
    }

    printf("\n\n\n");
    printf("Fabricante do produto mais barato:\n");
    printf("Fabricante: %s", produtos[indexMenorValor].fabricante);
    printf("-------------------\n");
}
void ordemPorValor()
{ // ordem por valor
    for (int i = 0; i < numProdutos - 1; i++)
    {
        for (int j = 0; j < numProdutos - i - 1; j++)
        {
            if (produtos[j].valorVenda > produtos[j + 1].valorVenda)
            {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    printf("\n\n\n");
    printf("Produtos em ordem crescente de valor:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Descricao: %s", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: %.2f\n", produtos[i].lucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].porcentagemLucro);
        printf("Fabricante: %s", produtos[i].fabricante);
        printf("-------------------\n");
    }
}
void ordemPorLucro()
{ // ordernar por lucro
    for (int i = 0; i < numProdutos - 1; i++)
    {
        for (int j = 0; j < numProdutos - i - 1; j++)
        {
            if (produtos[j].lucro > produtos[j + 1].lucro)
            {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
    printf("\n\n\n");
    printf("Produtos em ordem crescente de valor do lucro:\n");
    for (int i = 0; i < numProdutos; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Descricao: %s", produtos[i].descricao);
        printf("Peso: %.2f\n", produtos[i].peso);
        printf("Valor de compra: %.2f\n", produtos[i].valorCompra);
        printf("Valor de venda: %.2f\n", produtos[i].valorVenda);
        printf("Valor do lucro: %.2f\n", produtos[i].lucro);
        printf("Percentual do lucro: %.2f%%\n", produtos[i].porcentagemLucro);
        printf("Fabricante: %s", produtos[i].fabricante);
        printf("-------------------\n");
    }
}

int main()
{
    int menu;
    do
    {
        printf("----------Menu:----------\n");
        printf("1 - Cadastrar fabricantes/marcas\n");
        printf("2 - Cadastrar produto\n");
        printf("3 - Listar todas as marcas\n");
        printf("4 - Listar todos os produtos\n");
        printf("5 - Listar os produtos de um estado\n");
        printf("6 - Listar os produtos de uma marca\n");
        printf("7 - Listar Estado do produto mais caro\n");
        printf("8 - Listar fabricante do produto mais barato\n");
        printf("9 - Listar todos os produtos em ordem crescente de valor\n");
        printf("10 - Listar todos os produtos em ordem crescente de maior 'valor do lucro'\n");
        printf("0 - Sair\n");
        printf("------------------------\n");
        printf("Escolha uma opcao: \n");
        printf("------------------------\n");
        scanf("%d", &menu);
        getchar();

        switch (menu)
        {
        case 1:
            cadastroFabricante();
            break;
        case 2:
            cadastroProduto();
            break;
        case 3:
            todasMarcas();
            break;
        case 4:
            todosProdutos();
            break;
        case 5:
            produtosEstados();
            break;
        case 6:
            listaProdutosMarca();
            break;
        case 7:
            estadoProdutoMaisCaro();
            break;
        case 8:
            produtoMaisBarato();
            break;
        case 9:
            ordemPorValor();
            break;
        case 10:
            ordemPorLucro();
            break;
        case 0:
            printf("Fechando programa. \n");
            break;
        default:
            printf("Opcao invalida\n");
        }
        printf("\n");
    } while (menu != 0);
    return 0;
}