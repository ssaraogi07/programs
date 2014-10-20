#include<stdio.h>
long long int search(long long int[],long long int,long long int,long long int);
void mergeSort(long long int[],long long int,long long int);
void merge(long long int[],long long int,long long int,long long int);
int main()
{

}
void mergeSort(long long int arr[],long long int l,long long int r)
{
long long int m;
if(l<r)
{
m=l+(r-l)/2;
mergeSort(arr,l,m);
mergeSort(arr,m+1,r);
merge(arr,l,m,r);
}
}
void merge(long long int arr[],long long int l,long long int m,long long int r)
{
long long int n1,n2,i,j,k;
n1=m-l+1;
n2=r-m;
long long int left[n1],right[n2];
for(i=0;i<n1;i++)
left[i]=arr[l+i];
for(j=0;j<n2;j++)
right[j]=arr[m+1+j];
i=0;
j=0;
k=l;
while(i<n1 && j<n2)
{
if(left[i]<=right[j])
{
arr[k]=left[i];
i++;
k++;
}
else
{
arr[k]=right[j];
j++;
k++;
}
}
if(i<n1)
{
while(i<n1)
{
arr[k]=left[i];
i++;
k++;
}
}
if(j<n2)
{
while(j<n2)
{
arr[k]=right[j];
j++;
k++;
}
}
}
