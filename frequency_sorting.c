#include<stdio.h>


struct s{
	int count[100];
	int value[100];
	int *index[100];
	int length;
};

void swap(int *x,int *y){
	*x=*x^*y;
	*y=*x^*y;
	*x=*x^*y;
}


void sort_array(int sort_arr[],int n){
	int i,j;

	for(i=0;i<n-1;i++){
		for(j=i;j<n;j++)
		{
			if(sort_arr[i] > sort_arr[j]){
				swap(&sort_arr[i],&sort_arr[j]);
			}
		}
	}
}


struct s remove_duplicate_store_index(int *arr,int n,int array[]){
	static int k;//used for sorting and couting
	static int j;
	struct s s1;
	int i=0;
	s1.count[k]=0;
	for(i=0;i<n;i++){
		if(*arr == array[i]){
			s1.index[j]=arr;	
		}
	}
	j++;
	if(s1.value[k-1] != *arr )//remove duplicates and store only one of them
	{
		s1.value[k]=*arr;
		k++;   //increment only for original value and not for duplicate
	}
	s1.length=k;//store the length of the array

	return s1;
}


struct s count_frequency(struct s s2,int arr[],int n){//count the frequency of elements occured.
	int i,j;

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if( s2.value[i] == arr[j]){
				(s2.count[i])++;
			}
		}
	}
	return s2;
}

struct s sort_value_descending(struct s s3,int n){ // sort the elemenss of array named value in structure of descending order
	int i,j;
	for(i=0;i<n-1;i++){

		for(j=i;j<n;j++){

			if(s3.count[i] < s3.count[j]){
				swap(&(s3.count[i]),&(s3.count[j]));
				swap(&(s3.value[i]),&(s3.value[j]));
			}
		}
	}
	return s3;
}


int* sort_with_frequency(struct s s4,int n){//sort according to the frquency of the elements
	int i,j,k=0;

	static int temp[100];
	for(i=0;i<(s4.length);i++){
		for(j=0;j<n;j++)
		{
			if(s4.value[i] == *(s4.index[j])){
				temp[k++]=*(s4.index[j]);

			}
		}
	}
	return temp;
}

void frequency_sort(int arr[],int n){
	struct s get;
	int i,*temp;
	sort_array(arr,n);
	for(i=0;i<n;i++){
		get=remove_duplicate_store_index(&arr[i],n,arr);
	}
	get=count_frequency(get,arr,n);
	get=sort_value_descending(get,n);
	temp=sort_with_frequency(get,n);

	for(i=0;i<n;i++){
		printf("The value in array temp is %d\n",temp[i]);
	}

	//for(i=0;i<get.length;i++){
	//printf("The element is the value array are %d\n",get.value[i]);
	//printf("The frequency of each element in sorted order is %d\n",get.count[i]);
	//printf("The value in index is %d\n",*(get.index[i]));
	//}
}



int main(){
	int n;
	int arr[]={2,3,2,4,5,12,2,3,3,3,12};
	n=sizeof(arr)/sizeof(arr[0]);
	frequency_sort(arr,n);
	return 0;
}
