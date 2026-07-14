#include <stdio.h>
#include <stdlib.h>

void FnSorting();

int main()
{
    FnSorting();
}

void FnSorting()
{
    int Employee;
    int pedrito,mirabal,catedral,gregorio,bluey; int d1,d2,d3,d4,m;
    // Reset all bill counters to 0 for the NEW employee
    pedrito = 0; mirabal = 0; catedral = 0; gregorio = 0; bluey = 0;
    d1,d2,d3,d4,m = 0;
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
    
    if (d1 % 2 == 0 && d1 != 0){bluey = d1/2; d1 = 0;} //2000 dop
    if (d1 % 2 != 0 && d1 != 1 ) {bluey = d1-1; d1 = 1;} //para los 2000 imparejos, 3000 = 2000 + 1000
   
    if (d2 % 5 == 0 && d2 != 0){pedrito = 1; d2=0;} //para los 500
    
    if (d2 % 2 == 0){mirabal = d2/2; d2=0;} //para los 200 ej 400 dop, 4/2 = 2 o 2 billetes de 200
    if (d2 % 2 != 0 && d2 != 1 ) {mirabal = d2-1; d2 = 1;} //para los 200 imparejos, 300 = 200 + 100
    
    if (d3 >= 5) {catedral = 1; d3 = d3-5;}//remover cualquier valor mas de 50
    
    if ((d3*10)+d4 >= 25) //con la sobra buscamos ver si puede tener un 25
    {gregorio = 1;       
    m = (d3*10)+d4;
    m = m-25;
    d4 = (m % 10);
    d3 = (m/10) % 10;
    }
    
    
    printf("Necesitas %d x2000 %dx1000, %dx500, %dx200, %dx100, %dx50 %dx25 %dx10 y %d pesos\n\n", bluey,d1,pedrito,mirabal,d2,catedral,gregorio,d3,d4);
}