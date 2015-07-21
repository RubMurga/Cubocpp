#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define nCuadros 5 //numero de cuadros por cada fila 
struct nodo{
    int iValor;
    int iCara;
    nodo *nAnterior;
    nodo *nSiguiente;
    nodo *nAbajo;
    nodo *nArriba;
    nodo *nAuxi;
    nodo *nAtras;
};
typedef struct operacionesH{
    int iSuma;
    int iResta;
    int iMultiplicacion;
}structOperaciones;

void crearCara(int iCara);
void crearAtras();
void inicializacion(int iCara);
void llenarValores(int iCara);
void cortarLista(int j,int iCara);
void llenarNaBajo(int iLimite,int iCara);
void llenarAnterior(int iCara);
void llenarArriba(int iCara);
void llenarAtras(int iCara);
void visualizar(int iCara);
void desvincularAux(int iCara);
void OperacionesHorizontales(int iCara);
void OperacionesHorizontalesDI(int iCara);
void OperacionesVerticales(structOperaciones *sOperacionesH, int iCara);
void OperacionesVerticalesAA(structOperaciones *sOperacionesH,int iCara);
nodo *inicio1, *ultimo1,*inicio2, *ultimo2,*inicio3, *ultimo3,*inicio4, *ultimo4,*inicio5, *ultimo5,*inicio6, *ultimo6; /*se
utilizan diferentes inicios porque si solo utilizara uno se estaria sobreescrbiendo la cara una y otra vez */

int main(){
    srand(time(NULL));
    crearCara(1); printf("\n"); /*Mete el numero de cara para crearla porque los metodos
    que sirven para una cara funcionan de igual manera para todas las caras.Entonces solamente metemos el nummero de cara que querramos*/
    crearCara(2);printf("\n");
    crearCara(3);printf("\n");
    crearCara(4);printf("\n");
    crearCara(5);printf("\n");
    crearCara(6);printf("\n");
    crearAtras();
};
void crearCara(int iCara){
    inicializacion(iCara);
    int i,j;
    for(i=0; i<=((pow(nCuadros,2.0))-1); i++){ /*porque son ncuadros^2 cuadritos por cara y empieza con cero (:*/
        llenarValores(iCara);
    }
    for(i=0, j=1; i<=((pow(nCuadros,2.0))-1); i++,j++){
        cortarLista(j,iCara); /*esta funcion nos sirve para ir cortando la lista de 5 en 5(cortar las filas)*/
    }
    for(i=0, j=1; i<=((pow(nCuadros,2.0))-1); i++,j++){
        llenarNaBajo(j,iCara); /*Nos sirve para llenar el campo de pAbajo que es el apuntador que esta debajo de cada apuntador*/
    }
    llenarAnterior(iCara);
    llenarArriba(iCara);
    //desvincularAux(iCara);
    //visualizar(iCara); /*esta funcion solo es de prueba para visualizar las caras que hemos creado*/
    OperacionesHorizontales(iCara); /*hace las operaciones horizontales de todas las filas(izquierda a derecha)*/
    OperacionesHorizontalesDI(iCara);
};
void crearAtras(){
    llenarAtras(1);
    llenarAtras(2);
    llenarAtras(3);
    llenarAtras(4);
    llenarAtras(5);
    llenarAtras(6);
};
void inicializacion(int iCara){
    switch(iCara){
        case 1: /*crea el inicio de la esquina superior izquierda*/
            inicio1 = NULL;
            ultimo1 = NULL;
            break;
        case 2:
            inicio2 = NULL;
            ultimo2 = NULL;
            break;
        case 3:
            inicio3 = NULL;
            ultimo3 = NULL;
            break;
        case 4:
            inicio4 = NULL;
            ultimo4 = NULL;
            break;
        case 5:
            inicio5 = NULL;
            ultimo5 = NULL;
            break;
        case 6:
            inicio6 = NULL;
            ultimo6 = NULL;
            break;
    }
};
void llenarValores(int iCara){
    nodo *nuevo;
    nuevo = (nodo*)malloc(sizeof(nodo));
    if(nuevo == NULL){ /*ya no hay memoria para insertar nuevo nodo*/

    }else{
        nuevo -> iValor = rand()%10;
        nuevo -> iCara = iCara;
        nuevo -> nAbajo = NULL;
        nuevo ->nSiguiente= NULL;
        nuevo ->nAnterior=NULL;
        nuevo ->nArriba =NULL;
        nuevo ->nAtras =NULL;
        if(iCara ==1){
            if(inicio1==NULL){ /*si es nulo significa que el nodo que estamos creando es el primero de la lista*/
                inicio1 = nuevo;
                ultimo1 = nuevo; /*entonces este nodo se convierte en el primero y en el ultimo de nuestra lista hasta ahora*/
            }else{
                ultimo1->nSiguiente = nuevo; /*agarra el ultimo apuntador de la lista y lo conecta con el apuntador que acabamos de crear*/
                ultimo1->nAuxi = nuevo; /*auxiliar para cortar la lista*/
                ultimo1 = nuevo; /*Y ahora sobreescribe nuestro apuntador anterior y lo pone en la ultima posicion de la lista*/
            }
        }
        else if(iCara==2){
            if(inicio2==NULL){
                inicio2 = nuevo;
                ultimo2 = nuevo;
            }else{
                ultimo2->nSiguiente = nuevo;
                ultimo2->nAuxi = nuevo;
                ultimo2 = nuevo;
            }
        }
        else if(iCara==3){
            if(inicio3==NULL){
                inicio3 = nuevo;
                ultimo3 = nuevo;
            }else{
                ultimo3->nSiguiente = nuevo;
                ultimo3->nAuxi = nuevo;
                ultimo3 = nuevo;
            }
        }
        else if(iCara==4){
            if(inicio4==NULL){
                inicio4 = nuevo;
                ultimo4 = nuevo;
            }else{
                ultimo4->nSiguiente = nuevo;
                ultimo4->nAuxi = nuevo;
                ultimo4 = nuevo;
            }
        }
        else if(iCara==5){
            if(inicio5==NULL){
                inicio5 = nuevo;
                ultimo5 = nuevo;
            }else{
                ultimo5->nSiguiente = nuevo;
                ultimo5->nAuxi = nuevo;
                ultimo5 = nuevo;
            }
        }
        else if(iCara==6){
            if(inicio6==NULL){
                inicio6 = nuevo;
                ultimo6 = nuevo;
            }else{
                ultimo6->nSiguiente = nuevo;
                ultimo6->nAuxi = nuevo;
                ultimo6 = nuevo;
            }
        }
    }
};
void cortarLista(int j, int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = inicio1;
            break;
        case 2:
            nAux = inicio2;
            break;
        case 3:
            nAux = inicio3;
            break;
        case 4:
            nAux = inicio4;
            break;
        case 5:
            nAux = inicio5;
            break;
        case 6:
            nAux = inicio6;
            break;
    }
    int i=1;
    if(j%nCuadros==0){
        while(nAux!=NULL){ /*cuando j que lo mete desde el for es multiplo de 5 entonces termina una fila y hay que poner NULL el
        ultimo apuntador que sirve para cortar la lista.*/
          if(i==j){
            nAux->nSiguiente =NULL;
            break;
          }
          nAux = nAux->nAuxi;
          i++;
        }
    }
};
void llenarNaBajo(int iLimite, int iCara){
    nodo *nAux, *nAux2;
    switch(iCara){
        case 1:
            nAux = inicio1;
            nAux2 = inicio1;
            break;
        case 2:
            nAux = inicio2;
            nAux2 = inicio2;
            break;
        case 3:
            nAux = inicio3;
            nAux2 = inicio3;
            break;
        case 4:
            nAux = inicio4;
            nAux2 = inicio4;
            break;
        case 5:
            nAux = inicio5;
            nAux2 = inicio5;
            break;
        case 6:
            nAux = inicio6;
            nAux2 = inicio6;
            break;
    }
    int i=1;
    while(nAux!=NULL){
        if(i==iLimite){
            break;
        } /*mueve horizontamlmente el apuntador dependiendo del numero de posiciones que queremos recorrer
        nuestro apuntador*/
        nAux= nAux->nAuxi;
        nAux2= nAux2->nAuxi;
        i++;
    }i=1;
    while(nAux2!=NULL){
        nAux2=nAux2->nAuxi;
        if(i==nCuadros){
            break; /*mueve el segundo apuntador en la fila debajo de la que estamos posicionados y cuando llega a al 5
            significa que estamos justo debajo del que queremos; entonces nos salimos del while y el apuntador que quedo
            sera el que esta debajo al que queremos*/
        }
        i++;
    }
    nAux->nAbajo = nAux2;

};
void llenarAnterior(int iCara){
    nodo *nAux,*nAux2;
    switch(iCara){
        case 1:
            nAux = inicio1;
            nAux2 = inicio1;
            break;
        case 2:
            nAux = inicio2;
            nAux2 = inicio2;
            break;
        case 3:
            nAux = inicio3;
            nAux2 = inicio3;
            break;
        case 4:
            nAux = inicio4;
            nAux2 = inicio4;
            break;
        case 5:
            nAux = inicio5;
            nAux2 = inicio5;
            break;
        case 6:
            nAux = inicio6;
            nAux2 = inicio6;
            break;
    }
    int i=0,j=0;
    while(nAux!=NULL){
        nAux = nAux->nSiguiente;
        if(nAux!=NULL){nAux->nAnterior=nAux2;}
        nAux2=nAux2->nSiguiente;
        if(nAux==NULL){/*si nAux es nulo entonces ya termino la fila*/
            j=0;
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    nAux2 = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    nAux2 = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    nAux2 = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    nAux2 = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    nAux2 = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    nAux2 = inicio6;
                    break;
            }/*se regresa al inicio y con el while se va cambiando de fila, esta bien locote mi programa jajaja*/
            while(nAux!=NULL){
                if(j==i){
                    break;
                }
                nAux = nAux->nAbajo;
                nAux2 = nAux2->nAbajo; /*cuando nAux es nulo cambia de fila, significa que va saltando verticalmente
                hacia el apuntador de abajo, posteriormente empieza a hacer todo de nuevo*/
                j++;
            }
            i++;
        }
    }
};
void llenarArriba(int iCara){
    nodo *nAux,*nAux2;
    switch(iCara){
        case 1:
            nAux = inicio1;
            nAux2 = inicio1;
            break;
        case 2:
            nAux = inicio2;
            nAux2 = inicio2;
            break;
        case 3:
            nAux = inicio3;
            nAux2 = inicio3;
            break;
        case 4:
            nAux = inicio4;
            nAux2 = inicio4;
            break;
        case 5:
            nAux = inicio5;
            nAux2 = inicio5;
            break;
        case 6:
            nAux = inicio6;
            nAux2 = inicio6;
            break;
    }
    int i=0,j=0;
    while(nAux!=NULL){
        nAux = nAux->nAbajo;
        if(nAux!=NULL){nAux->nArriba=nAux2;}
        nAux2=nAux2->nAbajo;
        if(nAux==NULL){/*si nAux es nulo entonces ya termino la fila*/
            j=0;
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    nAux2 = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    nAux2 = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    nAux2 = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    nAux2 = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    nAux2 = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    nAux2 = inicio6;
                    break;
            }/*se regresa al inicio y con el while se va cambiando de fila, esta bien locote mi programa jajaja*/
            while(nAux!=NULL){
                if(j==i){
                    break;
                }
                nAux = nAux->nSiguiente;
                nAux2 = nAux2->nSiguiente; /*cuando nAux es nulo cambia de fila, significa que va saltando verticalmente
                hacia el apuntador de abajo, posteriormente empieza a hacer todo de nuevo*/
                j++;
            }
            i++;
        }
    }
};
void desvincularAux(int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = inicio1;
            break;
        case 2:
            nAux = inicio2;
            break;
        case 3:
            nAux = inicio3;
            break;
        case 4:
            nAux = inicio4;
            break;
        case 5:
            nAux = inicio5;
            break;
        case 6:
            nAux = inicio6;
            break;
    }
    int i=0,j=0;
    while(nAux != NULL){
        nAux->nAuxi=NULL;
        nAux=nAux->nAbajo;/*va moviendo el apuntador verticalemente hasta que llega al final de la columna,
        luego cambia al siguiente*/
        if(nAux == NULL){
            j=0;
            //nAux = inicio;
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    break;
                }
            while(nAux!=NULL){/*este while nos sirve para mover el apuntador horizontalmente, y
                    lo movera j veces horizontalmente*/
                if(j==i){
                    break;
                }
                nAux = nAux->nSiguiente; /*cuando nAux es nulo cambia de fila, el j sirve para saber cuantas veces cambiara de fila*/
                j++;
            }
            i++;
        }
    }
    printf("cara %i desvinculada", iCara);
};
void llenarAtras(int iCara){
    nodo *nAux,*nAux2;
        switch(iCara){
            case 1:
                nAux = inicio1;
                nAux2 = inicio3;
                break;
            case 2:
                nAux = inicio2;
                nAux2 = inicio4;
                break;
            case 3:
                nAux = inicio3;
                nAux2 = inicio1;
                break;
            case 4:
                nAux = inicio4;
                nAux2 = inicio2;
                break;
            case 5:
                nAux = inicio5;
                nAux2 = inicio6;
                break;
            case 6:
                nAux = inicio6;
                nAux2 = inicio5;
                break;
        }
        int i=0,j=0;
        while(nAux!=NULL){
            nAux->nAtras=nAux2;
            nAux = nAux->nSiguiente;
            nAux2= nAux2->nSiguiente;
            if(nAux==NULL){/*si nAux es nulo entonces ya termino la fila*/
                j=0;
                switch(iCara){
                    case 1:
                        nAux = inicio1;
                        nAux2 = inicio3;
                        break;
                    case 2:
                        nAux = inicio2;
                        nAux2 = inicio4;
                        break;
                    case 3:
                        nAux = inicio3;
                        nAux2 = inicio1;
                        break;
                    case 4:
                        nAux = inicio4;
                        nAux2 = inicio2;
                        break;
                    case 5:
                        nAux = inicio5;
                        nAux2 = inicio6;
                        break;
                    case 6:
                        nAux = inicio6;
                        nAux2 = inicio5;
                        break;
                }/*se regresa al inicio y con el while se va cambiando de fila, esta bien locote mi programa jajaja*/
                while(nAux!=NULL){
                    if(j==i){
                        break;
                    }
                    nAux = nAux->nAbajo;
                    nAux2 = nAux2->nAbajo; /*cuando nAux es nulo cambia de fila, significa que va saltando verticalmente
                    hacia el apuntador de abajo, posteriormente empieza a hacer todo de nuevo*/
                    j++;
                }
                i++;
            }
        }
    visualizar(iCara);
    //OperacionesHorizontales(iCara); /*hace las operaciones horizontales de todas las filas(izquierda a derecha)*/
    //OperacionesHorizontalesDI(iCara);
};
void OperacionesHorizontales(int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = inicio1; /*depende de la cara que estemos inicializando para sacar el inicio*/
            break;
        case 2:
            nAux = inicio2;
            break;
        case 3:
            nAux = inicio3;
            break;
        case 4:
            nAux = inicio4;
            break;
        case 5:
            nAux = inicio5;
            break;
        case 6:
            nAux = inicio6;
            break;
    }
    structOperaciones *sOperacionesH;
    sOperacionesH = (structOperaciones*)malloc(10*sizeof(structOperaciones)); /*las operaciones las
    guardara en un arreglo de apuntadores a una estructura que guarda las sumas, restas y multiplicaciones */
    int i=0,j=0, iSuma =0, iMultiplicacion=1, iResta=0; /*la multi es 1 porque 0 por algo es 0, no seas baboso :v*/
    while(nAux!=NULL){
        iSuma+= nAux->iValor;
        iMultiplicacion *= nAux->iValor;
        iResta -= nAux->iValor; /*operaciones faciles jajajaja*/
        nAux=nAux->nSiguiente;/*va moviendo el apuntador horizontalmente*/
        if(nAux==NULL){/*si nAux es nulo entonces ya termino la fila*/
            j=0;
            sOperacionesH[i].iSuma = iSuma;
            sOperacionesH[i].iMultiplicacion = iMultiplicacion;
            sOperacionesH[i].iResta = iResta; /*mete todas las operaciones dependiendo del numero de columna*/
            iSuma=0;iMultiplicacion=1;iResta=0;/*se reinician porque ya acabo la operacion de la fila*/
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    break;
            }/*se regresa al inicio y con el while se va cambiando de fila, esta bien locote mi programa jajaja*/
            while(nAux!=NULL){
                if(j==i){
                    break;
                }
                nAux = nAux->nAbajo; /*cuando nAux es nulo cambia de fila, significa que va saltando verticalmente
                hacia el apuntador de abajo, posteriormente empieza a hacer todo de nuevo*/
                j++;
            }
            i++;
        }
    }
    /*for(i=1; i<6; i++){
        printf("%i| ", sOperacionesH[i].iSuma);Ya quedaron todas las operaciones, las hace bien :v }*/
    OperacionesVerticales(sOperacionesH,iCara);
};
void OperacionesVerticales(structOperaciones *sOperacionesH,int iCara){
    /*Es muy parecido al metodo de operaciones verticales pero cambia en que ahora en vez de cambiar de fila cambia de columna*/
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = inicio1;
            break;
        case 2:
            nAux = inicio2;
            break;
        case 3:
            nAux = inicio3;
            break;
        case 4:
            nAux = inicio4;
            break;
        case 5:
            nAux = inicio5;
            break;
        case 6:
            nAux = inicio6;
            break;
    }
    structOperaciones *sOperacionesV;
    sOperacionesV = (structOperaciones*)malloc(10*sizeof(structOperaciones)); /*las operaciones las
    guardara en un arreglo de apuntadores a una estructura */
    int i=0,j=0, iSuma =0, iMultiplicacion=1, iResta=0;
    while(nAux != NULL){
        iSuma+= nAux->iValor;
        iMultiplicacion *= nAux->iValor;
        iResta -= nAux->iValor;
        nAux=nAux->nAbajo;/*va moviendo el apuntador verticalemente hasta que llega al final de la columna,
        luego cambia al siguiente*/
        if(nAux == NULL){
            j=0;
            sOperacionesV[i].iSuma = iSuma;
            sOperacionesV[i].iMultiplicacion = iMultiplicacion;
            sOperacionesV[i].iResta = iResta;
            iSuma=0;iMultiplicacion=1;iResta=0;/*se reinician porque ya acabo la operacion de la columna*/
            //nAux = inicio;
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    break;
                }
            while(nAux!=NULL){/*este while nos sirve para mover el apuntador horizontalmente, y
                    lo movera j veces horizontalmente*/
                if(j==i){
                    break;
                }
                nAux = nAux->nSiguiente; /*cuando nAux es nulo cambia de fila, el j sirve para saber cuantas veces cambiara de fila*/
                j++;
            }
            i++;
        }
    }
    printf("     Suma vertical resta Horizontal arriba hacia abajo izquierda a derecha\n");
    for(i=1; i<6; i++){
        printf("\t %i| \t %i \n", sOperacionesV[i].iSuma,sOperacionesH[i].iResta); /*solo lo use para ver si si hace bien las operaciones
        para el modo frafico estas lineas estaran comentadas*/
    }
    free(sOperacionesH);
    free(sOperacionesV); /*libera memoria para que no se junten las sumas de las caras anteriores*/
};
void OperacionesHorizontalesDI(int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = ultimo1; /*depende de la cara que estemos inicializando para sacar el inicio*/
            break;
        case 2:
            nAux = ultimo2;
            break;
        case 3:
            nAux = ultimo3;
            break;
        case 4:
            nAux = ultimo4;
            break;
        case 5:
            nAux = ultimo5;
            break;
        case 6:
            nAux = ultimo6;
            break;
    }
    structOperaciones *sOperacionesH;
    sOperacionesH = (structOperaciones*)malloc(10*sizeof(structOperaciones)); /*las operaciones las
    guardara en un arreglo de apuntadores a una estructura que guarda las sumas, restas y multiplicaciones */
    int i=0,j=0, iSuma =0, iMultiplicacion=1, iResta=0;
    while(nAux!=NULL){
        iSuma+= nAux->iValor;
        iMultiplicacion *= nAux->iValor;
        iResta -= nAux->iValor; /*operaciones faciles jajajaja*/
        nAux=nAux->nAnterior;/*va moviendo el apuntador horizontalmente*/
        if(nAux==NULL){/*si nAux es nulo entonces ya termino la fila*/
            j=0;
            sOperacionesH[i].iSuma = iSuma;
            sOperacionesH[i].iMultiplicacion = iMultiplicacion;
            sOperacionesH[i].iResta = iResta; /*mete todas las operaciones dependiendo del numero de columna*/
            iSuma=0;iMultiplicacion=1;iResta=0;/*se reinician porque ya acabo la operacion de la fila*/
            switch(iCara){
                case 1:
                    nAux = ultimo1;
                    break;
                case 2:
                    nAux = ultimo2;
                    break;
                case 3:
                    nAux = ultimo3;
                    break;
                case 4:
                    nAux = ultimo4;
                    break;
                case 5:
                    nAux = ultimo5;
                    break;
                case 6:
                    nAux = ultimo6;
                    break;
            }/*se regresa al inicio y con el while se va cambiando de fila, esta bien locote mi programa jajaja*/
            while(nAux!=NULL){
                if(j==i){
                    break;
                }
                nAux = nAux->nArriba; /*cuando nAux es nulo cambia de fila, significa que va saltando verticalmente
                hacia el apuntador de abajo, posteriormente empieza a hacer todo de nuevo*/
                j++;
            }
            i++;
        }
    }
    /*for(i=1; i<6; i++){
        printf("%i| ", sOperacionesH[i].iSuma);
    }*/
    OperacionesVerticalesAA(sOperacionesH, iCara);
};
void OperacionesVerticalesAA(structOperaciones *sOperacionesH,int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = ultimo1;
            break;
        case 2:
            nAux = ultimo2;
            break;
        case 3:
            nAux = ultimo3;
            break;
        case 4:
            nAux = ultimo4;
            break;
        case 5:
            nAux = ultimo5;
            break;
        case 6:
            nAux = ultimo6;
            break;
    }
    structOperaciones *sOperacionesV;
    sOperacionesV = (structOperaciones*)malloc(10*sizeof(structOperaciones)); /*las operaciones las
    guardara en un arreglo de apuntadores a una estructura */
    int i=0,j=0, iSuma =0, iMultiplicacion=1, iResta=0;
    while(nAux != NULL){
        iSuma+= nAux->iValor;
        iMultiplicacion *= nAux->iValor;
        iResta -= nAux->iValor;
        nAux=nAux->nArriba;/*va moviendo el apuntador verticalemente hasta que llega al final de la columna,
        luego cambia al siguiente*/
        if(nAux == NULL){
            j=0;
            sOperacionesV[i].iSuma = iSuma;
            sOperacionesV[i].iMultiplicacion = iMultiplicacion;
            sOperacionesV[i].iResta = iResta;
            iSuma=0;iMultiplicacion=1;iResta=0;/*se reinician porque ya acabo la operacion de la columna*/
            //nAux = inicio;
            switch(iCara){
                case 1:
                    nAux = ultimo1;
                    break;
                case 2:
                    nAux = ultimo2;
                    break;
                case 3:
                    nAux = ultimo3;
                    break;
                case 4:
                    nAux = ultimo4;
                    break;
                case 5:
                    nAux = ultimo5;
                    break;
                case 6:
                    nAux = ultimo6;
                    break;
                }
            while(nAux!=NULL){/*este while nos sirve para mover el apuntador horizontalmente, y
                    lo movera j veces horizontalmente*/
                if(j==i){
                    break;
                }
                nAux = nAux->nAnterior; /*cuando nAux es nulo cambia de fila, el j sirve para saber cuantas veces cambiara de fila*/
                j++;
            }
            i++;
        }
    }
    printf("     Suma vertical resta Horizontal abajo hacia arriba derecha a izquierda\n");
    for(i=1; i<6; i++){
        printf("\t %i| \t %i \n", sOperacionesV[i].iSuma,sOperacionesH[i].iResta); /*solo lo use para ver si si hace bien las operaciones
        para el modo frafico estas lineas estaran comentadas*/
    }
    free(sOperacionesH);
    free(sOperacionesV); /*libera memoria para que no se junten las sumas de las caras anteriores*/
};
void visualizar(int iCara){
    nodo *nAux;
    switch(iCara){
        case 1:
            nAux = inicio1;
            break;
        case 2:
            nAux = inicio2;
            break;
        case 3:
            nAux = inicio3;
            break;
        case 4:
            nAux = inicio4;
            break;
        case 5:
            nAux = inicio5;
            break;
        case 6:
            nAux = inicio6;
            break;
    }
    int i=0,j=0,k=0;
        printf("direccionMemoriaApuntador =MA\ndireccionMemoriaApuntadorDerecha =MAR \ndireccionMemoriaApuntadorIzquierda =MAL\ndireccionMemoriaApuntadorAbajo =MAD\ndireccionMemoriaApuntadorArriba =MAU\ndireccionMemoriaApuntadorAtras = MAB\n");
        printf("                         MA      MAR      MAD     MAL     MAU    MAB\n");

    while(nAux!=NULL){
        printf("cara %i %i valor: %i \t%i\t%i\t%i\t%i\t%i\t%i\n",nAux->iCara, i+1, nAux->iValor, nAux, nAux->nSiguiente, nAux->nAbajo,nAux->nAnterior,nAux->nArriba, nAux->nAtras);
        nAux = nAux->nAuxi;
        i++;
    }
    /*while(nAux != NULL){
        printf("cara %i Posicion %i valor: %i \t%i\t%i\t%i\t\t%i\n",nAux->iCara, k+1, nAux->iValor, nAux, nAux->nSiguiente, nAux->nAbajo, nAux->nAuxi);
        nAux=nAux->nSiguiente;/*va moviendo el apuntador verticalemente hasta que llega al final de la columna,
        luego cambia al siguiente*/
       /* if(nAux == NULL){
            j=0;
            //nAux = inicio;
            switch(iCara){
                case 1:
                    nAux = inicio1;
                    break;
                case 2:
                    nAux = inicio2;
                    break;
                case 3:
                    nAux = inicio3;
                    break;
                case 4:
                    nAux = inicio4;
                    break;
                case 5:
                    nAux = inicio5;
                    break;
                case 6:
                    nAux = inicio6;
                    break;
                }
            while(nAux!=NULL){/*este while nos sirve para mover el apuntador horizontalmente, y
                    lo movera j veces horizontalmente*/
              /*  if(j==i){
                    break;
                }
                nAux = nAux->nAbajo; /*cuando nAux es nulo cambia de fila, el j sirve para saber cuantas veces cambiara de fila*/
             /*   j++;
            }
            i++;
        }
    k++;
    }*/

};
