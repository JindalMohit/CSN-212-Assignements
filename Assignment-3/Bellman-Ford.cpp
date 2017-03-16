#include<bits/stdc++.h>
using namespace std;

struct Edge{
	int src, dest, cost;
};

int main(){
	clock_t t;

	cout<<"Input format:\n";
	cout<<"First line of the input shouls be two integers: V-number of vertices and E-number of edges\n";
	cout<<"Second line contains single integer which specify the souce vertex: src\n";
	cout<<"Next E lines specifies each edge of the graph with three integers each:\n";
	cout<<"\'a b c\'\n";
	cout<<"It defines directed edge from vertex a to b with weight c\n";
	cout<<"a,b,src belongs to 0-V-1\n\n";

	int T;
	cin>>T;
	while(T--){
		int v,e,src;
		cin>>v>>e;
		cin>>src;
		Edge *edge;
		edge = new Edge[e];
		for(int i=0;i<e;i++){
			cin>>edge[i].src>>edge[i].dest>>edge[i].cost;
		}

		t=clock();

		int *dist;
		dist = new int[v];
		for(int i=0;i<v;i++){
			dist[i]=INT_MAX;
		}
		dist[src]=0;
		int a,b,c;
		int check;
		for(int i=0;i<v;i++){
			for(int j=0;j<e;j++){
				a=edge[j].src; b=edge[j].dest; c=edge[j].cost;
				if(dist[a] != INT_MAX){
					if(dist[b] > (dist[a]+c)){
						if(i==v-1){
							check=1;
						}
						else{
							dist[b] = dist[a]+c;
						}
					}
				}
			}
		}
		if(check==1){
			cout<<"Negative cycle found\n";
		}
		else{
			cout<<"\nDistance of all vertices from the source vertex:\n";
			cout<<"Vertex   Distance from source\n";
			for(int i=0;i<v;i++){
				cout<<i<<"          ";
				if(dist[i]==INT_MAX) cout<<"inf"<<endl;
				else cout<<dist[i]<<endl;
			}
			cout<<endl;
		}

		t = clock() - t;
		printf ("It took %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);	
	}
	return 0;
}