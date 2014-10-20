#include<stdio.h>
long long int search(long long int[],long long int,long long int,long long int);
void mergeSort(long long int[],long long int,long long int);
void merge(long long int[],long long int,long long int,long long int);
int main()
{
long long int n1,n2,n3,i,j=0,flag1=0,flag2=0,count=0;
scanf("%lld %lld %lld",&n1,&n2,&n3);
long long int a[n1],b[n2],c[n3],d[n1+n2+n3];
for(i=0;i<n1;i++)
scanf("%lld",&a[i]);
for(i=0;i<n2;i++)
scanf("%lld",&b[i]);
for(i=0;i<n3;i++)
scanf("%lld",&c[i]);
j=0;
for(i=0;i<n1;i++)
{
flag1=search(b,0,n2-1,a[i]);
flag2=search(c,0,n3-1,a[i]);
if(flag1!=-1 || flag2!=-1)
{
d[j]=a[i];
j++;
}
}
for(i=0;i<n2;i++)
{
flag1=search(a,0,n1-1,b[i]);
flag2=search(c,0,n3-1,b[i]);
if(flag1!=-1 || flag2!=-1)
{
d[j]=b[i];
j++;
}
}
for(i=0;i<n3;i++)
{
flag1=search(a,0,n1-1,c[i]);
flag2=search(b,0,n2-1,c[i]);
if(flag1!=-1 || flag2!=-1)
{
d[j]=c[i];
j++;
}
}
mergeSort(d,0,j-1);
for(i=1;i<j;i++)
{
if(d[i]!=d[i-1])
count++;
}
count++;
printf("%lld\n",count);
printf("%lld\n",d[0]);
for(i=1;i<j;i++)
{
if(d[i]!=d[i-1])
printf("%lld\n",d[i]);
}
return 0;
}
long long int search(long long int arr[],long long int beg,long long int end,long long int item)
{
long long int mid;
while(beg<=end)
{
mid = beg + (end-beg)/2;
if(arr[mid]==item)
return mid;
else if(arr[mid]>item)
end=mid-1;
else if(arr[mid]<item)
beg=mid+1;
}
return -1;
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
