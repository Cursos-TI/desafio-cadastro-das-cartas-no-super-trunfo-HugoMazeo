#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

typedef struct 
{
    char codigo[3];
    int popul;
    float area;
    float PIB;
    int ptturis;
    char nome [20];
    char estado [20];
    float PIBcapita;
    float denspopul;
} Carta;

int main(void) {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.

    setlocale(LC_ALL, "C");

    Carta cartas[16];
    int carta_atual = 0;

    char carta;
    int numero;

    while (1) 
    {
        if(carta_atual >= 16) 
        {
            printf("Todas as cartas foram registradas\n");
            break;
        }

        printf("Bem vindo ao Cadastro de cartas do SuperTrunfo!\n Por favor, separe as seguintes informações sobre a cidade desejada:\n nome, população, area, PIB, quantidade de pontos turisticos.\n");
    
    printf("Qual carta gostaria de cadastrar primeiro?\n");
    printf("São Paulo - digite -A-\n");
    printf("Minas Gerais - digite -B-\n");
    printf("Mato Grosso - digite -C-\n");
    printf("Rio de Janeiro - digite -D-\n");

    scanf("%c",&carta);
    carta = toupper(carta);
    while ((getchar()) != '\n');
    printf("%c\n",carta);

    if (carta < 'A' || carta > 'D') 
    {
            printf("Carta inválida!\n");
            continue;
    }

    printf("Agora escolha um número de 1 a 4 para cadastrar sua carta %c\n",carta);
    scanf("%d",&numero);
    printf("%d\n",numero);

    if (numero < 1 || numero > 4) {
            printf("Número inválido!\n");
            continue;
        }
    Carta novaCarta;
    snprintf(novaCarta.codigo, 3, "%c%d", carta, numero);

    if (carta == 'A') strcpy(novaCarta.estado, "São Paulo") ;
        else if (carta == 'B') strcpy(novaCarta.estado, "Minas Gerais");
        else if (carta == 'C') strcpy(novaCarta.estado, "Mato Grosso");
        else if (carta == 'D') strcpy(novaCarta.estado, "Rio de Janeiro");

    printf("Ok, agora vamos registrar as informações dentro da carta %s\n", novaCarta.codigo);
    printf("Qual o nome dessa cidade?\n");
    scanf("%s",&novaCarta.nome);

    printf("Qual a população de %s?\n",novaCarta.nome);
    scanf("%d",&novaCarta.popul);

    printf("E qual a area (em m²) de %s?\n",novaCarta.nome);
    scanf("%f",&novaCarta.area);

    printf("E qual o PIB de %s?\n",novaCarta.nome);
    scanf("%f",&novaCarta.PIB);

    printf("Quantos pontos turisticos tem a cidade de %s? (digite 0 se não houver nenhum)\n",novaCarta.nome);
    scanf("%d",&novaCarta.ptturis);

    printf("Perfeito, temos tudo que precisamos! suas informações ficarão salvas da seguinte maneira:\n");
    printf("A carta %s do estado de %s representa a cidade de %s\n",novaCarta.codigo, novaCarta.estado, novaCarta.nome);
    printf("Que tem as seguintes caracteristicas:\n");
    printf("Uma área de %.2fm²\n Com uma população de %d habitantes\n Um PIB de R$%.2f\n Com %d pontos turisticos\n",novaCarta.area,novaCarta.popul,novaCarta.PIB,novaCarta.ptturis);
    novaCarta.PIBcapita = novaCarta.PIB / (float)novaCarta.popul;
    printf("o PIB per capita é de R$%.2f\n",novaCarta.PIBcapita);
    novaCarta.denspopul = (float)novaCarta.popul / novaCarta.area;
    printf("A densidade populacional é de %.2f\n",novaCarta.denspopul);
    printf("Incrível! Parece uma boa cidade para se morar!\n");
    printf("Seu código para comparar essa carta é %d\n",carta_atual);

    cartas[carta_atual++] = novaCarta;

    printf("Deseja cadastrar outra carta? (s/n):");
    char resposta;
    while ((getchar()) != '\n');
    scanf("%c",&resposta);

    if(tolower(resposta) != 's')
    {
        break;
    }

    }

    printf("Essas são as cartas cadastradas no total:\n");

    for(int i = 0; i < carta_atual; i++)
    {
        Carta c = cartas[i];
        printf("Código: %s | Estado: %s | Cidade: %s | População: %d | Área: %.2f | PIB: %.2f | Pontos Turísticos: %d\n",
               c.codigo, c.estado, c.nome, c.popul, c.area, c.PIB, c.ptturis);
    }

    while (1)
    {
        printf("Deseja comparar cartas? (s/n):");
        while ((getchar()) != '\n');
        char resposta;
        scanf("%c",&resposta);

        if(tolower(resposta) != 's')
    {
        break;
    }
        printf("Ok, qual o código da primeira carta para comparar?\n");
        int compararx;
        scanf("%d",&compararx);

        printf("Ok, estaremos comparando a carta de código comparador %d com qual carta?\n");
        int comparary;
        scanf("%d",&comparary);

        printf("Deseja comparar qual propriedade?\n");
        printf("Densidade Populacional - digite A\n");
        printf("PIB per Capita - digite B\n");
        printf("Super Poder (soma de todas as propriedades) - digite C\n");
        char comparar;
        while ((getchar()) != '\n');
        scanf("%c",&comparar);
        comparar = toupper(comparar);
        if(comparar == 'A')
        {
            if (cartas[compararx].denspopul > cartas[comparary].denspopul)
        {
            printf("A cidade de %s tem uma densidade populacional menor, logo melhor para se viver!\n vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
        }
        else 
        {
            printf("A cidade de %s tem uma densidade populacional menor, logo melhor para se viver!\n vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
        }
        }
        else if(comparar == 'B')
        {
            if(cartas[compararx].PIBcapita > cartas[comparary].PIBcapita)
            {
                printf("A cidade de %s tem um PIB per capita maior, logo melhor para se viver!\n Vitória para %s!\n",cartas[compararx].nome,cartas[compararx].nome);
            }
            else
            {
                printf("A cidade de %s tem um PIB per capita maior, logo melhor para se viver!\n Vitória para %s!\n",cartas[comparary].nome,cartas[comparary].nome);
            }
        }
        else if(comparar == 'C')
        {
            float superPoder1 = (cartas[compararx].area + cartas[compararx].PIB + (float)cartas[compararx].popul) * (cartas[compararx].ptturis + 1);
            float superPoder2 = (cartas[comparary].area + cartas[comparary].PIB + (float)cartas[comparary].popul) * (cartas[comparary].ptturis + 1);
            if(superPoder1 > superPoder2)
            {
                printf("A cidade de %s tem um SuperPoder de %.2f que é maior, logo ganha no SuperTrunfo!\n Vitória para %s",cartas[compararx].nome,superPoder1,cartas[compararx].nome);
            }
            else
            {
                printf("A cidade de %s tem um SuperPoder de %.2f que é maior, logo ganha no SuperTrunfo!\n Vitória para %s",cartas[comparary].nome,superPoder2,cartas[comparary].nome);
            }
        }
        
    }


    return 0;

}
