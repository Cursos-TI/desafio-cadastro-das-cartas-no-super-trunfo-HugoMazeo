#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main(void) {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.

    setlocale(LC_ALL, "C");

    char carta;
    int code = 1;

    int popul;
    float area;
    float PIB;
    int ptturis;
    char nome[20];
    int numero;
    char estado[20];

    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.


    printf("Bem vindo ao Cadastro de cartas do SuperTrunfo!\n Por favor, separe as seguintes informações sobre a cidade desejada:\n nome, população, area, PIB, quantidade de pontos turisticos.\n");
    
    printf("Qual carta gostaria de cadastrar primeiro?\n");
    printf("São Paulo - digite -A-\n");
    printf("Minas Gerais - digite -B-\n");
    printf("Mato Grosso - digite -C-\n");
    printf("Rio de Janeiro - digite -D-\n");

    scanf("%c",&carta);
    carta = toupper(carta);

    if (carta == 'A') 
    {
        printf("Você selecionou a carta %c, do estado de São Paulo.\n", carta);
        strcpy(estado,"São Paulo");
    }

    else if (carta == 'B') 
    {
        printf("Você selecionou a carta %c, do estado de Minas Gerais.\n",carta);
        strcpy(estado,"Minas Gerais");
    }

    else if (carta == 'C') 
    {
        printf("Você selecionou a carta %c, do estado de Mato Grosso.\n",carta);
        strcpy(estado,"Mato Grosso");
    }

    else if (carta == 'D') 
    {
        printf("Você selecionou a carta %c, do estado de Rio de Janeiro.\n",carta);
        strcpy(estado,"Rio de Janeiro");
    }

    else {
        printf("Carta inválida!\n");
        return 1;
    }

    printf("Muito bem, agora, da sua carta %c escolha um número de 1 a 4 para registrar uma cidade\n",carta);
    scanf("%d",&numero);

    printf("Ok, agora vamos registrar as informações dentro da carta %c de numero %d\n",carta, numero);
    printf("Qual o nome dessa cidade?\n");
    scanf("%s",&nome);

    printf("Qual a população de %s?\n",nome);
    scanf("%d",&popul);

    printf("E qual a area (em m²) de %s?\n",nome);
    scanf("%f",&area);

    printf("E qual o PIB de %s?\n",nome);
    scanf("%f",&PIB);

    printf("Quantos pontos turisticos tem a cidade de %s? (digite 0 se não houver nenhum)\n",nome);
    scanf("%d",&ptturis);

    printf("Perfeito, temos tudo que precisamos! suas informações ficarão salvas da seguinte maneira:\n");
    printf("A carta %c%d do estado de %s representa a cidade de %s\n",carta,numero,estado,nome);
    printf("Que tem as seguintes caracteristicas:\n");
    printf("Uma área de %.2fm²\n Com uma população de %d habitantes\n Um PIB de R$%.2f\n Com %d pontos turisticos\n",area,popul,PIB,ptturis);
    printf("Incrível! Parece uma boa cidade para se morar!");

    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
