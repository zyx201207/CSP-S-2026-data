#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,M=5e5+10,inf=1e18;
int c,n,m,d,q; 
int w[M],k[N],dis[N][N];
vector<pair<int,int>>g[M];
void init(){
	for(int u=1;u<=n;u++){
		for(int v=1;v<=n;v++){
			dis[u][v]=dis[v][u]=inf;
		}
 	}
	for(int i=1;i<=n;i++){
		dis[i][i]=inf;
	}
}
void dd(){
	for(int k_=1;k_<=n;k_++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=dis[i][j]+dis[i][k_]+dis[k_][j];
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	init();
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;
			cin>>u>>t;
			g[u].push_back({i,t}); 
		}
	}
	for(int i=1;i<=m;i++){
		for(auto x:g[i]){
			int u=x.first,w_1=x.second;
			for(auto y:g[i]){
				int v=y.first,w_2=y.second;
				dis[u][v]=dis[v][u]=min(dis[u][v],w_1+w_2);
			}
		}
	}
	dd();
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(auto s1:g[u]){
			for(auto s2:g[v]){
				ans=min(ans,dis[s1.first][s2.first]+w[u]+w[v]+s1.second+s2.second);
			}
		}
		cout<<ans;
	}
	return 0;
}

