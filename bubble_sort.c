#include <stdio.h>
#include <stdbool.h>
void bubble_sort(int a[], int length);

int main(){
	int a[] = {7,6,4,1,2,3,5,8,9,0};
	int i,length = 10;
	bubble_sort(a,length);
	for(i=0;i<length;i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}

void bubble_sort(int a[], int length){
	int i=0,j;
	bool swapped = false;
	do{
		swapped = false;
		for(j=0;j<length-1-i;j++){
			if(a[j] < a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				swapped = true;
			}
		}
		i++;
	}while(swapped == true);	
}
