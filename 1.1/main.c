#include <stdio.h>
void heap_adjust(int arr[], int father, int n)
{
	int child = father*2 + 1;
	int temp = arr[father];
	while(child < n){
		if(child+1<n && arr[child]<arr[child+1])child++;
		if(arr[father]>=arr[child])break;
		arr[father]=arr[child];
		father = child;
		child = father*2+1;
		arr[father] = temp;
	}
}

void build_heap(int arr[], int n)
{
	for(int i=(n-1)/2;i>=0;--i)
		heap_adjust(arr, i, n);
}

void heap_sort(int arr[], int beg, int end)
{
	build_heap(arr+beg, end - beg);
	for(int tmp, i= end-1; i>beg;--i)
	{
		tmp = arr[i];
		arr[i] = arr[0];
		arr[0] = tmp;
		heap_adjust(arr+beg, 0, i);
	}
}
int main(void){
	int arr[100];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n;i++)
		scanf("%d", &arr[i]);
	heap_sort(arr, 0, n);
	for(int i = 0; i<n;++i)printf("%d ", arr[i]);
	return 0;
}
