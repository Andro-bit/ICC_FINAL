#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>



typedef struct
{
    int secuencia; // Número de la apertura de caja a la que pertenece esta venta
    char fecha[11];
    int cantidad;
    float precio;
    char tipoPago;
    float pago;
    float devolucion;
    int cash;
    int card; // Para saber si el dinero fue recibido con efectivo o tarjeta

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
bool OpenSale = false;

void FnSorting(int IN, bool ADD);
void ApCiCaja(int N);
void AperturaCaja();
void CierreCaja();
void Ventas();
void PrintReport(VENTA Placeholder);
void PrintTotal(int E, int C, int T);
int NextSequence();
void REGISventas();
void DailySales();
void menu();
void GuardarCaja();

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
        printf("3.Agregar ventas de boletas...\n");
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
            printf("\n[ejecutando] Agregar ventas de boletas...\n"); REGISventas();
            break;
            case 4:
            printf("\n[ejecutando] generando reporte de ventas diarias...\n"); DailySales();
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


    // hice estos cambios because in order de hacer el reporte diario de ventas
    // necesito que las secuencias se registren y se guarden, ademas de que
    // yo cada venta la ire registrando por apertura y cierre so aja.
    switch (N) {
        case 1:
            if (!OpenSale) {
                caja.operacion = 'A';
                caja.secuencia = NextSequence();
                AperturaCaja();
                GuardarCaja();
                OpenSale = true;
            } else printf("La caja ya esta abierta bro");
            break;
        case 2:
            if (OpenSale) {
                caja.operacion = 'C';
                CierreCaja();
                GuardarCaja();
                OpenSale = false;
                break;
            }
        default: caja.operacion = '?'; break;
    }
    

    strcpy(caja.fecha, "N/A"); //fecha basado con time.h
    caja.efectivo = 0.0f;
    caja.tarjeta = 0.0f;

    printf(
    "Secuencia:                  %d\n"
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

void AperturaCaja()
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

    // VALIDAR INGRESO Y ASEGURAR (se recomienda que que sea una funcion) - Tarea de Andrey
}

void CierreCaja()
{
    // ver lo que quedo, cuadrarlo con lo que vendi y ver cuanto gane - Tarea de Andrey
}


void GuardarCaja() {
    FILE *archivoCaja = NULL;
    int intentos = 0;

    // Se agregó un ciclo while que intenta abrir el archivo hasta 3 veces antes de cancelar la operación.
    // Si después de esos intentos fopen() sigue devolviendo NULL, se muestra un mensaje de error al usuario
    // y la función termina sin intentar escribir en el archivo.

    while (archivoCaja == NULL && intentos < 3) {
        archivoCaja = fopen("caja.dat", "ab");

        if (archivoCaja == NULL) {
            intentos++;

            if (intentos < 3) {
                printf("No se pudo abrir caja.dat. Reintentando (%d/3)...\n", intentos + 1);
            }
        }
    }

    if (archivoCaja == NULL) {
        printf("Error: no fue posible abrir caja.dat despues de 3 intentos.\n");
        printf("Verifique que el archivo no este siendo usado por otro programa o que tenga permisos de escritura.\n");
        return;
    }

    FILE *ventasCaja = NULL;
    int try = 0;

    while (ventasCaja == NULL && try < 3) {
        // Si el archivo no existe, mostrar un mensaje y terminar la función
        ventasCaja = fopen("ventas.dat", "ab");

        if (ventasCaja == NULL) {
            try++;

            if (intentos < 3) {
                printf("No se pudo abrir caja.dat. Reintentando (%d/3)...\n", intentos + 1);
            }
        }
    }

    // guardar caja y venta
    fwrite(&venta, sizeof(VENTA), 1, ventasCaja);
    fwrite(&caja, sizeof(CAJA), 1, archivoCaja);
    fclose(archivoCaja);
    fclose(ventasCaja);
}

/* NextSequence() es una función encargada de obtener el número de secuencia que tendrá la próxima
apertura de caja. Primero intenta abrir el archivo binario caja.dat
en modo lectura. Si el archivo no existe, significa que nunca se ha registrado una caja, por lo que
devuelve 1000 como la primera secuencia. Si el archivo existe, mueve el puntero hasta el inicio del último
registro utilizando fseek(), lee esa última estructura CAJA con fread() y obtiene su campo secuencia.
Finalmente, devuelve ese valor incrementado en uno, asegurando que cada nueva apertura de caja tenga
una secuencia única y consecutiva, incluso si el programa se cierra y se vuelve a ejecutar. */

int NextSequence() {

    CAJA ultimaCaja;
    FILE *archivoCaja = fopen("caja.dat", "rb");
    if (archivoCaja == NULL) {
		// this means it's the first time so it's a 1000
        return 1000;
    }

	// comienza a leer archivo Caja desde el final pero retrocede exactamente el size
	// de un struct y asi encuentra el ultimo
    fseek(archivoCaja, -sizeof(CAJA), SEEK_END);

	// Lee la info de la variable temporal ultimaCaja de tipo caja
	// en el lugar que encontre
    fread(&ultimaCaja, sizeof(CAJA), 1, archivoCaja);

    fclose(archivoCaja);

	// devuelve ultima secuencia mas uno
    return ultimaCaja.secuencia + 1;

}

/* La función DailySales() genera el historial de ventas recorriendo todas las secuencias de caja desde la más reciente
 * hasta la primera registrada. Para cada secuencia, reinicia los acumuladores de efectivo, tarjeta y ganancias, vuelve
 * al inicio del archivo ventas.dat y lee cada venta con fread(). Si la venta pertenece a la secuencia actual, la
 * imprime mediante PrintReport() y acumula sus valores. Cuando termina de revisar all of el archivo para esa secuencia,
 * imprime un resumen con los totales usando PrintTotal(). Este proceso se repite para cada apertura de caja, permitiendo
 * mostrar el historial agrupado por secuencia sin modificar la información almacenada en el archivo. */

void DailySales() {

    printf("Bienvenido al registro de ventas \n");

    FILE *ventasCaja = fopen("ventas.dat", "rb");

    if (ventasCaja == NULL) {
        printf("No existen ventas registradas.\n");
        return;
    }

    VENTA tempSale;

    int efectivo;
    int tarjeta;
    int gananciasTotales;
    bool ventaEncontrada;

    int LastSequence = NextSequence() - 1;

    // recorrer secuencias
    for (int secuencia = LastSequence; secuencia >= 1000; secuencia--) {

        ventaEncontrada = false;
        efectivo = 0;
        tarjeta = 0;
        gananciasTotales = 0;

        // Vuelve el puntero al inicio
        rewind(ventasCaja);

        while (fread(&tempSale, sizeof(VENTA), 1, ventasCaja) == 1) {

            if (tempSale.secuencia == secuencia) {

                // se le suma lo que conseguimos a los acumuladores
                efectivo += tempSale.cash;
                tarjeta += tempSale.card;
                gananciasTotales += tempSale.cash + tempSale.card;

                PrintReport(tempSale);
                ventaEncontrada = true;
            }
        }

        if (ventaEncontrada) {
            PrintTotal(efectivo, tarjeta, gananciasTotales);
        }

    }

    fclose(ventasCaja);
}

void PrintReport(VENTA Placeholder) {
    printf(" Caja No. %d \n", Placeholder.secuencia);
    printf("Fecha XXXX \n"); // no loco hagan ustedes lo de fecha que me di cuenta que el struct de VENTA ni fecha tiene
    printf("Monto recibido en efectivo %d \n", Placeholder.cash);
    printf("Monto recibido en tarjeta %d \n", Placeholder.card);
    printf("Total venta %d \n", Placeholder.cash + Placeholder.card);
}

void PrintTotal(int E, int C, int T) {
    printf("Total dinero Efectivo secuencia: %d \n", E);
    printf("Total dinero Tarjeta secuencia: %d \n", C);
    printf("Total dinero secuencia: %d \n", T);
}

void Ventas()
{
    int select;
    do {
        printf("Desea pagar con [1]Efectivo o [2]Tarjeta? \n");
        scanf("%d", &select);
        getchar();
        switch(select) {
            case 1: {
                printf("Cuantos tickets se vendieron? "); //ej un ticket es 50DOP
                scanf("%d",&venta.cantidad);

                // NOTA DEJAR UN APARTADO PARA PAGO INSUFICIENTE
                printf("Cuanto se pago?  "); //ej 200DOP
                scanf("%f",&venta.pago); //no tengo internet pa ver lo de fgets

                venta.cash = 50 * venta.cantidad; //EJ 3 tickets x 50DOP = 150DOP
                venta.devolucion = venta.pago - venta.cash;
                FnSorting(venta.pago,true); FnSorting(venta.devolucion,false);
                break;

                //(venta.cash) incrementa el valor de un acumulador (ventas totales)
                // para el reporte de ventas diarias! (ง🔥ﾛ🔥)ง
            }
            case 2: {
                printf("Cuantos tickets se vendieron? "); //ej un ticket es 50DOP
                scanf("%d",&venta.cantidad);
                printf("Se recibieron %d pesos \n", 50 * venta.cantidad);
                venta.card = 50 * venta.cantidad; //EJ 3 tickets x 50DOP = 150DOP
                break;
            }
            default: {
                printf("Opcion invalida \n"); break;
            }
        }
    } while (select != 1 && select != 2);
}

void REGISventas(){

    if (caja.operacion == 'A') {
        Ventas();
        venta.secuencia = caja.secuencia;
        GuardarCaja();
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
    } else {
        printf("No puede realizar ventas. Debe abrir una caja primero.\n");
    }
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