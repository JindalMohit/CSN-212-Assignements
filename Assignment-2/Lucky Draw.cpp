#include<bits/stdc++.h>
using namespace std;
 
int ceil_index(int* arr,int a,int b,int value){
	int m;
	while((b-a)>1){
		m=a+(b-a)/2;
		if(arr[m]>=value) b=m;
		else{
			a=m;
		}
	}
	return b;
}
 
int LISlength(int* arr,int size){
	int *LIS,len=0;
	LIS=new int[size];
	LIS[0]=arr[0]; len=1;
	for(int i=1;i<size;i++){
		if(arr[i]>LIS[len-1]){
			LIS[len]=arr[i];
			len++;
		}
		else if(arr[i]<LIS[0]){
			LIS[0]=arr[i];
		}
		else{
			LIS[ceil_index(LIS,-1,len-1,arr[i])]=arr[i];
		}
	}
	return len;
}
 
int main(){
	int t,n,ans,*arr,max;
	scanf("%d",&t);
	while(t--){
		max=ans=0;
		scanf("%d",&n);
		arr=new int[2*n];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			arr[i+n]=arr[i];
		}
		for(int i=0;i<n;i++){
			ans=LISlength(arr+i,n);
			if(ans>max) max=ans;
		}
		printf("%d\n",max);
	}
	return 0;
} 