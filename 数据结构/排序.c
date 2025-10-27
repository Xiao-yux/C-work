#include<stdio.h>

int main(){
    int arr[]={23,232,1,32,44,65,76};
    int n=sizeof(arr)/sizeof(arr[0]);
    //选择排序
   for(int i=0;i<n-1;i++){
       int min_idx=i;
       for(int j=i+1;j<n;j++){
           if(arr[j]<arr[min_idx]){
               min_idx=j;
           }
       }
       int temp=arr[min_idx];
       arr[min_idx]=arr[i];
       arr[i]=temp;
   }

   printf("排序的数组是: \n");
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
   }
   printf("\n");

   return 0;
}