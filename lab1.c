/*Primer laboratorio del curso de ALSE
  Programa suma de dos numeros complejos
*/
#include<stdio.h>

//prototipo de funciones
void pedir_valores(float *num1_real,float *num1_imaginario, float *num2_real,float *num2_imaginario);
void definir_operacion(char *operacion);
void operar_valores(float num1_real, float num1_imaginario, float num2_real, float num2_imaginario, char operacion, float *resultado1, float *resultado2);
void mostrar_resultado(char operacion, float resultado1, float resultado2, float num2_imaginario);

int main(void)//funcion principal
{
    float num1_real, num1_imaginario, num2_real, num2_imaginario, resultado1, resultado2 = 0;
    char  operacion = 0;

    pedir_valores(&num1_real, &num1_imaginario, &num2_real, &num2_imaginario);
    definir_operacion(&operacion);
    operar_valores(num1_real, num1_imaginario, num2_real, num2_imaginario, operacion, &resultado1, &resultado2 );
    mostrar_resultado(operacion, resultado1, resultado2, num2_imaginario);

    return 1;
}
void pedir_valores(float *num1_real, float *num1_imaginario, float *num2_real, float *num2_imaginario)
{
    printf("ingrese los datos del primer numero complejo: ");
    printf("\nParte real: ");
    scanf("%f", &(*num1_real));
    printf("Parte imaginaria: ");
    scanf("%f",&(*num1_imaginario));

    printf("\nIngrese los datos para el segundo numero complejo: ");
    printf("\nParte real: ");
    scanf("%f",&(*num2_real));
    printf("Parte imaginaria: ");
    scanf("%f",&(*num2_imaginario));
}

void definir_operacion (char *operacion)
{

    printf("Digite un numero del 1-4 para realizar la operacion:");
    printf("\n1. SUMA.");
    printf("\n2. RESTA.");
    printf("\n3. MULTIPLICACION.");
    printf("\n4. DIVISION.");
    printf("\nDigite el numero: ");
    scanf("%hhd",&*operacion);
}

void operar_valores(float num1_real, float num1_imaginario, float num2_real, float num2_imaginario, char operacion, float *resultado1, float *resultado2)
{
    float rta1, rta2= 0;
    if( operacion == 1)
    {
       rta1 = num1_real + num2_real;
       rta2 = num1_imaginario + num2_imaginario;
       *resultado1 = rta1;
       *resultado2 = rta2;
    }
    if(operacion == 2)
    {
          rta1 = num1_real + (-1 * num2_real);
          rta2 = num1_imaginario + (-1 * num2_imaginario);
          *resultado1 = rta1;
          *resultado2 = rta2;
    }
    if(operacion == 3)
    {
       rta1 = (num1_real * num2_real)+((num1_imaginario * num2_imaginario)*-1);
       rta2 = (num1_imaginario * num2_real)+(num1_real * num2_imaginario);
       *resultado1 = rta1;
       *resultado2 = rta2;
    }
    if(operacion == 4)
    {
          rta1 = (((num1_real * num2_real)+(num1_imaginario * num2_imaginario))/((num2_real * num2_real)+(num2_imaginario * num2_imaginario)));
          rta2 = (((num1_imaginario * num2_real)-(num1_real * num2_imaginario))/((num2_real * num2_real)+(num2_imaginario * num2_imaginario)));
          *resultado1 = rta1;
          *resultado2 = rta2;
    }
}

void mostrar_resultado(char operacion, float resultado1, float resultado2, float num2_imaginario)
{
    if(operacion == 1)
    {
       if(resultado2 > 0)
       {
          printf("\n%s%f%s%f%s","El resultado es :",resultado1,"+",resultado2,"i\n");
       }
       else
       {
          printf("\n%s%f%f%s","El resultado es : ",resultado1,resultado2,"i\n");
       }
    }
    if(operacion == 2)
    {
       if(resultado2 < 0)
       {
          printf("\n%s%f%f%s","El resultado es :", resultado1,resultado2,"i\n");
       }
       else
       {
          printf("\n%s%f%s%f%s","El resultado es :",resultado1,"+",resultado2,"i\n");
       }
    }
    if(operacion == 3)
    {
       if(resultado2 > 0)
       {
          printf("\n%s%f%s%f%s","El resultado es : ", resultado1,"+",resultado2,"i\n");
       }
       else
       {
          printf("\n%s%f%f%s","El resultado es :",resultado1,resultado2,"i\n");
       }
    }
    if(operacion == 4)
    {

       if(resultado2 < 0)
       {
         printf("%s%f%f%s","El resultado es : ", resultado1,resultado2,"i\n");
       }
       else
       {
         printf("%s%f%s%f%s","El resultado es :", resultado1, "+",resultado2,"i\n");
       }
    }
}
