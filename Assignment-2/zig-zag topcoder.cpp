#include<bits/stdc++.h>
using namespace std;

int max(int a,int b){
	return (a>b)?a:b;
}

int main(){
	int n,*arr,*ans_pos,*ans_neg;
	/*
	*There is slight modification in input format
	*Instead of input as string i have taken input as array
	*first input is no. of elements=n
	*then array of n elements as input
	*/
	cin>>n;
	int diff;
	arr=new int[n];
	ans_pos=new int[n];
	ans_neg=new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++){
		ans_neg[i]=ans_pos[i]=0;
		for(int j=i-1;j>=0;j--){
			diff=arr[i]-arr[j];
			if(diff>0) ans_pos[i]=max(1+ans_neg[j],ans_pos[i]);
			else if(diff<0) ans_neg[i]=max(1+ans_pos[j],ans_neg[i]); 
		}
	}
	cout<<max(ans_neg[n-1],ans_pos[n-1])+1<<endl;
	return 0;
}
