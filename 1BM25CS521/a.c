#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 100000

void merge(int a[],int low,int mid,int high)
{
    int i=low,j=mid+1,k=low;
    int b[max];
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j]) b[k++]=a[i++];
        else b[k++]=a[j++];

    }
    while(i<=mid) b[k++]=a[i++];
    while(j<=high) b[k++]=a[j++];
    for(k=low;k<=high;k++) a[k]=b[k];
}
void mergesort(int a[],int low,int high)
{
    if (low<high)
    {
        int mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main()
{
    int n,i;
    printf("Enter no. of elements");
    scanf("%d",&n);
    int a[n];
    printf("Enter integers \n");
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%10000;
        //scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    clock_t start,end;
    start = clock();
    mergesort(a,0,n-1);
    end=clock();
    printf("\nSorted\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    double time_taken = ((double)(end - start)*1000)/CLOCKS_PER_SEC;
    printf("\nTime takes = %f milisec",time_taken);
    return 0;
}
