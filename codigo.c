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

    FnSorting();
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
    int pedrito,mirabal,catedral,gregorio,bluey,sanchez; int d1,d2,d3,d4,m;
    // Reset all bill counters to 0 for the NEW employee
    pedrito = 0; mirabal = 0; catedral = 0; gregorio = 0; bluey = 0; sanchez =0;
    d1 = d2 = d3 = d4 = m = 0;
    //pedrito = 500
    //mirabal = 200
    //catedral = 50
    //gregorio = 25 
    //bluey = 2000 dop

    printf("Inserta Valor: "); scanf("%d",&Employee);
   
    d4 = (Employee % 10); //4 123.4
    d3 = (Employee/10) % 10; //3 12.34
    d2 = (Employee/100) % 10; //2 1.234
    d1 = (Employee/1000); //1 0.1234

    printf("%d%d%d%d ",d1,d2,d3,d4);
    
    bluey = d1 / 2;
    d1 %= 2; //para los 2000
   
    if (d2 >= 5){ //para los 500
    pedrito = 1;
    d2 -= 5;}
    
    if (d2 >= 2){
    mirabal = d2 / 2;
    d2 %= 2;}
    
    if (d3 >= 5) {catedral = 1; d3 = d3-5;}//remover cualquier valor mas de 50
    
    if ((d3*10)+d4 >= 25) //con la sobra buscamos ver si puede tener un 25
    {gregorio = 1;       
    m = (d3*10)+d4;
    m = m-25;
    d4 = (m % 10);
    d3 = (m/10) % 10;
    }

    if (d4 >= 5){d4 = d4-5; sanchez = 1;}
    
    
    printf("Necesitas %d x2000 %dx1000, %dx500, %dx200, %dx100, %dx50 %dx25 %dx10 %dx5 y %d pesos\n\n", bluey,d1,pedrito,mirabal,d2,catedral,gregorio,d3,sanchez,d4);

    caja.m1 = d4;
    caja.m5 = sanchez;
    caja.m10 = d3;
    caja.m25 = gregorio;

    caja.b50 = catedral;
    caja.b100 = d2;
    caja.b200 = mirabal;

    caja.b500 = pedrito;
    caja.b1000 = d1;
    caja.b2000 = bluey;

    printf("Necesitas %d x2000 %dx1000, %dx500, %dx200, %dx100, %dx50 %dx25 %dx10 %dx5 y %d pesos\n\n",
       caja.b2000,
       caja.b1000,
       caja.b500,
       caja.b200,
       caja.b100,
       caja.b50,
       caja.m25,
       caja.m10,
       caja.m5,
       caja.m1);
}