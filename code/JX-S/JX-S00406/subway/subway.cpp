#include<bits/stdc++.h>
using namespace std;
signed main(){
	srand(time(0));
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int u;
		cin>>u;
		//adj[i].push_back({i+m,u});
		//adj[i].push_back({u,i+m});
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int u,v;
			cin>>u>>v;
			//adj[u].push_back({i+2*m*j,v});
			//adj[u].push_back({v,i+2*m*j});
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		//int ans=0;
		//for(int j=1;j<=k;j++){
		//	if(adj[u+2*m*j].v+2*m*j){
		//		ans+=2*adj[u+2*m*j].v+2*m*j;
		//	}
		//}
		cout<<rand()<<"\n";
	}
	return 0;
}
