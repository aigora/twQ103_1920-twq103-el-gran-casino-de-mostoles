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
struct maquina{
	int v1[5];
	int v2[5];
	int v3[5];
	int v4[5];
	int v5[5];
	
};
struct palabras{
	char p1;
	char p2;
	char p3;
	char p4;
	char p5;
};
struct contador{
	int z;
	int t;
	int l;
	int b;
	int c;
	int m;
	int s;
	int x;
	int X;
};
typedef struct cartas{
	int numero,numero2,numero3,numeroaux,total;
}cartas;
int GenerarCartas(cartas cartasjugador);
void TablaPremios();
void IntroduccionT();
void IntroduccionB();

//Menu para trabajo informatica de Arturo Cañizares, Eduardo Gonzalez y Raul de Pablo
int main(){
	float apuesta;
	int final,edad,juego,infoT=0,infoB=0,lineas;
	float dineroretirado,dineroingresado;
	int retirar,ingresar,tabla;
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
			
			break;
		}

	printf("Tienes %0.2f euros\n",usuario[k].dinero);
	printf("Si quieres ingresar saldo introduzca 1 o cualquier otro numero si no:\n");
	scanf("%d",&ingresar);
	if(ingresar==1){
			printf("Introduzca la cantidad que desea ingresar:\n");
			scanf("%f",&dineroingresado);
			usuario[k].dinero=usuario[k].dinero+dineroingresado;
	}
	else{
		printf("Has decidido no ingresar dinero,buena suerte\n");
	}
	do{
	
		printf("< 1 para BlackJack, 2 para tragaperras>:\n\n\n\n\n");
		scanf("%d",&juego);
		switch(juego){
	
			case 1:
				if(infoB==0){
					IntroduccionB();
				}
				printf("Tienes %0.2f euros\n",usuario[k].dinero);
				do{	
					printf("Haz una apuesta\n");
					scanf("%f",&apuesta);
					if(apuesta>usuario[k].dinero){
						printf("No tienes dinero\n");
					}			
				}while(apuesta>usuario[k].dinero);
	
				printf("Apuesta aceptada");
				system("cls");
			
				cartas cartasjugador;
				cartas cartascrupier;
				cartasjugador.total=0;
				cartasjugador.numeroaux=0;
				cartascrupier.total=0;
				cartascrupier.numeroaux=0;
			
				
				srand(time(NULL));//Esto sirve para poder producir un numero aleatorio, usa la hora de tu pc para generar un número,
				//como nunca es la misma hora exactamente,siempre te generara un numero diferente
				int total=0,final=0,totalcrup=0;
		//		while(final!=1)
				printf("Cartas de jugador:\n");
				cartasjugador.numero=(rand()%12)+1;//Produce un numero aleatorio del 0 al 13 ,como se le suma uno, produce un numero aleatorio del 1 al 13
				if(cartasjugador.numero>10){
					cartasjugador.numero=10; //es del 1 al 13 porque en la baraja la J la Q y la K valen 10
				}
				if(cartasjugador.numero==1){
					cartasjugador.numero=11;
				}
				printf("%d\n",cartasjugador.numero);
				cartasjugador.total=cartasjugador.total+cartasjugador.numero;
			    cartasjugador.numero2=(rand()%12)+1;
			    if(cartasjugador.numero2>10){
				 	cartasjugador.numero2=10; //es del 1 al 13 porque en la baraja la J la Q y la K valen 10
				}
				if(cartasjugador.numero2==1){
				 		cartasjugador.numero2=11;
				}
			    printf("%d\n",cartasjugador.numero2);
			    	
			    if((cartasjugador.numero==11)&&(cartasjugador.numero2==11)){
			    	
			    	cartasjugador.numero2=1;
				}
				cartasjugador.total=cartasjugador.total+cartasjugador.numero2;
			   // }
			    printf("El total es:%d\n",cartasjugador.total);
			    if((cartasjugador.numero==11&&cartasjugador.numero2==10)||(cartasjugador.numero==10&&cartasjugador.numero2==11)){
			    	printf("Felicidades, has obtenido BlackJack");
			    	usuario[k].dinero=usuario[k].dinero+(apuesta*1.5);
			    	printf("Tu dinero es :%0.2f\n",usuario[k].dinero);
			    	goto repeticion;
				}
			    			
				printf("Cartas de crupier:\n");
				cartascrupier.numero=(rand()%12)+1;
				if(cartascrupier.numero>10){
				 	cartascrupier.numero=10 ;//es del 1 al 13 porque en la baraja la J la Q y la K valen 10
				}
				if(cartascrupier.numero==1){
					cartascrupier.numero=11;
				}
				printf("%d\n",cartascrupier.numero);
				cartascrupier.total=cartascrupier.total+cartascrupier.numero;
			   // if (cartascrupier.total<=11){
			    cartascrupier.numero2=(rand()%12)+1;
			    if(cartascrupier.numero2>10){
				 	cartascrupier.numero2=10 ;//es del 1 al 13 porque en la baraja la J la Q y la K valen 10
				}
				if(cartascrupier.numero2==1){
					cartascrupier.numero2=11;
				}

			    cartascrupier.total=cartascrupier.total+cartascrupier.numero2;
			    
			   
			    
				printf("-----------------------------------------\n");
				do{
					apuesta:
						printf("Quieres otra carta <1 si quieres carta,0 si no quieres, y 2 si te quieres doblar>:");
						scanf("%d",&a);
						if(a<0||a>2){
							printf("Numero incorrecto\n");
						}
				}while(a<0||a>2);
					while (a==1){	
					
						cartasjugador.total=GenerarCartas(cartasjugador);
				  		printf("El total es :%d\n",cartasjugador.total);
				  		if (cartasjugador.total>21){
				    		printf("Lo siento has superado 21, por lo tanto has perdido\n");
				    	usuario[k].dinero=usuario[k].dinero-apuesta;
				    		break;
						}
				  		printf("<1 si quieres otra carta , 0 si no quieres otra carta>:");
				  		scanf("%d",&a);
					}
					if (a==2){
						if(apuesta*2>usuario[k].dinero){
							printf("No tienes dinero para doblarte\n");
							goto apuesta;
						}
						cartasjugador.total=GenerarCartas(cartasjugador);
				  		printf("El total es :%d\n",cartasjugador.total);
				  		apuesta=apuesta*2;
					}
				 	if (cartasjugador.total>21&&a==2){
				   		printf("Lo siento has superado 21, por lo tanto has perdido\n");
				    	usuario[k].dinero=usuario[k].dinero-apuesta;
					}
				if(cartasjugador.total<=21){
					printf("Turno del crupier\n");
					printf("La segunda carta del crupier es:%d\n",cartascrupier.numero2);
					if(cartascrupier.total==21){
						printf("El crupier ha sacado BlackJack\n");
						usuario[k].dinero=usuario[k].dinero-apuesta;
						goto repeticion;
					}
					if(cartascrupier.total>21){
						cartascrupier.numero=1;
						cartascrupier.total=cartascrupier.numero+cartascrupier.numero2;
					}
					
					if (cartascrupier.total<17){
						while (cartascrupier.total<17){
				  			cartascrupier.total=GenerarCartas(cartascrupier);
				 			printf("El total del crupier es :%d\n",cartascrupier.total);
						}
					} else {
						printf("El total del crupier es :%d\n",cartascrupier.total);
					}
		
		
					if (cartasjugador.total>cartascrupier.total||cartascrupier.total>21){
						usuario[k].dinero=usuario[k].dinero-apuesta+(apuesta*2.0);
						printf("Felicidades has ganado al crupier\n");
					}
					else if (cartasjugador.total<cartascrupier.total||cartasjugador.total>21){
						usuario[k].dinero=usuario[k].dinero-apuesta;
						printf("Lo siento, has perdido\n");
					}
					else if (cartasjugador.total==cartascrupier.total){
						printf("Habeis empatado\n");
					}
					printf("Tu dinero es :%0.2f\n",usuario[k].dinero);
					infoB++;
				}	
			break;
			
			case 2:
				if(infoT==0){
					IntroduccionT();
				}
				srand(time(NULL));
				struct maquina maquina;
				struct palabras palabra[5];
				struct contador ganan[5];
				int w,p=0;
				int ganancia=0;
				int contador=0;
				int aux;
			
			
				
				for(w=0;w<5;w++){
					maquina.v1[w]=(rand()%199)+1;
					maquina.v2[w]=(rand()%199)+1;
					maquina.v3[w]=(rand()%199)+1;
					maquina.v4[w]=(rand()%199)+1;
					maquina.v5[w]=(rand()%199)+1;
				}
				
				p=0;
				for(w=0;w<5;w++){
					ganan[p].m=0;
					ganan[p].b=0;
					ganan[p].s=0;
					ganan[p].l=0;
					ganan[p].c=0;
					ganan[p].z=0;
					ganan[p].t=0;
					ganan[p].x=0;
					ganan[p].X=0;
					if(maquina.v1[w]>0&&maquina.v1[w]<41){
						palabra[p].p1='M';
						ganan[p].m++;
						fflush(stdin);
					}
					if(maquina.v1[w]>=41&&maquina.v1[w]<=80){
						palabra[p].p1='S';
						ganan[p].s++;
						fflush(stdin);
					}
					if(maquina.v1[w]>80&&maquina.v1[w]<=110){
						palabra[p].p1='L';
						ganan[p].l++;
						fflush(stdin);
					}
					if(maquina.v1[w]>110&&maquina.v1[w]<=140){
						palabra[p].p1='C';
						ganan[p].c++;
						fflush(stdin);
					}
					if(maquina.v1[w]>140&&maquina.v1[w]<=155){
						palabra[p].p1='Z';
						ganan[p].z++;
						fflush(stdin);
					}
					if(maquina.v1[w]>155&&maquina.v1[w]<=170){
						palabra[p].p1='T';
						ganan[p].t++;
						fflush(stdin);
					}
					if(maquina.v1[w]>170&&maquina.v1[w]<=185){
						palabra[p].p1='B';
						ganan[p].b++;
						fflush(stdin);
					}
					if(maquina.v1[w]>185&&maquina.v1[w]<=195){
						palabra[p].p1='x';
						ganan[p].x++;
						fflush(stdin);
					}
					if(maquina.v1[w]>195){
						palabra[p].p1='X';
						ganan[p].X++;
						fflush(stdin);
					}
					if(maquina.v2[w]>0&&maquina.v2[w]<41){
						palabra[p].p2='M';
						ganan[p].m++;
						fflush(stdin);
					}
					if(maquina.v2[w]>=41&&maquina.v2[w]<=80){
						palabra[p].p2='S';
						ganan[p].s++;
						fflush(stdin);
					}
					if(maquina.v2[w]>80&&maquina.v2[w]<=110){
						palabra[p].p2='L';
						ganan[p].l++;
						fflush(stdin);
					}
					if(maquina.v2[w]>110&&maquina.v2[w]<=140){
						palabra[p].p2='C';
						ganan[p].c++;
						fflush(stdin);
					}
					if(maquina.v2[w]>140&&maquina.v2[w]<=155){
						palabra[p].p2='Z';
						ganan[p].z++;
						fflush(stdin);
					}
					if(maquina.v2[w]>155&&maquina.v2[w]<=170){
						palabra[p].p2='T';
						ganan[p].t++;
						fflush(stdin);
					}
					if(maquina.v2[w]>170&&maquina.v2[w]<=185){
						palabra[p].p2='B';
						ganan[p].b++;
						fflush(stdin);
					}
					if(maquina.v2[w]>185&&maquina.v2[w]<=195){
						palabra[p].p2='x';
						ganan[p].x++;
						fflush(stdin);
					}
					if(maquina.v2[w]>195){
						palabra[p].p2='X';
						ganan[p].X++;
						fflush(stdin);
					}
					if(maquina.v3[w]>0&&maquina.v3[w]<41){
						palabra[p].p3='M';
						ganan[p].m++;
						fflush(stdin);
					}
					if(maquina.v3[w]>=41&&maquina.v3[w]<=80){
						palabra[p].p3='S';
						ganan[p].s++;
						fflush(stdin);
					}
					if(maquina.v3[w]>80&&maquina.v3[w]<=110){
						palabra[p].p3='L';
						ganan[p].l++;
						fflush(stdin);
					}
					if(maquina.v3[w]>110&&maquina.v3[w]<=140){
						palabra[p].p3='C';
						ganan[p].c++;
						fflush(stdin);
					}
					if(maquina.v3[w]>140&&maquina.v3[w]<=155){
						palabra[p].p3='Z';
						ganan[p].z++;
						fflush(stdin);
					}
					if(maquina.v3[w]>155&&maquina.v3[w]<=170){
						palabra[p].p3='T';
						ganan[p].t++;
						fflush(stdin);
					}
					if(maquina.v3[w]>170&&maquina.v3[w]<=185){
						palabra[p].p3='B';
						ganan[p].b++;
						fflush(stdin);
					}
					if(maquina.v3[w]>185&&maquina.v3[w]<=195){
						palabra[p].p3='x';
						ganan[p].x++;
						fflush(stdin);
					}
					if(maquina.v3[w]>195){
						palabra[p].p3='X';
						ganan[p].X++;
						fflush(stdin);
					}
					if(maquina.v4[w]>0&&maquina.v4[w]<41){
						palabra[p].p4='M';
						ganan[p].m++;
						fflush(stdin);
					}
					if(maquina.v4[w]>=41&&maquina.v4[w]<=80){
						palabra[p].p4='S';
						ganan[p].s++;
						fflush(stdin);
					}
					if(maquina.v4[w]>80&&maquina.v4[w]<=110){
						palabra[p].p4='L';
						ganan[p].l++;
						fflush(stdin);
					}
					if(maquina.v4[w]>110&&maquina.v4[w]<=140){
						palabra[p].p4='C';
						ganan[p].c++;
						fflush(stdin);
					}
					if(maquina.v4[w]>140&&maquina.v4[w]<=155){
						palabra[p].p4='Z';
						ganan[p].z++;
						fflush(stdin);
					}
					if(maquina.v4[w]>155&&maquina.v4[w]<=170){
						palabra[p].p4='T';
						ganan[p].t++;
						fflush(stdin);
					}
					if(maquina.v4[w]>170&&maquina.v4[w]<=185){
						palabra[p].p4='B';
						ganan[p].b++;
						fflush(stdin);
					}
					if(maquina.v4[w]>185&&maquina.v4[w]<=195){
						palabra[p].p4='x';
						ganan[p].x++;
						fflush(stdin);
					}
					if(maquina.v4[w]>195){
						palabra[p].p4='X';
						ganan[p].X++;
						fflush(stdin);
					}
					if(maquina.v5[w]>0&&maquina.v5[w]<41){
						palabra[p].p5='M';
						ganan[p].m++;
						fflush(stdin);
					}
					if(maquina.v5[w]>=41&&maquina.v5[w]<=80){
						palabra[p].p5='S';
						ganan[p].s++;
						fflush(stdin);
					}
					if(maquina.v5[w]>80&&maquina.v5[w]<=110){
						palabra[p].p5='L';
						ganan[p].l++;
						fflush(stdin);
					}
					if(maquina.v5[w]>110&&maquina.v5[w]<=140){
						palabra[p].p5='C';
						ganan[p].c++;
						fflush(stdin);
					}
					if(maquina.v5[w]>140&&maquina.v5[w]<=155){
						palabra[p].p5='Z';
						ganan[p].z++;
						fflush(stdin);
					}
					if(maquina.v5[w]>155&&maquina.v5[w]<=170){
						palabra[p].p5='T';
						ganan[p].t++;
						fflush(stdin);
					}
					if(maquina.v5[w]>170&&maquina.v5[w]<=185){
						palabra[p].p5='B';
						ganan[p].b++;
						fflush(stdin);
					}
					if(maquina.v5[w]>185&&maquina.v5[w]<=195){
						palabra[p].p5='x';
						ganan[p].x++;
						fflush(stdin);
					}
					if(maquina.v5[w]>195){
						palabra[p].p5='X';
						ganan[p].X++;
						fflush(stdin);
					}
					p++;
				}
				do{
					printf("Por favor introduzca el numero de lineas con las que desea jugar:");
					scanf("%d",&lineas);
					if(lineas<1&&lineas>3){
						printf("Hay de 1 a 3 lineas\n");
					}
				}while(lineas<1&&lineas>3);
				for(w=0;w<3;w++){
					printf("%c	%c	%c	%c	%c\n",palabra[w].p1,palabra[w].p2,palabra[w].p3,palabra[w].p4,palabra[w].p5);
					fflush(stdin);
				}
				system("pause");
				if(lineas==1){
					for(w=0;w<1;w++){	
						aux=usuario[k].dinero;
						if(ganan[w].m==3||ganan[w].s==3){
							ganancia=3.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==4||ganan[w].s==4){
							ganancia=10.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==5||ganan[w].s==5){
							ganancia=60.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==3||ganan[w].c==3){
							ganancia=20.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==4||ganan[w].c==4){
							ganancia=50.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==5||ganan[w].c==5){
							ganancia=150.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==3||ganan[w].t==3){
							ganancia=+30.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==4||ganan[w].t==4){
							ganancia=200.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==5||ganan[w].t==5){
							ganancia=600.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==3){
							ganancia=60;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==4){
							ganancia=600;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==5){
							ganancia=3000;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else{
							usuario[k].dinero=usuario[k].dinero-2;
						}
						if(ganan[w].x==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						if(ganan[w].X==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+2*ganancia;
						}		
					}
				}
				if(lineas==2){
					for(w=0;w<2;w++){		
						aux=usuario[k].dinero;
						if(ganan[w].m==3||ganan[w].s==3){
							ganancia=3.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==4||ganan[w].s==4){
							ganancia=10.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==5||ganan[w].s==5){
							ganancia=60.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==3||ganan[w].c==3){
							ganancia=20.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==4||ganan[w].c==4){
							ganancia=50.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==5||ganan[w].c==5){
							ganancia=150.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==3||ganan[w].t==3){
							ganancia=+30.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==4||ganan[w].t==4){
							ganancia=200.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==5||ganan[w].t==5){
							ganancia=600.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==3){
							ganancia=60;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==4){
							ganancia=600;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==5){
							ganancia=3000;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else{
							usuario[k].dinero=usuario[k].dinero-2;
						}
						if(ganan[w].x==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						if(ganan[w].X==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+2*ganancia;
						}		
					}
				}
				if(lineas==3){
					for(w=0;w<3;w++){
						aux=usuario[k].dinero;
						if(ganan[w].m==3||ganan[w].s==3){
							ganancia=3.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==4||ganan[w].s==4){
							ganancia=10.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].m==5||ganan[w].s==5){
							ganancia=60.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==3||ganan[w].c==3){
							ganancia=20.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==4||ganan[w].c==4){
							ganancia=50.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].l==5||ganan[w].c==5){
							ganancia=150.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==3||ganan[w].t==3){
							ganancia=+30.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==4||ganan[w].t==4){
							ganancia=200.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].z==5||ganan[w].t==5){
							ganancia=600.0;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==3){
							ganancia=60;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==4){
							ganancia=600;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else if(ganan[w].b==5){
							ganancia=3000;
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						else{
							usuario[k].dinero=usuario[k].dinero-2;
						}
						if(ganan[w].x==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+ganancia;
						}
						if(ganan[w].X==1&&usuario[k].dinero!=aux-2){
							usuario[k].dinero=usuario[k].dinero+2*ganancia;
						}
					}
				}
				if(usuario[k].dinero<aux){
					printf("Lo siento has perdido\n");
					printf("Tu saldo es de %0.2f\n",usuario[k].dinero);
				}
				else{
					printf("Felicidades, has ganado\n");
					printf("Tu saldo es de %0.2f\n",usuario[k].dinero);
				}
				infoT++;
			break;
		}
		repeticion:
		printf("Si quieres volver a jugar introduce cualquier numero distinto de 0, si quieres finalizar la partida, introduce 0:");
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
					printf("Operacion realizada con exito\n");
					break;
				default:
					return 0;}
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
	printf("Hasta pronto");
}


int GenerarCartas(cartas cartasjugador){
	cartasjugador.numero3=(rand()%12)+1;
	if(cartasjugador.numero3>10){
		cartasjugador.numero3=10 ;//es del 1 al 13 porque en la baraja la J la Q y la K valen 10
	}
	if(cartasjugador.numero3==1){
		cartasjugador.numero3=11;
		cartasjugador.numeroaux=cartasjugador.numero3;
		cartasjugador.total=cartasjugador.total+cartasjugador.numeroaux;
	}else{
		cartasjugador.total=cartasjugador.total+cartasjugador.numero3+cartasjugador.numeroaux;
	}
	printf("La siguiente carta es %d\n",cartasjugador.numero3);
	if(cartasjugador.total>21&&(cartasjugador.numero==11||cartasjugador.numero2==11||cartasjugador.numeroaux==11)){
		if(cartasjugador.numero==11){
			cartasjugador.numero=1;
			cartasjugador.total=cartasjugador.total-10;
		}	
		else if(cartasjugador.numero2==11){
			cartasjugador.numero2=1;
			cartasjugador.total=cartasjugador.total-10;
		}
		else if(cartasjugador.numeroaux==11){
			cartasjugador.numeroaux=1;
			cartasjugador.total=cartasjugador.total-10;
		}
	}
	return cartasjugador.total;
}
void TablaPremios(){
	system("cls");
	printf("   -----------------                             -----------------                            \n");
	printf("   |  Cerezas(Z):  |                             |   Sietes(T):  |             \n");
	printf("   | 5x--600 euros |                             | 5x--600 euros |                   \n");
	printf("   | 4x--200 euros |                             | 5x--200 euros |          \n");
	printf("   | 3x--30 euros  |                             | 5x--30 euros  |            \n");
	printf("   -----------------      -----------------      -----------------                     \n");
	printf("                          | Botellines(B):|                                          \n");
	printf(" -----------------        | 5x--3000 euros|          ----------------- \n");
	printf(" |  Limones(L):  |        | 4x--600 euros |          |   Coronas(C): |            \n");
	printf(" | 5x--150 euros |        | 3x--60 euros  |          | 5x--150 euros |                  \n");
	printf(" | 4x--50  euros |        -----------------          | 4x--50 euros  |                  \n");
	printf(" | 3x--20  euros |                                   | 3x--20 euros  |                    \n");
	printf(" -----------------                                   -----------------                         \n");
	printf("           -----------------               ---------------- \n");
	printf("           |  Manzanas(M): |               |   Sandias(S):|\n");
	printf("           | 5x--60  euros |               | 5x--60  euros| \n");
	printf("           | 4x--10  euros |               | 4x--10  euros| \n");
	printf("           | 3x--3   euros |               | 3x--3   euros| \n");
	printf("           -----------------               ----------------\n");
	printf(" Si en tu linea ganadora hay una x, tu premio se multiplicara x2\n");
	printf(" Si en tu linea ganadora hay una X, tu premio se multiplicara x3\n");
	
}
void IntroduccionT(){
	int tabla;
	printf("Bienvenido a las tragaperras\n");
	printf("Nuestras maquinas cuentan con tres lineas de apuesta con 5 elementos en cada una\n");
	printf("El juego consiste en conseguir tres elementos iguales\n");
	printf("El precio de las tiradas depende de con cuantas lineas quieres jugar\n");
	printf("Si no consigues ninguna combinacion correcta perderas 2 euros por cada linea en la que apuestes\n");
	printf("Si quiere ver la tabla de premios pulse 1,si no quiere, pulse cualquier otro numero:");
	scanf("%d",&tabla);
	if(tabla==1){
		TablaPremios();
	}
	printf("Buena suerte\n");
	system("pause");
}
void IntroduccionB(){
	printf("Bienvenido al BlackJack\n");
	printf("Puede jugar en cualquiera de las mesas disponibles\n");
	printf("El juego consiste en sacar mayor valor de cartas que el crupier,sinedo el maximo 21\n");
	printf("Ambos tendreis dos cartas al principio,pero tu puedes pedir todas las que quieras\n");
	printf("Ten cuidado, si te pasas de 21, perderas automaticamente tu apuesta\n");
	printf("Puedes apostar lo que quieras; si ganas al crupier obtendras el doble de lo que hayas apostado\n");
	printf("Sacar un 21 en tus dos cartas iniciales significara BlackJack y ganaras mas dinero\n");
	printf("Existe una opcion de doblar tu apuesta a la hora de pedir cartas, pero solo podras pedir una unica carta\n");
	printf("El as tiene un valor de 1 o 11, dependiendo de tus demas cartas\n");
	printf("Buena suerte\n");
	system("pause");
}
