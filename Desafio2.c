#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char siglas[MAX][4];           // Siglas dos estados cadastrados
    int contadores[MAX];           // Quantidade de cartas por sigla
    char codigos[MAX][5];          // Código gerado, como "PR1"
    char nomes[MAX][50];           // Nome do estado
    char nomecidade[MAX][50];      // Nome da estado
    float area[MAX];               // Área da cidade 
    float pib[MAX];                // PIB Cidade
    float areaD[MAX];             
    float pibP[MAX]; 
    int populacao[MAX];            //População Cidade
    int turismo[MAX];              //Quantidade Pontos Turisticos
    int total_estados = 0;
    int total_cartas = 0;
    int i, j, existe, opcao; 
    char sigla[5];
    int vencedor_area = 0;
    int vencedor_pib = 0;
    int vencedor_pibP = 0;
    int vencedor_densidade = 0;  
    int vencedor_pop = 0;
    int vencedor_turismo = 0;

    do {
        printf("Sigla do estado (ex: SP): ");
        scanf("%s", sigla);

        // Verifica se o estado já foi cadastrado
        existe = 0;
        for (i = 0; i < total_estados; i++) {
            if (strcmp(siglas[i], sigla) == 0) {
                existe = 1;
                break;
            }
        }

        // Se for nova sigla, adiciona
        if (!existe) {
            strcpy(siglas[total_estados], sigla);
            contadores[total_estados] = 1;
            i = total_estados;
            total_estados++;
        } else {
            contadores[i]++;
        }

        // Gerar código como "PR1"
        sprintf(codigos[total_cartas], "%s%d", sigla, contadores[i]);

        // Ler os outros dados
        printf("Nome do estado (Sem acentos): ");
        scanf(" %[^\n]", nomes[total_cartas]);

        printf("Nome da cidade(Sem acentos): ");
        scanf(" %[^\n]", nomecidade[total_cartas]);

        printf("Área em mil km²: ");
        scanf("%f", &area[total_cartas]);

        printf("PIB em bilhões: ");
        scanf("%f", &pib[total_cartas]);

        printf("População: ");
        scanf("%d", &populacao[total_cartas]);

        printf("Pontos turísticos: ");
        scanf("%d", &turismo[total_cartas]);

         pibP[total_cartas] = pib[total_cartas] / populacao[total_cartas];
        areaD[total_cartas] = populacao[total_cartas] / area[total_cartas];

        total_cartas++;

        printf("Cadastrar outra carta? 1 para sim, 0 para não): ");
        scanf("%d", &opcao);
        printf("\n");

    } while (opcao == 1 && total_cartas < MAX);

    // Mostrar todas as cartas
    printf("\nCartas cadastradas:\n");
    for (j = 0; j < total_cartas; j++) {
        printf("Código: %s\n", codigos[j]);
        printf("Estado: %s\n", nomes[j]);
        printf("Cidade: %s\n", nomecidade[j]);
        printf("Área: %.2f mil km²\n", area[j]);
        printf("PIB: %.2f bilhões\n", pib[j]);
        printf("PIB per capita: %.2f \n", pibP[j]);
        printf("Densidade populacional: %.2f \n", areaD[j]);
        printf("População: %d\n", populacao[j]);
        printf("Pontos turísticos: %d\n", turismo[j]);
        printf("-------------------------\n");
    }

for (i = 1; i < total_cartas; i++) {
        if (area[i] > area[vencedor_area]) {
            vencedor_area = i;
        }
        if (pib[i] > pib[vencedor_pib]) {
            vencedor_pib = i;
        }
        if (pibP[i] > pibP[vencedor_pibP]) {
            vencedor_pibP = i;
        }
        if (areaD[i] < areaD[vencedor_densidade]) {
            vencedor_densidade = i;
        }
        if (populacao[i] > populacao[vencedor_pop]) {
            vencedor_pop = i;
        }
        if (turismo[i] > turismo[vencedor_turismo]) {
            vencedor_turismo = i;
        }
    }

    // Mostrar vencedores por critério
    printf("\n🏆 Vencedores por Critério 🏆\n");
    printf("Área: %s\n", codigos[vencedor_area]);
    printf("PIB: %s\n", codigos[vencedor_pib]);
    printf("PIB per capita: %s\n", codigos[vencedor_pibP]);
    printf("Densidade populacional (menor): %s\n", codigos[vencedor_densidade]);
    printf("População: %s\n", codigos[vencedor_pop]);
    printf("Pontos turísticos: %s\n", codigos[vencedor_turismo]);
    printf("-------------------------\n");

    return 0;
}



