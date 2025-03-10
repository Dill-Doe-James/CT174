#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct{
	char TenDV[20];
	int TL, GT, PA;
}DoVat;

typedef int bang[50][100];

DoVat *ReadFromFile(int *W, int *n){
	FILE *f;
	f = fopen("QHD_Caibalo.INP", "r");
	fscanf(f, "%d", W);
	DoVat *dsdv;
	dsdv = (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f,"%d%d%[^\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].TenDV);
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv,sizeof(DoVat)*(i+1));
	}
	*n=i;
	fclose(f);
	return dsdv;
}
void TaoBang(DoVat *dsdv, int n, int W, Bang F, Bang X){
	int xk, yk, k;
	int FMax, XMax, V;
	
	for(V=1;V<=W;V++){
		X[0][V] = dsdv[0].TL;
		F[0][V] = X[0][V]*dsdv[0].GT;
	}
	for(k=1;k<n;k++){
		for(V=0;V<=W;V++){
			FMax = F[k-1][V];
			XMax = 0;
			yk = V/dsdv[k].TL;
			for(xk=1;xk<=yk;xk++){
				if(F[k-1][V - xk*dsdv[k].TL] + xk*dsdv[k].GT > FMax){
					FMax = F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT;
					XMax = xk;
				}
			}
			F[k][V] = FMax;
			X[k][V] = XMax;
		}
	}
}



