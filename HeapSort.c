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
void PushDown(recordtype a[], int first, int last){
	int r = first;
	while(r<=(last-1)/2){
		if(last== 2*r+1){
			if(a[r].key > a[last].key) swap(&a[r], &a[last]);
			r = last;	
		}
		else if((a[r].key > a[2*r+1].key)&&(a[2*r+1].key<=a[2*r+2].key)){
			swap(&a[r],&a[2*r+1]);
			r = 2*r+1;
		}
		else if((a[r].key > a[2*r+2].key)&&(a[2*r+2].key<a[2*r+1].key)){
			swap(&a[r],&a[2*r+2]);
			r = 2*r+2;
		}
		else r = last;
	}
}
void HeapSort(recordtype a[], int n){
	int i;
	for(i=(n-2)/2;i>=0;i--){
		PushDown(a,i,n-1);
	}
	for(i=n-1;i>=2;i--){
		swap(&a[0],&a[i]);
		PushDown(a,0,i-1);
	}
	swap(&a[0],&a[1]);
}
int main(){
	recordtype a[100];
	int n;
	read_data(a,&n);
	printf("du lieu truoc khi xep:\n");
	print_data(a,n);
	HeapSort(a,n);
	printf("du lieu sau khi xep:\n");
	print_data(a,n);
	
}
