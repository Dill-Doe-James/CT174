#include <stdio.h>

int main(){
	int a[] = {4,5,2,1,6,7,3,9,8,0};
	int length = 10;
	int i,j;
	for(i=0;i<length-1;i++){
		int min_pos = i;
		for(j=i+1;j<length;j++){
			if(a[j] < a[min_pos]){
				min_pos = j;
			}
		}
		if(i!=min_pos){
			int temp = a[i];
			a[i] = a[min_pos];
			a[min_pos] = temp;
		}
	}
	for(i=0;i<length;i++){
		printf("a[%d] = %d\n", i, a[i]);
	}
	return 0;
}
