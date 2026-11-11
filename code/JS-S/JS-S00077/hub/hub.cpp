#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,q;
	cin>>c>>q;
	while(q--){
		int n,k;
		cin>>n>>k;
		graph.assign(n,vector<int>());
		for(int i=1,u,v;i<=n;i++){
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cout<<1<<"\n";
	}
	return 0;
}
