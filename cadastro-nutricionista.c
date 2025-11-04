#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define TAM 2

struct cadastro
{
    int idade;
    float peso, altura;
    char nome[50], sobrenome[50];
};

typedef struct cadastro cadastro;

float calculo_imc(float altura, float peso)
{

    return peso / (altura * altura);

}

void resultados(cadastro lista[TAM])
{

    printf("Resultado das consultas: \n");
    for(int i = 0; i < TAM; i++)
    {

        printf("Nome do paciente N%dº: %s %s\n", i+1, lista[i].nome, lista[i].sobrenome);
        printf("Idade do paciente: %d\n", lista[i].idade);
        printf("IMC do paciente: %.2f\n", calculo_imc(lista[i].altura, lista[i].peso));

    }

}

void menu()
{

    setlocale(LC_ALL, "portuguese");

    cadastro lista[TAM];

    for(int i = 0; i < TAM; i++)
    {

        printf("Seja Bem vindo ao Nutricionista digital!\n");

        printf("(cadastro N%dº) Para começarmos, digite seu nome: ", i+1);
        scanf("%s", lista[i].nome);
        system("cls");

        printf("Prazer %s!, agora digite seu sobrenome: ", &lista[i].nome);
        scanf("%49s", lista[i].sobrenome);
        system("cls");

        printf("Digite sua idade: ");
        scanf("%d", &lista[i].idade);
        system("cls");

        printf("Digite sua altura atual (Utilizar Virgula): ");
        scanf("%f", &lista[i].altura);
        system("cls");

        printf("Digite seu peso atual (Utilizar Virgula): ");
        scanf("%f", &lista[i].peso);
        system("cls");

        float IMC = calculo_imc(lista[i].altura, lista[i].peso);


    }

    resultados(lista);

}

int main()
{
    menu();
}