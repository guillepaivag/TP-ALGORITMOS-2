#include <stdio.h>
#include <stdlib.h>

struct areas
{
	int dato;
	struct areas *ant;
	struct areas *sig;
};
struct tipos{
	int pasos[5]={-1,-1,-1,-1,-1};

};

typedef struct areas areaDoc;
typedef struct tipos tipos;

int cantidadTipos;
int cantDocumentos;


void addDato(areaDoc**, areaDoc**, int);
void preguntolostiposnuevo();


int main(){

	int comenzarPrograma = 1;
	int contadorDeVecees = 0;
	int simulacion;

	areaDoc* area[2][5] = {
		{NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL}
	};	

	while(comenzarPrograma != 0)
	{
		printf("\nDesea comenzar el programa? ");
		scanf("%d", &comenzarPrograma);

		if(comenzarPrograma)
		{
			contadorDeVecees++;

			printf("\n1. SIMULACION NUEVA\n2. SIMULACION ANTERIOR\n");
			scanf("%d", &simulacion);
			
			switch(simulacion){
				case 1:
					contadorDeVecees = 1;
					// se debe reiniciar todo
					preguntolostiposnuevo();


					//run();
				break;

				case 2:
					if(contadorDeVecees > 1){
						


						//run();
					}
				break;
			}

		}else{
			printf("HASTA LA PROXIMA\n");
		}




	}

	return 0;
}
void preguntolostiposnuevo(){
	int definido;
	tipos vecTipos[cantidadTipos];

	printf("\nIngresecantidad de tipos de documentos \n");
	scanf("%d",&definido);
	if(definido == 1){
		scanf("%d",&cantidadTipos);
	}
	
	for(i=0;i<cantidadTipos;i++){
		printf("\nIngrese las areas por las que pasa el tipo %d en formato enter para cada area en orden: ");
		scanf("%d",&pasos);
		for(j=0;j<5;j++){
			if(pasos == j){
				c++;
				vecTipos[i].pasos[j]=c;
			}
		}
	}



}



void addDato(areaDoc* *area, areaDoc* *ult, int myDato){

	int i;
	areaDoc* newDoc;

	newDoc = (areaDoc*) malloc(sizeof(areaDoc));

	newDoc->dato = myDato;

	if(*area == NULL){
		newDoc->ant = NULL;
		newDoc->sig = NULL;
		*area = newDoc;
		*ult = newDoc;
	}else{
		newDoc->ant = *ult;
		newDoc->sig = NULL;
		(*ult)->sig = newDoc;
		*ult = newDoc;
	}
}

void run(){
	int i;
	int posArea, myDato;
	areaDoc* aux;

	while(1){

		printf("INGRESE POSICION: ");
		scanf("%d", &posArea);
		printf("INGRESE DATO: ");
		scanf("%d", &myDato);

		if(myDato == 0){
			break;
		}

		addDato(&area[0][posArea-1], &area[1][posArea-1], myDato);

	}

	for(i = 0; i < 5; i++){
		aux = area[0][i];
		while(aux != NULL){
			printf("%d ", aux->dato);
			aux = aux->sig;
		}
		printf("\n");
	}
}
