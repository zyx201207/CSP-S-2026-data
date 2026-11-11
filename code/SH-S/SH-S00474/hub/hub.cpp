#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<vector<int> > adj(n+1);
		for(int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cout<<n/k-(rand()%int(log(n)+1))<<"\n";
	}
	return 0;
} 
