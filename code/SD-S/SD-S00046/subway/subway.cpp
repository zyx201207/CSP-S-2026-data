#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ldb=long double;
using db=double;
using i128=__int128;
using uint=unsigned int;
using ull=unsigned long long;
const int M=5e5+10;
const int N=510;
int c,n,m,d,q;
ll w[M];
ll f[N][N];
vector<pair<int,ll>> x_graph[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			ll t;
			cin>>a;
			cin>>t;
			x_graph[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e18;
		}
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		if(!x_graph[i].empty()){
			for(int j=0;j<x_graph[i].size();j++){
				for(int op=j+1;op<x_graph[i].size();op++){
					int u=x_graph[i][j].first;
					int v=x_graph[i][op].first;
					ll opu=x_graph[i][j].second+x_graph[i][op].second;
					f[u][v]=min(f[u][v],opu);
					f[v][u]=min(f[v][u],opu);
				}
			}
		}
	}
	for(int zhongz=1;zhongz<=n;zhongz++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][zhongz]+f[zhongz][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		ll ans=1e18;
		int x,y;
		cin>>x>>y;
		for(auto it:x_graph[x]){
			for(auto itx:x_graph[y]){
				ans=min(ans,f[it.first][itx.first]+w[x]+w[y]+it.second+itx.second);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

