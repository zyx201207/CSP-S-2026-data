#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5,M = 505,inf=1e18;
int n,m,c,d,q;
int w[N];
struct node{int to,w;};
vector<node>G[N];
int dis[M][M];
void solve(){
	int x,y;cin>>x>>y;
	int ans=inf;
	for(auto i:G[x]){
		for(auto j:G[y]){
			ans=min(ans,i.w+j.w+dis[i.to][j.to]);
		}
	}
	cout<<ans+w[x]+w[y]<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		int k;cin>>k;
		while(k--){
			int u,w;cin>>u>>w;
			G[u].push_back({i,w});
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)dis[i][j]=inf;
	}
	for(int i=1;i<=n;++i)dis[i][i]=0;
	for(int i=1;i<=m;++i){
		for(auto x:G[i]){
			for(auto y:G[i]){
				dis[x.to][y.to]=min(dis[x.to][y.to],x.w+y.w);
				dis[y.to][x.to]=dis[x.to][y.to];
			}
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(dis[i][k]>=inf)continue;
			for(int j=i+1;j<=n;++j){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				dis[j][i]=dis[i][j];
			}
		}
	}
	while(q--)solve();
	return 0;
}