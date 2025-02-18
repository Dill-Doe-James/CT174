#include <stdio.h>
typedef int keytype;
typedef float othertype;
typedef struct{
	keytype key;
	othertype otherfields;
}recordtype;
void swap(recordtype *x, recordtype *y){
	recordtype temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
void Selection_sort(recordtype a[], int n){
	int i,j,lowindex;
	keytype lowkey;
	for(i=0;i<=n-2;i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j=i+1;j<=n-1;j++){
			if(a[j].key<lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}			
		}
	swap(&a[i],&a[lowindex]);	
	}
}
void read_data(recordtype a[], int *n){
	FILE *file;
	file = fopen("data.txt","r");
	int i=0;
	if(file != NULL){
		while(!feof(file)){
			fscanf(file,"%d%f", &a[i].key, &a[i].otherfields);
			i++;
		}
	}
	else printf("Loi mo file!\n");
	fclose(file);
	*n = i;
	
}

void insertionSort(recordtype a[], int n){
	int i;
	for(i=1;i<=n;i++){
		int j = i;
		while(j>0 && a[j].key < a[j-1].key){
			swap(&a[j],&a[j-1]);
			j--;
		}
	}
}
void BubbleSort(recordtype a[], int n){
	int i,j;
	for(i=0;i<=n-2;i++){
		for(j=n-1;j>=i+1;j--){
			if(a[j].key<a[j-1].key)
				swap(&a[j].key, &a[j-1].key);
		}
	}
}
void print_data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}
int main(){
	recordtype a[100];
	int n=0;
	read_data(a,&n);
	printf("du lieu truoc khi xep:\n");
	print_data(a,n);
	BubbleSort(a,n);
	printf("du lieu sau khi xep:\n");
	print_data(a,n);
	
}
