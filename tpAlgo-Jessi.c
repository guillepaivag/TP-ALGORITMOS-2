void imprimirInforme(documento vecTotalDoc[cantidadDocumentos]) {
    int i, j;
    int contadorPendientes[cantidadTipos];
    int contadorProcesados[cantidadTipos];
    int contadorNoEntro[cantidadTipos];
    for (i = 0; i < cantidadTipos; i++){
        contadorPendientes[i] = 0;
        contadorProcesados[i] = 0;
        contadorNoEntro[i] = 0;
    }
    printf("\n------------------------------------------------------\n");
    printf("\nGENERANDO INFORME");
    printf("\n------------------------------------------------------\n");
    //IMPRIMIR PROCESADAS
    printf("\n------------------------------------------------------\n");
    printf("\nPROCESADAS COMPLETAMENTE: ");


    for (i = 0; i < cantidadDocumentos; i++) {
        if (vecTotalDoc[i].procesado) {
            printf("\n\nNumero de solicitud: |%d|", vecTotalDoc[i].id);
            printf("\nTipo de solicitud: |%d|", vecTotalDoc[i].tipo);
            printf("\nHora de recepcion: |%s|", ctime(&(vecTotalDoc[i].tiempoInicio)));
            printf("\nHora de conclusion: |%s|", ctime(&(vecTotalDoc[i].tiempoFinal)));
            printf("\nDuracion: |%.0lf| segundos\n", difftime(vecTotalDoc[i].tiempoFinal, vecTotalDoc[i].tiempoInicio));
            contadorProcesados[vecTotalDoc[i].tipo - 1]++;
        }else if(vecTotalDoc[i].pendiente){
            contadorPendientes[vecTotalDoc[i].tipo - 1]++;
        }else {
            contadorNoEntro[vecTotalDoc[i].tipo - 1]++;
        }

    }
    printf("\n------------------------------------------------------\n");

    //IMPRIMIR POR AREA
    printf("\n------------------------------------------------------\n");
    for (i = 0; i < 5; i++) {
        
        printf("\nPROCESADAS COMPLETAMENTE EN EL AREA %d : ", i + 1);
        for (j = 0; j < cantidadTipos; j++) {
            printf("\nTIPO: %d",j+1);
            printf("\nCantidad procesadas: |%d|",contadorProcesados[j]);
            printf("\nCantidad pendientes: |%d|",contadorPendientes[j]);
            printf("\nCantidad sin entrar en area: |%d|",contadorNoEntro[j]);
            printf("\n");
        }
        printf("\n------------------------------------------------------\n");
    }
    printf("\n------------------------------------------------------\n");
    return ;
}
