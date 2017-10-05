/*	PROGRAM TUGAS METODE NUMERIK 
	REGRESI LINIER
		3411151066	DIDIN WAHYUDI
		3411151098	FAUZI MAULANA KUSUMA
		SIE-B 2017
*/

#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define nMax 100

int x[nMax+1], y[nMax+1];
int jumx, jumy, i, n;
int sigmax=0, sigmay=0, sigmaxkuadrat=0, sigmaykuadrat=0, sigmaxy=0;
int kuadx[nMax+1], kuady[nMax+1], xy[nMax+1];
float m=0,c,error[nMax+1],yaksen[nMax+1],sigmaerror=0,errorakhir;
   
int main(){
	
  	printf("\n\t=== PROGRAM MENGHITUNG REGRESI LINIER ===\n\n");
  	printf("\t\t=== Created By ===");
  	printf("\n\t3411151066	DIDIN WAHYUDI");
  	printf("\n\t3411151098	FAUZI MAULANA KUSUMA");
  	printf("\n=========================================================");
  	printf ("\n\tINPUT JUMLAH DATA : "); scanf ("%d", &n);

   	for(i=1;i<=n;i++){
   	  	printf("\n\tINPUT\n");
      	printf("\tNILAI X [%d] : ",i); scanf("%d",&jumx);
      	printf("\tNILAI Y [%d] : ",i); scanf("%d",&jumy);
      	x[i]=jumx;
      	y[i]=jumy;
      	kuadx[i]=pow(x[i], 2);
      	kuady[i]=pow(y[i], 2);
      	sigmax=sigmax + x[i];
      	sigmay=sigmay + y[i];
      	sigmaxkuadrat=sigmaxkuadrat + kuadx[i];
      	sigmaykuadrat=sigmaykuadrat + kuady[i];
      	xy[i]=x[i]*y[i];
      	sigmaxy=sigmaxy + xy[i];
	}
	system("cls");
	//getch();
	
	printf("\n\tTABEL REGRESI LINIER\n\n");
	
		//MENGHITUNG M
       	m=((n*sigmaxy)-(sigmax*sigmay))/((n*sigmaxkuadrat)-pow(sigmax,2));
  	   	printf("\n\tNILAI M : %f ", m);
		
		//MENGHITUNG C
	 	c=((sigmay*sigmaxkuadrat)-(sigmax*sigmaxy))/((n*sigmaxkuadrat)-pow(sigmax,2));
  		printf("\n\tNILAI C = %f \n", c);
  		
		//MENGHITUNG Y AKSEN
  		for (i=1;i<=n;i++){
			yaksen[i]=((m*x[i])+c);  
		}
		
		//MENGHITUNG ERROR
		for (i=1;i<=n;i++){
			if(y[i]>yaksen[i]){
				error[i]=(y[i]-yaksen[i]);
			}else{
				error[i]=(yaksen[i]-y[i]);
			}
		}
		
		//MENGHITUNG SIGMA ERROR
		for (i=1;i<=n;i++){
 			sigmaerror=((sigmaerror+error[i]));
		}
  			printf("\n\t----------------------------------------------------------------------\n");
			printf("\tX\tY\tX Kuadrat\tY Kuadrat\tXY\tY'\tError\n");
			printf("\t----------------------------------------------------------------------\n");
						
		for(i=1;i<=n;i++){
			printf("\t%d\t%d\t%d\t\t%d\t\t%d\t%.2f\t%.2f\n",x[i],y[i],kuadx[i],kuady[i],xy[i],yaksen[i],error[i]);
		} 
			printf("\t----------------------------------------------------------------------\n");
			printf("\t%d\t%d\t%d\t\t%d\t\t%d\t\t%.2f\n",sigmax,sigmay,sigmaxkuadrat,sigmaykuadrat,sigmaxy,sigmaerror);
 		
		errorakhir = sigmaerror/n;
			printf("\n\tERROR : %f",errorakhir);				
getch();
return 0;
}
