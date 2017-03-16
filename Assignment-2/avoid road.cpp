//avoid roads topcoder problem no.1889
#include<bits/stdc++.h>
#define lld long long int
using namespace std;

lld ans[101][101]={0};

int main(){
	int width, height;
	cin>>width>>height;
	int m,a,b,c,d;
	/*
	*Instead of taking input as string, i have taken input explicitly.
	*m is the number of untraversable blocks
	*{a,b,c,d} specifies a single untraversal block
	*/
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c>>d;
		//-1 means down
		//-2 means left
		if(a==c){
			if(b>d) ans[a][b]=-1;
			else ans[c][d]=-1;
		}
		else{
			if(a>c) ans[a][b]=-2;
			else ans[c][d]=-2;
		}
	}
	for(int i=0;i<=width;i++){
		for(int j=0;j<=height;j++){
			if(i==0 && j==0) ans[i][j]=1;
			else{
				if(ans[i][j]==0){
					if(j!=0) ans[i][j]+=ans[i][j-1];
					if(i!=0) ans[i][j]+=ans[i-1][j];
				}
				else if(ans[i][j]==-1){
					if(i==0) ans[i][j]=0;
					else ans[i][j]=ans[i-1][j];
				}
				else if(ans[i][j]==-2){
					if(j==0) ans[i][j]=0;
					else ans[i][j]=ans[i][j-1];
				}
			}
		}
	}
	cout<<ans[width][height]<<endl;
	return 0;
}
