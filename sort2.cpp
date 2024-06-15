#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[]){
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge(int arr[],int l,int mid,int r){
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a1[n1];
    int a2[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i]=arr[i+l];
    }
    for (int i =0; i < n2; i++)
    {
        a2[i]= arr[i+ mid+1];
    }
    int i=0,j=0,c=l;
    while (i<n1 && j<n2)
    {
        if(a1[i]<a2[j]){
            arr[c]=a1[i];
            i++;
            c++;
        }else if (a1[i]>a2[j])
        {
            arr[c]=a2[j];
            c++;
            j++;
        }else{
            arr[c]=arr[i];
            i++;c++;
        }
    }
    while (i<n1)
    {
        /* code */
       arr[c]=a1[i];
            i++;
            c++;
    }
    while (j<n2)
    {
        /* code */
        arr[c]=a2[j];
            c++;
            j++;
    }
}
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return ;
    }
    int  mid = (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}
void swap(int arr[],int a,int b){
    int temp = arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}
int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j < r; j++)
    {
        /* code */
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}
void quickSort(int arr[],int l,int r){
    if(l>=r){
        return ;
    }
    int pi = partition(arr,l,r);
    quickSort(arr,l,pi-1);
    quickSort(arr,pi+1,r);
}
//count Sort
void countSort(int arr[]){
    int countArray[100]={0};
    for(int i=0;i<10;i++){
        countArray[arr[i]]++;
    }
    for (int i = 0; i < 9; i++)
    {
        countArray[i+1] +=countArray[i];
    }
    int new_arr[10];
    for (int i = 9; i >=0 ; i--)
    {  
        countArray[arr[i]]--;
        new_arr[countArray[arr[i]]]=arr[i];
    }
    cout<<"\n";
    printArray(new_arr);
}
//DNF Sort
void DNF(int arr[]){
    int i=0,mid = 0,j=9;
    while (mid<=j)
    {
        if(arr[mid]==0){
            swap(arr,i,mid);
            mid++;
            i++;
        }else if (arr[mid]==1)
        {
         mid++;   
        }else{
            swap(arr,j,mid);
            j--;
        }
        
    }
}
void waveSort(int arr[],int n){
    if(n==0 || n==1){
        return;
    }
    for (int i = 1; i < n-1; i+=2)
    {
        if(arr[i]>arr[i-1]){
            swap(arr,i,i-1);
        }
        if (arr[i]>arr[i+1] && i<=n-2)
        {
            swap(arr,i,i+1);
        }
    }
    printArray(arr);
}
int main(){
    int arr[7]={1,3,4,7,5,6,2};
    waveSort(arr,7);
    return 0;
}