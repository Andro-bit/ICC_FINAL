#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

FILE *sales;

typedef struct
{
    int secuencia;
    char fecha[11];
    int cantidad;
    float precio;
    char tipoPago;
    float pago;
    float devolucion;

}VENTA;

typedef struct
{
    int secuencia;
    char operacion;
    char fecha[11];
    float efectivo;
    float tarjeta;

    int m1;
    int m5;
    int m10;
    int m25;

    int b50;
    int b100;
    int b200;
    int b500;
    int b1000;
    int b2000;

}CAJA;

CAJA caja;

void FnSorting();

int main()
{

}

void ApCiCaja(int N) {

    // incializar los valores

    caja.secuencia = 1000;
    strcpy(caja.fecha, "N/A");
    switch (N) {
        case 1: caja.operacion = 'A'; break;
        case 2: caja.operacion = 'C'; break;
        default: break;
    }
    caja.efectivo = 0;
    caja.tarjeta = 0;

    // cantidad de billetes y monedas que se multiplicara por su valor correspondiente
    caja.m1 = 100;
    caja.m5 = 100;
    caja.m10 = 100;
    caja.m25 = 100;

    caja.b50 = 50;
    caja.b100 = 50;
    caja.b200 = 50;

    caja.b500 = 10;
    caja.b1000 = 10;
    caja.b2000 = 10;
}

void FnSorting()
{

    int Employee;
    int m;

    // toy harta de la vida andrey ppdios este bendito codigo me tiene hara
    /// pipipipi nnn

    printf("Inserta Valor: "); scanf("%d",&Employee);

    caja.m1 = (Employee % 10); //4 123.4
    caja.m10 = (Employee/10) % 10; //3 12.34
    caja.b100 = (Employee/100) % 10; //2 1.234
    caja.b1000 = (Employee/1000); //1 0.1234

    printf("%d%d%d%d ",caja.b1000,caja.b100,caja.m10,caja.m1);

    if (caja.b1000 % 2 == 0 && caja.b1000 != 0){caja.b2000 = caja.b1000/2; caja.b1000 = 0;} //2000 dop
    if (caja.b1000 % 2 != 0 && caja.b1000 != 1 ) {caja.b200 = caja.b1000-1; caja.b1000 = 1;} //para los 2000 imparejos, 3000 = 2000 + 1000

    if (caja.b100 % 5 == 0 && caja.b100 != 0){caja.b500 = 1; caja.b100=0;} //para los 500

    if (caja.b100 % 2 == 0){caja.b200 = caja.b100/2; caja.b100=0;} //para los 200 ej 400 dop, 4/2 = 2 o 2 billetes de 200
    if (caja.b100 % 2 != 0 && caja.b100 != 1 ) {caja.b200 = caja.b100-1; caja.b100 = 1;} //para los 200 imparejos, 300 = 200 + 100

    if (caja.m10 >= 5) {caja.b50 = 1; caja.m10 = caja.m10-5;}//remover cualquier valor mas de 50


    if ((caja.m10*10)+caja.m1 >= 25) //con la sobra buscamos ver si puede tener un 25
    {caja.m25 = 1;
    m = (caja.m10*10)+caja.m1;
    m = m-25;
    caja.m1 = (m % 10);
    caja.m10 = (m/10) % 10;
    }

    printf("Necesitas %d x2000 %dx1000, %dx500, %dx200, %dx100, %dx50 %dx25 %dx10 y %d pesos\n\n", caja.b200,caja.b1000,caja.b500,caja.b200,caja.b100,caja.b50,caja.m25,caja.m10,caja.m1);
}