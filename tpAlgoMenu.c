#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct areaDoc {
    int dato;
    struct areaDoc *ant;
    struct areaDoc *sig;
};

struct tipos {
    int activo;
    int pasos[5];
    int cantidadDoc;
};

struct Documento{
    int tipo;
    int id;
    int recorrido[2][5];
    time_t tiempoInicio, tiempoMov;
    double duracion;
    
};

typedef struct areaDoc areaDoc;
typedef struct tipos tipos;

int cantidadTipos;
int cantidadDocumentos;
tipos vecTipos[1];

void addDato(areaDoc**, areaDoc**, int);
void agregarTiposNuevos(tipos*);
void agregarCantidadDeDocumentos(tipos*);
void cerearVecTipos(tipos*);
void run(tipos*, areaDoc* area[][5]);
void ImprimirReporte(areaDoc**);

int main() {

    srand(time(NULL));

    int modificacion;
    int comenzarPrograma = 1;
    int yaSimulada = 0;
    int simulacion;
    int procesoModificacion;

    areaDoc * area[2][5] = {
        {NULL, NULL, NULL, NULL, NULL},
        {NULL, NULL, NULL, NULL, NULL}
    };


    while (comenzarPrograma != 0) {
        printf("\nDESEA COMENZAR EL PROGRAMA?\n1) COMENZAR\n0) SALIR\nRespuesta: ");
        scanf("%d", &comenzarPrograma);

        if (comenzarPrograma) {
            printf("\n1. SIMULACION NUEVA\n2. SIMULACION ANTERIOR\nRespuesta: ");
            scanf("%d", &simulacion);

            if (simulacion == 1) {

                yaSimulada = 1;

                printf("\nCANTIDAD DE TIPOS: ");
                scanf("%d", &cantidadTipos);
                tipos vecTipos[cantidadTipos];

                agregarTiposNuevos(vecTipos);

                agregarCantidadDeDocumentos(vecTipos);

                run(vecTipos, area);
                
            } else if (simulacion == 2) {

                if (yaSimulada == 1) {

                    printf("\nDESEA HACER MODIFICACIONES?\n 0) NO MODIFICAR\n 1) MODIFICAR\nRespuesta: ");
                    scanf("%d", &modificacion);

                    if (modificacion) {

                        printf("\nDESEA ELIMINAR? \n(Observacion: 0-NO, 1-SI)\nRespuesta: ");
                        scanf("%d", &procesoModificacion);
                        if (procesoModificacion) {
                            //eliminar();
                        }
                        printf("\nDESEA AGREGAR? \n(Observacion: 0-NO, 1-SI)\nRespuesta: ");
                        scanf("%d", &procesoModificacion);
                        if (procesoModificacion) {
                            //agregar();
                        }

                        //run();
                    } else {
                        //run();
                    }

                } else {
                    printf("NO SE HIZO NI UNA SIMULACION ANTES :(\n");
                }

            } else {
                printf("ELEGIR UNA OPCION VALIDA..\n");
            }

        } else {
            printf("HASTA LA PROXIMA\n");
        }

    }

    return 0;
}

void agregarTiposNuevos(tipos vecTipos[]) {
    int verificadorDePasoDeArea[5];
    int i, j;
    int auxPaso;

    // TIPO
    for (i = 0; i < cantidadTipos; i++) {
        verificadorDePasoDeArea[0] = 0;
        verificadorDePasoDeArea[1] = 0;
        verificadorDePasoDeArea[2] = 0;
        verificadorDePasoDeArea[3] = 0;
        verificadorDePasoDeArea[4] = 0;
        vecTipos[i].activo = 1;

        // AREAS
        printf("INGRESE LAS AREAS POR LA QUE PASARA EL TIPO %d: \n(Observacion: Colocar 0 para finalizar)\n", i + 1);
        for (j = 0; j < 5; j++) {
            do {
                printf("SU PASO %d SERA: ", j + 1);
                scanf("%d", &auxPaso);
                if (auxPaso == 0) {
                    break;
                }

            } while (auxPaso < 0 || auxPaso >= 6 || verificadorDePasoDeArea[auxPaso - 1] == 1);

            if (auxPaso > 0 && auxPaso < 6) {
                vecTipos[i].pasos[j] = auxPaso;
                verificadorDePasoDeArea[auxPaso - 1] = 1;
            }

            if (auxPaso == 0) {
                break;
            }

        }

    }

    return;
}

void agregarCantidadDeDocumentos(tipos vecTipos[]) {
    int i, cantidadDefinida, agregarManualmente, auxCantidadDocumentoTipo;
    printf("\nLA CANTIDAD DE DOCUMENTOS YA ESTA DEFINIDA? (Observacion: 1-SI, 0-NO-Random)\nRespuesta: ");
    scanf("%d", &cantidadDefinida);
    if (cantidadDefinida) {
        printf("LA CANTIDAD DE DOCUMENTOS ES: ");
        scanf("%d", &cantidadDocumentos);
    } else {
        cantidadDocumentos = 100 + rand() % 100;
    }

    int auxCantidadDocumentos = cantidadDocumentos;
    printf("DESEA AGREGAR MANUALMENTE LAS CANTIDADES POR TIPO? (Observacion: 1-SI, 0-NO-Random)\nRespuesta: ");
    scanf("%d", &agregarManualmente);
    if (agregarManualmente) {
        while (auxCantidadDocumentos) {
            cerearVecTipos(vecTipos);
            auxCantidadDocumentos = cantidadDocumentos;
            for (i = 0; i < cantidadTipos; i++) {
                printf("LE SOBRA %d\n", auxCantidadDocumentos);

                printf("CUANTOS DOCUMENTOS TIENE EL TIPO %d? ", i + 1);
                scanf("%d", &auxCantidadDocumentoTipo);
                while (auxCantidadDocumentoTipo > auxCantidadDocumentos || auxCantidadDocumentoTipo < 0) {
                    printf("AGREGUE CORRECTAMENTE POR FAVOR\n");
                    printf("CUANTOS DOCUMENTOS TIENE EL TIPO %d? ", i + 1);
                    scanf("%d", &auxCantidadDocumentoTipo);
                }
                vecTipos[i].cantidadDoc = auxCantidadDocumentoTipo;

                auxCantidadDocumentos -= vecTipos[i].cantidadDoc;
                if (auxCantidadDocumentos == 0) {
                    printf("YA SELECCIONO TODO! NO SOBRA MAS :)\n");
                    break;
                }
            }
            if (auxCantidadDocumentos) {
                printf("VUELVA A INGRESAR TODO, NO SE USO LA TOTALIDAD DE DOCUMENTOS DISPONIBLES :(\n");
            }
        }
    } else {
        auxCantidadDocumentos = cantidadDocumentos;
        cerearVecTipos(vecTipos);
        for (i = 0; i < cantidadTipos - 1; i++) {
            printf("LE SOBRA %d\n", auxCantidadDocumentos);
            auxCantidadDocumentoTipo = rand() % auxCantidadDocumentos;
            printf("SE ELIGIO PARA EL TIPO %d UNA CANTIDAD DE %d\n", i + 1, auxCantidadDocumentoTipo);
            auxCantidadDocumentos -= auxCantidadDocumentoTipo;
            vecTipos[i].cantidadDoc = auxCantidadDocumentoTipo;
            if (auxCantidadDocumentos == 0) {
                printf("LE SOBRA %d\n", auxCantidadDocumentos);
                break;
            }
        }
        printf("LE SOBRA %d\n", auxCantidadDocumentos);
        vecTipos[i].cantidadDoc = auxCantidadDocumentos;
        printf("SE ELIGIO PARA EL TIPO %d UNA CANTIDAD DE %d\n", i + 1, auxCantidadDocumentos);
        auxCantidadDocumentos -= auxCantidadDocumentos;
        printf("LE SOBRA %d\n", auxCantidadDocumentos);
        printf("YA SELECCIONO TODO! NO SOBRA MAS :)\n");
    }

    return;
}

void cerearVecTipos(tipos* vecTipos) {
    for (int i = 0; i < cantidadTipos; i++) {
        vecTipos[i].cantidadDoc = 0;
    }
}

void addDato(areaDoc* *area, areaDoc* *ult, int myDato) {

    int i;
    areaDoc* newDoc;

    newDoc = (areaDoc*) malloc(sizeof (areaDoc));

    newDoc->dato = myDato;

    if (*area == NULL) {
        newDoc->ant = NULL;
        newDoc->sig = NULL;
        *area = newDoc;
        *ult = newDoc;
    } else {
        newDoc->ant = *ult;
        newDoc->sig = NULL;
        (*ult)->sig = newDoc;
        *ult = newDoc;
    }
}

void run(tipos vecTipos[], areaDoc* area[][5]) {
    Documento vecTotalDoc[200];
    int i,j;
    int auxTipo;
    for (i = 0; i < cantidadDocumentos; i++) {
        auxTipo = rand() % cantidadTipos;

        while (vecTipos[auxTipo].cantidadDoc == 0) {
            auxTipo = rand() % cantidadTipos;
        }
        vecTotalDoc[i].tipo = auxTipo + 1;
        vecTotalDoc[i].id=i+1;
        for(j=0;j<5;j++){
            vecTotalDoc[i].recorrido[0][j]=vecTipos[vecTotalDoc[i].tipo-1].pasos[j]
            vecTotalDoc[i].recorrido[1][j]=0;       
        }
        vecTipos[auxTipo].cantidadDoc -= 1;

    }

    ////////////////////////EMPIEZA SIMULACION///////////////////////////////////////////////////////////

    int posArea, myDato;
    areaDoc* aux;
    
    time_t HoraMov = time(NULL);
    time_t HoraIni = time(NULL);
    time_t ultimoAgregado = time(NULL);
    
    int tiempoEspera=0;
    int documento=0;
    
    int cam = 0;

    while (difftime(HoraMov, HoraIni) != 97) {
        HoraMov = time(NULL);
        
        if(difftime(HoraMov,ultimoAgregado)==tiempoEspera){
            
            if(documento < cantidadDocumentos){
                addDocumento(&area[0][posArea - 1], &area[1][posArea - 1], vecTotalDoc[documento]);
                documento++;
            }else{
                printf("\nYA SE PROCESARON TODOS LOS DOCUMENTOS :D");
                break;
                
            }
            
            
            ultimoAgregado = time(NULL);
            
            tiempoEspera=random()%5;
            
        }
        
        
           
            



            addDato(&area[0][posArea - 1], &area[1][posArea - 1], myDato);
        


        if (difftime(HoraMov, HoraIni) == cam) {
            for (i = 0; i < 5; i++) {
                ImprimirReporte(&area[0][i]);
            }
            cam=cam+4;
        }

    }




    


}

void ImprimirReporte(areaDoc* *area) {
    while ((*area) != NULL) {
        printf("%d hola", (*area)->dato);
        (*area) = (*area)->sig;
    }
    printf("\n");
}
