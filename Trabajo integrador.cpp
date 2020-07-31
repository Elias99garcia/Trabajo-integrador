
#include<iostream>
#include<conio.h>
#define MAX 1000
using namespace std;

//Prototipo de funciones
void pedirDatos();
void pedirDatos2();
void pedirDatos3();
void pedirDatos4();
int vecBurbuja(int arreglo1[],int);
int vecInsercion(int arreglo2[],int);
int vecSencillo(int arreglo3[],int);
void QuickSort(int [] , int );
void Imprimir(int [] , int);


//Variables globales
int arreglo1[100],tam1;
int arreglo2[100],tam2;
int arreglo3[100],tam3;
int arreglo4[100],tam4;
int n ;


int main(){
	
	int opc;
	float extra;
	
	cout<<"\tBienvenido al programa, cargue su vector segun sus caracteristicas:"<<endl;
	cout<<"1. Intercambio o burbuja mejorada"<<endl;
	cout<<"2. Insercion o metodo de la baraja "<<endl;
	cout<<"3. Seleccion o metodo sencillo  "<<endl;
	cout<<"4. Rapido o QuickSort   "<<endl;
	cout<<"5. Por Mezcla o MergeSor  "<<endl;
	
	cout<<"6. Salir"<<endl;
	cout<<"Opcion: "; 
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
		case 4:
			   cout<<"Ingrese el total de numeros: "<<endl;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){

        cout<<"Ingresa el elemento numero "<<i+1<<" : "<<endl;
        cin>>a[i];

    }

    QuickSort(a,n);
    Imprimir(a,n);
    break;

			   
		
	}
	getch();
	return 0;
}

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


