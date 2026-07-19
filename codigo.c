#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>


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

VENTA venta;

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

void FnSorting(int IN, bool ADD);
void ApCiCaja(int N);
void Apcaja();
void CiCaja();
void Ventas();
void REGISventas();
void menu();

int main()
{
    menu();
    return 0;
}

void menu() {
    int opcion;

    do{
        //imprimir el menu de la boleteria 
        printf("\n*** MODULO: Boleteria ***\n");
        printf("Menu de opciones\n\n");
        printf("1.Apertura de caja\n");
        printf("2.Cierre de caja\n");
        printf("3.Resgistro de ventas de boletas\n");
        printf("4.Registro de ventas diarias\n");
        printf("5.Salir\n\n");
        printf("Seleccione una opcion: ");

        //leer la opcion del usuario 
        scanf("%d", &opcion);

        while (opcion < 1 || opcion > 5) {
            printf("\nEsa opcion no es valida. Intente de nuevo: ");
            scanf("%d", &opcion);
        }

        //evaluar la opcion seleccionada
        switch(opcion) {
            case 1:
            printf("\n[ejecutando] apertura de caja...\n"); ApCiCaja(opcion);
            //logica para apertura de caja
            break;
            case 2:
            printf("\n[ejecutando] cierre de caja...\n"); ApCiCaja(opcion);
            //logica para cierre de caja 
            break;
            case 3:
            printf("\n[ejecutando] registro de ventas de boletas...\n"); REGISventas();
            break;
            case 4:
            printf("\n[ejecutando] generando reporte de ventas diarias...\n");
            //logica para el reporte 
            break;
            case 5:
            printf("\n saliendo del sistema. Hasta luego!");
            break;
            default:
            printf("\n opcion no valida. Por favor, intente de nuevo.\n");
            break;

        }

        printf ("-----------------------------------------\n");

    } while(opcion != 5); // el ciclo se repite hasta que la opcion sea 5

}

void ApCiCaja(int N) {

    switch (N) {
        case 1: caja.operacion = 'A'; Apcaja(); break;
        case 2: caja.operacion = 'C'; break;
        default: caja.operacion = '?'; break;
    }
    
    caja.secuencia = 1000; //debe incrementar cada apertura..
    strcpy(caja.fecha, "N/A"); //fecha basado con time.h
    caja.efectivo = 0.0f;
    caja.tarjeta = 0.0f;

    printf("Secuencia:                  %d\n"
           "Operacion:                  %c\n"
           "Fecha:                      %s\n"
           "Monto Efectivo:             %.2f\n"
           "Monto TC:                   %.2f\n",
           caja.secuencia,
           caja.operacion,
           caja.fecha,
           caja.efectivo,
           caja.tarjeta);

    printf("Denominaciones:\n"
           "Monedas de 1:       %d     Monedas de 5:        %d\n"
           "Monedas de 10:      %d     Monedas de 25:       %d\n"
           "Billetes de 50:     %d     Billetes de 100:     %d\n"
           "Billetes de 200:    %d     Billetes de 500:     %d\n"
           "Billetes de 1000:   %d     Billetes de 2000:    %d\n",
           caja.m1,
           caja.m5,
           caja.m10,
           caja.m25,
           caja.b50,
           caja.b100,
           caja.b200,
           caja.b500,
           caja.b1000,
           caja.b2000);
}

void Apcaja()
{
    int a;
    printf("Ingrese denominaciones del dia:\n");

    printf("Cuantas monedas de 1? ");
    scanf("%d", &a);
    caja.m1 = a;
    printf("Cuantas monedas de 5? ");
    scanf("%d", &a);
    caja.m5 = a;
    printf("Cuantas monedas de 10? ");
    scanf("%d", &a);
    caja.m10 = a;
    printf("Cuantas monedas de 25? ");
    scanf("%d", &a);
    caja.m25 = a;
    printf("Cuantos billetes de 50? ");
    scanf("%d", &a);
    caja.b50 = a;
    printf("Cuantos billetes de 100? ");
    scanf("%d", &a);
    caja.b100 = a;
    printf("Cuantos billetes de 200? ");
    scanf("%d", &a);
    caja.b200 = a;
    printf("Cuantos billetes de 500? ");
    scanf("%d", &a);
    caja.b500 = a;
    printf("Cuantos billetes de 1000? ");
    scanf("%d", &a);
    caja.b1000 = a;
    printf("Cuantos billetes de 2000? ");
    scanf("%d", &a);
    caja.b2000 = a;
}

void CiCaja()
{
    
}

void Ventas()
{

    printf("Cuanto se pago?  "); //ej 200DOP
    scanf("%f",&venta.pago); //no tengo internet pa ver lo de fgets
    printf("Cuantos tickets se vendieron? "); //ej un ticket es 50DOP
    scanf("%d",&venta.cantidad);

    venta.precio = 50 * venta.cantidad; //EJ 3 tickets x 50DOP = 150DOP
    venta.devolucion = venta.pago - venta.precio;
    FnSorting(venta.pago,true); FnSorting(venta.devolucion,false);

    //(venta.precio) incrementa el valor de un acumulador (ventas totales) para el reporte de ventas diarias! (ง🔥ﾛ🔥)ง
    
}

void REGISventas(){

    Ventas();
     printf("Denominaciones:\n"
           "Monedas de 1:       %d     Monedas de 5:        %d\n"
           "Monedas de 10:      %d     Monedas de 25:       %d\n"
           "Billetes de 50:     %d     Billetes de 100:     %d\n"
           "Billetes de 200:    %d     Billetes de 500:     %d\n"
           "Billetes de 1000:   %d     Billetes de 2000:    %d\n",
           caja.m1,
           caja.m5,
           caja.m10,
           caja.m25,
           caja.b50,
           caja.b100,
           caja.b200,
           caja.b500,
           caja.b1000,
           caja.b2000);
}

void FnSorting(int IN, bool ADD)
{
    int pedrito,mirabal,catedral,gregorio,bluey,sanchez; int d1,d2,d3,d4,m;
    // Reset all bill counters to 0 for the NEW employee
    pedrito = 0; mirabal = 0; catedral = 0; gregorio = 0; bluey = 0; sanchez =0;
    d1 = d2 = d3 = d4 = m = 0;
    //pedrito = 500
    //mirabal = 200
    //catedral = 50
    //gregorio = 25 
    //bluey = 2000 dop
   
    d4 = (IN % 10); //4 123.4
    d3 = (IN/10) % 10; //3 12.34
    d2 = (IN/100) % 10; //2 1.234
    d1 = (IN/1000); //1 0.1234
    
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
    
    
    //printf("Necesitas %d x2000 %dx1000, %dx500, %dx200, %dx100, %dx50 %dx25 %dx10 %dx5 y %d pesos\n\n", bluey,d1,pedrito,mirabal,d2,catedral,gregorio,d3,sanchez,d4);

    //Billete de ingreso  - COSTO DE VENTA = DEVOLUCION
    // Sorting(Billete de ingreso) & Sorting(Devolucion)
    //agregar valores de Sorted BDI), Restar valores de sorted DEVOL
    //Que billetes se pierden al hacer la devolucion?

    if(ADD == true){ 
    caja.m1 += d4;
    caja.m5 += sanchez;
    caja.m10 += d3;
    caja.m25 += gregorio;

    caja.b50 += catedral;
    caja.b100 += d2;
    caja.b200 += mirabal;

    caja.b500 += pedrito;
    caja.b1000 += d1;
    caja.b2000 += bluey;}
    
    else{
    caja.m1 -= d4;
    caja.m5 -= sanchez;
    caja.m10 -= d3;
    caja.m25 -= gregorio;

    caja.b50 -= catedral;
    caja.b100 -= d2;
    caja.b200 -= mirabal;

    caja.b500 -= pedrito;
    caja.b1000 -= d1;
    caja.b2000 -= bluey;
    }

}