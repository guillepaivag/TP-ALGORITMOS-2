#include <stdio.h>
#include <stdlib.h>

struct areaDoc
{
	int dato;
	struct areaDoc *ant;
	struct areaDoc *sig;
};

struct tipos{
	int activo;
	int pasos[5];
};

typedef struct areaDoc areaDoc;
typedef struct tipos tipos;

int cantidadTipos;
int cantDocumentos;
tipos vecTipos[1];

void addDato(areaDoc**, areaDoc**, int);
void preguntaLosTiposNuevo(tipos*);

int main(){

	int modificacion;
	int comenzarPrograma = 1;
	int yaSimulada = 0;
	int simulacion;
	int procesoModificacion;

	areaDoc* area[2][5] = {
		{NULL, NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL, NULL}
	};


	while(comenzarPrograma != 0)
	{
		printf("\nDESEA COMENZAR EL PROGRAMA?\n1) COMENZAR\n0) SALIR\nRespuesta: ");
		scanf("%d", &comenzarPrograma);

		if(comenzarPrograma)
		{
			printf("\n1. SIMULACION NUEVA\n2. SIMULACION ANTERIOR\nRespuesta: ");
			scanf("%d", &simulacion);

			if(simulacion == 1){

					yaSimulada = 1;
					
					printf("\nCANTIDAD DE TIPOS: ");
					scanf("%d", &cantidadTipos); 
					tipos vecTipos[cantidadTipos];

					preguntaLosTiposNuevo(vecTipos);

					//run();
			}else if(simulacion == 2){

				if(yaSimulada == 1){
					
					printf("\nDESEA HACER MODIFICACIONES?\n 0) NO MODIFICAR\n 1) MODIFICAR\nRespuesta: ");
					scanf("%d", &modificacion);

					if(modificacion){

						printf("\nDESEA ELIMINAR? \n(Observacion: 0-NO, 1-SI)\nRespuesta: ");
						scanf("%d", &procesoModificacion);
						if(procesoModificacion){
							//eliminar();
						}
						printf("\nDESEA AGREGAR? \n(Observacion: 0-NO, 1-SI)\nRespuesta: ");
						scanf("%d", &procesoModificacion);
						if(procesoModificacion){
							//agregar();
						}

						//run();
					}else{
						//run();
					}

				}else{
					printf("NO SE HIZO NI UNA SIMULACION ANTES :(\n");
				}
			
			}else{
				printf("ELEGIR UNA OPCION VALIDA..\n");
			}

		}else{
			printf("HASTA LA PROXIMA\n");
		}

	}

	return 0;
}


void preguntaLosTiposNuevo(tipos vecTipos[])
{
	int i, j;

	// TIPO
	for(i = 0; i < cantidadTipos; i++){
		vecTipos[i].activo = 1;

		// AREAS
		printf("INGRESE LAS AREAS POR LA QUE PASARA EL TIPO %d: \n(Observacion: Colocar -1 para finalizar)\n", i+1);
		for(j = 0; j < 5; j++){
			printf("SU PASO %d sera: ", j+1);
			scanf("%d", &vecTipos[i].pasos[j]);
			if(vecTipos[i].pasos[j] <= 0){
				break;
			}
		}
		
	}

	return ;
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

/*
void run(areaDoc* *area){
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

		addDato(&*area[0][posArea-1], &*area[1][posArea-1], myDato);

	}

	for(i = 0; i < 5; i++){
		aux = area[0][i];
		while(aux != NULL){
			printf("%d ", aux->dato);
			aux = aux->sig;
		}
		printf("\n");
	}
}*/
