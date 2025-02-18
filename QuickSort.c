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
void print_data(recordtype a[], int n){
	int i;
	for(i=0;i<n;i++){
		printf("%3d%5d%8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}
int FindPivot(recordtype a[], int i, int j){
	keytype firstkey;
	int k = i+1;
	firstkey = a[i].key;
	while(k<=j && a[k].key==firstkey) k++;
	if(k<j){
		if(a[k].key > firstkey) return k;
		else return i;
	} 
	else return -1;		
}
int Partition(recordtype a[], int i, int j, int pivot){
	int L = i, R = j;
	while(L<=R){
		while(a[L].key < pivot) L++;
		while(a[R].key >= pivot) R--;
		if(L<R) swap(&a[L], &a[R]);
	}
	return L;
}
void QuickSort(recordtype a[], int i, int j){
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a,i,j);
	if(pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a,i,j,pivot);
		QuickSort(a,i,k-1);
		QuickSort(a,k,j);
	}
}
int main(){
	recordtype a[100];
	int n;
	read_data(a,&n);
	printf("du lieu truoc khi xep:\n");
	print_data(a,n);
	QuickSort(a,0,n-1);
	printf("du lieu sau khi xep:\n");
	print_data(a,n);
	
}
