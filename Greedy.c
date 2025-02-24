#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct{
	char TenTien[25];
	int MG,PA;
}Tien;

Tien * ReadFromFile(int *n){
	FILE *f;
	f = fopen("ATM.TXT","r");
	Tien *dslt;
	dslt = (Tien*)malloc(sizeof(Tien));
	int i=0;
	while(!feof(f)){
		fscanf(f,"%d%[^\n]", &dslt[i].MG,&dslt[i].TenTien);
		dslt[i].PA = 0;
		i++;
		dslt = (Tien*)realloc(dslt,sizeof(Tien)*(i+1));
	}
	*n = i;
	fclose(f);
	return dslt;
}
void swap(Tien *x, Tien *y){
	Tien Temp;
	Temp = *x;
	*x = *y;
	*y = Temp;
}
void BubbleSort(Tien *dslt, int n){
	int i,j;
	for(i=0;i<n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(dslt[j].MG > dslt[j-1].MG)
			swap(&dslt[j],&dslt[j-1]);
		}
	}
}

void InDS(Tien *dslt, int n, int Tiencanrut){
	int i;
	int Tongtientra = 0;
	for(i=0;i<n;i++){
		if(dslt[i].PA!=0){
			printf("%-25s",dslt[i].TenTien);
			printf("%-9d",dslt[i].MG);
			printf("%-9d",dslt[i].PA);
			printf("%-10d\n",dslt[i].MG*dslt[i].PA);
			Tongtientra = Tongtientra + dslt[i].PA * dslt[i].MG;
		}
		else continue;
	}
	printf("So tien can rut= %9d\n", Tiencanrut);
	printf("So tien da tra= %9d\n", Tongtientra);
}
void Greedy(Tien* dslt, int n, int Tiencanrut){
	int i=0;
	while(i<n&&Tiencanrut>0){
		dslt[i].PA= Tiencanrut/dslt[i].MG;
		Tiencanrut = Tiencanrut-dslt[i].PA*dslt[i].MG;
		i++;
	}
}

int main(){
	int n;
	int Tiencanrut;
	printf("Nhap so tien can rut: ");
	scanf("%d", &Tiencanrut);
	Tien *dslt;
	dslt = ReadFromFile(&n);
	
	BubbleSort(dslt,n);
	
	Greedy(dslt,n,Tiencanrut);
	
	InDS(dslt,n,Tiencanrut);
	free(dslt);
	return 0;
}




