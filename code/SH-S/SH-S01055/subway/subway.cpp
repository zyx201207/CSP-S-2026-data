#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int c,n,m,d,q;
int w[500005];

vector<pair<int,int>> g[500005];

ll dis[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i) cin>>w[i];
	
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		while(k--){
			int u,w;
			cin>>u>>w;
			g[u].push_back({i,w});
		}
	}
	
	memset(dis,0x3f,sizeof(dis));
	
	for(int u=1;u<=n;++u) dis[u][u]=0;
	
	for(int i=1;i<=m;++i){
		int sz=g[i].size();
		for(int a=0;a<sz;++a){
			for(int b=a+1;b<sz;++b){
				auto aa=g[i][a],bb=g[i][b];
				dis[aa.first][bb.first]=min(dis[aa.first][bb.first],(ll)aa.second+bb.second);
				dis[bb.first][aa.first]=min(dis[bb.first][aa.first],(ll)aa.second+bb.second);
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int u=1;u<=n;++u){
			for(int v=1;v<=n;++v){
				dis[u][v]=min(dis[u][v],dis[u][i]+dis[i][v]);
			}
		}
	}
	
	while(q--){
		int u,v;
		cin>>u>>v;
		
		ll ans=1e18;
		
		for(auto a:g[u]){
			for(auto b:g[v]){
				ans=min(ans,a.second+dis[a.first][b.first]+b.second);
			}
		}
		
		cout<<ans+w[u]+w[v]<<'\n';
	}
	
	return 0;
}
