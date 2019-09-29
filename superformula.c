//programa elaborado por Brayan Quirino
// 28 de septiembre de 2019
#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<stdbool.h>
int tablas=0;
int campos=0;
int tipo=0;
/*
@param filas numero de filas
@param valTable valor de una fila por tabla
@param valTotal valor total de la bd
@param fp filas por pagina
@param varchar tamaño de un tip varchat
@param variable tipo de dato que el usuario teclea*/
double filas=0;
double valTable=0;
double valTotal=0;
double varchar=0;
double fp=0;
char variable[20];
//Funcion que decide que valor(tamaño) darle a la variable asignada por el usuario.
int acciones(char palabrauno[20]);

int main()
{
	//se pide el numero de tablas
	while(tablas==0){
		printf("¿Cuantas tablas tiene tu BD?\n");
		scanf("%d",&tablas);
		if(tablas==0){
			printf("No existen las tablas empty en este programa\n");
		}
	}
	//For que hace tantos ciclos como numero de tablas
	for (int i=0;i<tablas;i++){
		campos=0;
		//Se pide el numero de campos de la tabla
		while(campos==0){
			printf("¿Cuantos campos tiene la tabla %d?\n", i+1);
			scanf("%d",&campos);
			if(campos==0){
			printf("No existen los campos vacios en este programa\n");
		}
		}
		/*Se piden las filas de la tabla*/
		filas=0;
		while(filas==0){
			printf("¿Cuantas filas tiene esta tabla?\n");
			scanf("%lf", &filas);
			if(filas==0){
				printf("\nNo puede haber 0 filas");
			}
		}
		/*Numero por pagina de cada tabla*/
		fp=0;
		while(fp==0){
			printf("¿Cuantas filas por pagina tiene tu tabla?\n");
			scanf("%lf",&fp);
			if(fp==0){
				printf("No existen 0 filas por pagina\n");
			}
		}
		//For que trabaja tantos campos por tabla hayan
		for(int j=0;j<campos; j++){
			printf("¿Cual es el tipo de variable del campo %d (numeric, text, boolean, etc))\n",j+1);
			scanf("%s", variable);
			acciones(variable);
		}
		//El valor de la bd va aumentando 
		valTotal+=valTable*filas;
		printf("\nEl valor de una fila de la tabla %d es %f\n",i+1,(double)(valTable));
		printf("El valor total de la tabla %d es %f\n",i+1,valTable*filas);
		printf("Numero de paginas %f\n", (float)(filas/fp));
		// Si hay mas filas que el n umero de filas por pagina quiere decir que al menos hay una pagina
		if(filas>fp){
			printf("Tamaño de la pagina en bits %f\n", (float)(valTable*fp));
			printf("Tamaño de la pagina en gigas %f\n",(float) ((valTable*fp)/1000)/1000);
		}
		valTable=0;
	}
	/*printf("Tamaño de la bd en bits %f\n",(float) valTotal);
	printf("Tamaño de la bd en megas %f\n",(float) (valTotal/1000));*/
	printf("Tamaño de la bd en gigas %f\n",(float) (valTotal/1000)/1000);
	return 0;
}

/*Funcion que recibe un string y dependiendo cual sea el caso asgina un valor al campo de la tabla en curso*/
int acciones(char palabrauno[20])
{
	char *ret;
	ret = strstr(palabrauno,"varchar");
	if(strcmp(palabrauno,"integer")==0){
		valTable+=8;
	}
	else if(strcmp(palabrauno,"float")==0){
		valTable+=8;
	}
	else if(strcmp(palabrauno,"double")==0){
		valTable+=8;
	}
	else if(strcmp(palabrauno,"numeric")==0){
		valTable+=8;
	}
	else if(strcmp(palabrauno,"boolean")==0){
		valTable+=1;
	}
	else if(strcmp(palabrauno,"text")==0){
		valTable+=500;
	}
	else if(strcmp(palabrauno,"date")==0){
		valTable+=12;
	/*HACKS BRAYAN*/	
	}else if(strcmp(palabrauno,"n")==0){
		valTable+=8;
	}
	else if(strcmp(palabrauno,"v")==0){
		valTable+=100;
	}
	else if(ret!=NULL){
		while(varchar==0){
			printf("\n¿cuál es el tamaño del varchar?");
			scanf("%d",&varchar);
			if(varchar==0){
				printf("\nNo puede ser de tamaño 0");
			}
		}
		valTable+=varchar;
	}else{
		printf("\nCreo que no entendí lo que dijiste");
		printf("\nIntenta repetir el tipo de dato\n");
		scanf("%s", variable);
		acciones(variable);
	}
    return(0);
}
