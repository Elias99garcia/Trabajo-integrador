/*TRABAJO INTEGRADOR PRIMER CUATRIMESTRE (ORDENAMIENTO)
FACULTAD REGIONAL TUCUMAN
ALUMNOS : GIMENEZ LEANDRO NAHUEL, GARCIA JOSE ELIAS
*/

#include<iostream>
#include<conio.h>
#define MAX 1000
using namespace std;

//Prototipo de funciones DATOS
void pedirDatos();
void pedirDatos2();
void pedirDatos3();
void pedirDatos4();
//Prototipo de funciones ORDENAMIENTOS
int vecBurbuja(int arreglo1[],int);
int vecInsercion(int arreglo2[],int);
int vecSencillo(int arreglo3[],int);
void QuickSort(int [] , int );
void Imprimir(int [] , int);
//Ordenamiento MERGESORT
void intercambio(int &a, int &b);
void muestra(int *array, int size);
void merge(int *array, int l, int m, int r);
void mergeSort(int *array, int l, int r);



//Variables globales
int arreglo1[100],tam1;
int arreglo2[100],tam2;
int arreglo3[100],tam3;
int arreglo4[100],tam4;
int arreglo5[100],tam5;
int n ;

//Programa principal
int main(){
	
	int opc;
	float extra;
	
	//Menu
	cout<<"\n\t********************************************************************"<<endl;
	cout<<"\t*Bienvenido al programa, cargue su vector segun sus caracteristicas*"<<endl;
	cout<<"\t*1. Intercambio o burbuja mejorada                                 *"<<endl;
	cout<<"\t*2. Insercion o metodo de la baraja                                *"<<endl;
	cout<<"\t*3. Seleccion o metodo sencillo                                    *"<<endl;
	cout<<"\t*4. Rapido o QuickSort                                             *"<<endl;
	cout<<"\t*5. Por Mezcla o MergeSor                                          *"<<endl;
	cout<<"\t*6. Salir                                                          *"<<endl;
	cout<<"\t********************************************************************"<<endl;
	cout<<"\nOpcion: "; 
	cin>>opc;
	
	switch(opc){
		case 1: 
		    //Llamada a las funciones
		       pedirDatos();
		       vecBurbuja(arreglo1,tam1);
				break;
		case 2: 
		       pedirDatos2();
		       vecInsercion(arreglo2,tam2);
		       break;
		       
		case 3:
			   pedirDatos3();
			   vecSencillo(arreglo3,tam3);
			   break;
		case 4:
			   cout<<"Digite el numero de elementos del vector:  "<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){

        cout<<" . Digite un numero: "<<i+1<<" : "<<endl;
        cin>>a[i];
    }
    QuickSort(a,n);
    Imprimir(a,n);
    break;
       case 5:
       	cout << "Digite el numero de elementos del vector: ";
   cin >> n;
   int arr[n];     //Esto crea un vector con un numero determinado de elementos
   cout << ". Digite un numero:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "VECTOR ANTES DE ORDENAR: ";
   muestra(arr, n);
   mergeSort(arr, 0, n-1);     //(n-1) para el ultimo indice
   cout << "VECTOR DESPUES DE ORDENAR: ";
   muestra(arr, n);
    break;
			   		
	}
	getch();
	return 0;
}


//FUNCIONES
void pedirDatos(){
	cout<<"Digite el numero de elementos del vector: ";
	cin>>tam1;
	
	for(int i=0;i<tam1;i++){
		cout<<i+1<<" . Digite un numero: ";
		cin>>arreglo1[i];
	}
}
void pedirDatos2(){
	cout<<"Digite el numero de elementos del vector: ";
	cin>>tam2;
	
	for(int i=0;i<tam2;i++){
		cout<<i+1<<" . Digite un numero: ";
		cin>>arreglo2[i];
	}
}
void pedirDatos3(){
	cout<<"Digite el numero de elementos del vector: ";
	cin>>tam3;
	
	for(int i=0;i<tam3;i++){
		cout<<i+1<<" . Digite un numero: ";
		cin>>arreglo3[i];
	}
}
void pedirDatos4(){
	cout<<"Digite el numero de elementos del vector: ";
	cin>>tam4;
	
	for(int i=0;i<tam4;i++){
		cout<<i+1<<" . Digite un numero: ";
		cin>>arreglo3[i];
	}
}

int vecBurbuja(int arreglo1[],int tam1){
	int i,j,aux;
	
	for (i=0;i<5;i++){
		
		//Algoritmo del metodo burbuja
		for(j=0;j<tam1;j++){
			if(arreglo1[j]> arreglo1[j+1]){
				
				aux = arreglo1[j];
				arreglo1[j] = arreglo1[j+1];
				arreglo1[j+1]=aux;
			}
		}
		
	}
	
	cout<<"Orden ascendente: " ;
	for(i=0;i<tam1;i++){
		cout<<arreglo1[i]<<" ";
	}
	
	cout<<"\nOrden descentente: ";
	for(i=tam1;i>=0;i--){
		cout<<arreglo1[i]<<" ";
	}

}
//FUNCION METODO INSERCION
int vecInsercion(int arreglo2[],int tam2){
	int i,pos,aux;
	//Algoritmo del metodo de insercion
	for(i=0;i<tam2;i++){
		pos = i;
		aux = arreglo2[i];
		while((pos>0) && (arreglo2[pos-1] > aux)){
			arreglo2[pos] = arreglo2[pos-1];
			pos--;
		}
		arreglo2[pos] = aux;
	}
	
	cout<<"Orden ascendente: ";
	for(i=0;i<tam2;i++){
		cout<<arreglo2[i]<<" ";
	}
	
	cout<<"\n Orden descente: ";
	for(i=tam2;i>=0;i--){
		cout<<arreglo2[i]<<" ";
	}	
}

int vecSencillo(int arreglo3[],int tam3){
	int i,j,aux,min;
	
	//Algoritmo del ordenamiento por seleccion
	for(i=0;i<tam3;i++){
		min = i;
		for(j=i+1;j<tam3;j++){
			if(arreglo3[j] < arreglo3[min]){
				min = j;
				
			}
		}
		aux = arreglo3[i];
		arreglo3[i] = arreglo3[min];
		arreglo3[min] = aux;
	}
	cout<<"Orden Ascendente: ";
	for(i=0;i<tam3;i++){
		cout<<arreglo3[i]<<" ";
	}
	
	cout<<"\n Orden descente: ";
	for(i=tam3;i>=0;i--){
		cout<<arreglo3[i]<<" ";
	}	
	
}

void QuickSort(int a[] , int n){

    int tope, ini, fin , pos;
    
            int may[MAX],menor[MAX];
            tope=0;
            menor[tope]=0;
            may[tope]=n-1;
            while(tope>=0)
            {
                ini = menor[tope];
                fin = may[tope];
                tope--;

            int izq,der,aux;
            bool band;
            izq=ini;
            der=fin;
            pos=ini;

            band=true;

            while(band==true)
            {
                while((a[pos]<a[der]) && ( pos!=der ))
                    der--;

                if(pos==der)
                    band=false;
                else
                {
                    aux=a[pos];
                    a[pos]=a[der];
                    a[der]=aux;
                    pos=der;
                }

                while((a[pos]>a[izq]) && ( pos!=izq ))
                    izq++;

                 if(pos==izq)
                    band=false;
                else
                {
                    aux=a[pos];
                    a[pos]=a[izq];
                    a[izq]=aux;
                    pos=izq;
                }


            }

                if(ini<=(pos-1))
                {
                    tope++;
                    menor[tope]=ini;
                    may[tope]=pos-1;

                }

                if(fin>=(pos+1))
                {
                    tope++;
                    menor[tope]=pos+1;
                    may[tope]=fin;
                }




            }

}




void Imprimir(int a[] , int n){

    cout<<"Orden Ascendente: ";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}


}
//ORDENAMIENTO MERGESORT

void intercambio(int &a, int &b) {     //intercambia el contenido de A y B
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void muestra(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];

   for(i = 0; i<nl; i++)
      larr[i] = array[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //TRANSFIERE LOS DATOS
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         array[k] = larr[i];
         i++;
      }else{
         array[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //Elemento extra en la matriz izquierda
      array[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     //Elemento extra en la matriz derecha
      array[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      //Ordena las matrices
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

