#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Node{
	ll id;
	ll time;
};

ll c, n, m, d, q;
ll k[505];
ll e[505][505];
ll f[505][505];
int w[500005];
vector <Node> scc[500005];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int start, end;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	
	for(int i=1; i<=n; i++){//i号线 
		cin>>k[i];
		
		for(int j=1; j<=k[i]; j++){//第j个站点 
			int a, tme;
			cin>>a>>tme;
			
			for(auto t:scc[a]){
				e[i][t.id] = e[t.id][i] = 1;
//				cout<<i<<" "<<t.id<<" connected\n";
			}
			
			scc[a].push_back({i, tme});
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			f[i][j] = 4e18;
		}
	}
	
	for(int i=1; i<=m; i++){
//		cout<<"station No."<<i<<": ";
		
		for(auto u:scc[i]){
//			cout<<u.id<<" ";
			
			for(auto v:scc[i]){
				if(u.id == v.id){
					continue;
				}
				
				f[u.id][v.id] = min(f[u.id][v.id], u.time+v.time);
				f[v.id][u.id] = f[u.id][v.id];
				
//				cout<<"\ntransfer from "<<u.id<<" to "<<v.id<<" costs "<<f[u.id][v.id];
			}
		}
		
//		cout<<"\n";
	} 
	
	for(int i=1; i<=n; i++){
		f[i][i] = 0;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
			} 
		}
	}
	
	for(int i=1; i<=q; i++){
		ll ans=5e18;
		cin>>start>>end;
		
		for(auto u:scc[start]){
			for(auto v:scc[end]){
				ans = min(ans, f[u.id][v.id]+u.time+v.time);
			}
		}
		
		cout<<ans+w[start]+w[end]<<"\n";
	}
	
	return 0;
}
