#include <stdio.h>
#include <string.h>
#include <windows.h>
struct usuarios{
	char username[100];
	char password[100];
	int contador;
	float dinero;
	int edad;
};
typedef struct cartas{
	int numero,numero2,numero3,numeroaux,total;
}cartas;
//Menu para trabajo informatica de Arturo Cañizares, Eduardo Gonzalez y Raul de Pablo
int main(){
	float apuesta;
	int final,edad,juego;
	float dineroretirado,dineroingresado;
	int retirar,ingresar;

	printf("Bienvenido al Gran Casino de Mostoles \n");
	struct usuarios usuario[500];
	int opcion,nUsuarios=0;
	int repeticion,indicador=0,k,i=0,j=0,a,n=0,s,longitud[200];
	FILE * fichero;
	
	fichero=fopen("Usuarios.txt","r");
	if(fichero==NULL){
		printf("Error\n");
		return 0;
	}
	
	while(fscanf(fichero,"%d %s %s %d %f",&usuario[i].contador,usuario[i].username,usuario[i].password,&usuario[i].edad,&usuario[i].dinero)!=EOF){
		nUsuarios++;
		i++;
	}
	fclose(fichero);
	
	printf("1-Registrarse\n2-Iniciar sesion\n");
	scanf("%d",&opcion);
	fflush(stdin);
	switch(opcion){
		
		case 1:
			printf("Empezaras con 500 euros y si te quedas sin dinero, o ingresas mas o se acaba el juego\nBuena suerte\n");
			usuario[i].contador=i+1;
			printf("Username:");
			fflush(stdin);
			gets(usuario[i].username);
			printf("Contraseña:");
			fflush(stdin);
			gets(usuario[i].password);
			printf("Edad:");
			fflush(stdin);
			scanf("%d",&usuario[i].edad);
				if (usuario[i].edad<18){
					printf("Lo siento eres menor de edad, no puedes entrar al casino");	
					return 0;
				}
			for(a=0;a<nUsuarios;a++){
				for(j=0;j<i;j++){
					if(strcmp(usuario[i].username,usuario[j].username)==0){
						printf("Nombre de usuario ya existente usa otro:");
						fflush(stdin);
						gets(usuario[i].username);		
					}
				}		
			}
				do{
				longitud[i]=strlen(usuario[i].password);
				if((longitud[i]<6)||(longitud[i]>14)){
					printf("Error,la contrasena debe tener entre 6 y 14 caracteres\n");
					printf("Contraseña:");
					fflush(stdin);
					gets(usuario[i].password);
					longitud[i]=strlen(usuario[i].password);
				}
				}while((longitud[i]<6)||(longitud[i]>14));	
				
			fichero=fopen("Usuarios.txt","w");
			usuario[i].dinero=500;
			if(fichero==NULL){
				printf("Error\n");
				return 0;
			}
			for(n=0;n<=i;n++){
				fprintf(fichero,"%d\n %s\n %s\n %d\n %f\n",usuario[n].contador,usuario[n].username,usuario[n].password,usuario[n].edad,usuario[n].dinero);
			}
			fclose(fichero);
			usuario[i].dinero=500;
			k=i;
			
			break;
		case 2:	
		
			do{
				
				printf("Nombre de usuario:");
				fflush(stdin);
				gets(usuario[i].username);
				printf("Contrasenna:");
				fflush(stdin);
				gets(usuario[i].password);
				for(k=0;k<nUsuarios;k++){
					if((strcmp(usuario[i].username,usuario[k].username)==0)&&(strcmp(usuario[i].password,usuario[k].password)==0)){
						indicador++;
						break;
					}		
				}
				if(indicador==0){
					printf("Nombre de usuario o contrasenna incorrecta\n");
				}
			}while(indicador==0);
			printf("Tu saldo es de:%f euros\n",usuario[k].dinero);
			
			break;
		}

	
	printf("Si quieres ingresar saldo introduzca 1 o cualquier otro numero si no:\n");
	scanf("%d",&ingresar);
	switch(ingresar){
		case 1:
			printf("Introduzca la cantidad que desea ingresar:\n");
			scanf("%f",&dineroingresado);
			usuario[k].dinero=usuario[k].dinero+dineroingresado;
			break;
		case 2:
			printf("Has decidido no ingresar dinero,buena suerte\n");
			break;
	}
	do{
	
		printf("< 1 para BlackJack, 2 para tragaperras>:");
		scanf("%d",&juego);
		switch(juego){
			case 1:
				printf("Blackjack:\n");
				break;
			case 2:
				printf("Tragaperras:\n");
				break;
		}
		printf("Si quieres volver a jugar introduce cualquier numero distinto de 0, si quieres finalizar la partida introduce 0:\n");
		scanf("%d",&final);
					if(final==0){
						printf("Si desea retirar el dinero ganado introduce 1, si no introduce cualquier otro numero:\n ");
						scanf("%d",&retirar);
						switch(retirar){
							case 1:
								printf("Introduzca el la cantidad que desea retirar:\n");
								scanf("%f",&dineroretirado);
								while(dineroretirado>usuario[k].dinero){
									printf("No tienes tanto dinero.Introduce de nuevo la cantidad a retirar:\n");
									scanf("%f",&dineroretirado);
								}
								usuario[k].dinero=usuario[k].dinero-dineroretirado;
								break;
							default:
								return 0;
						}
					}
		fichero=fopen("Usuarios.txt","w");
			if(fichero==NULL){
				printf("Error\n");
				return 0;
			}
			if(opcion==1){
				for(s=0;s<=i;s++){
					fprintf(fichero,"%d\n %s\n %s\n %d\n %f\n",usuario[s].contador,usuario[s].username,usuario[s].password,usuario[s].edad,usuario[s].dinero);
				}
			}
			else if(opcion==2){
				for(s=0;s<i;s++){
					fprintf(fichero,"%d\n %s\n %s\n %d\n %f\n",usuario[s].contador,usuario[s].username,usuario[s].password,usuario[s].edad,usuario[s].dinero);
				}	
			}
		
			fclose(fichero);
		}while(final<0||final>0);
}
