#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5,INF=1e18;
vector<pair<int,int> > G[M];
int c,n,m,d,ans,Q,w[M],dis[N][N];
void init(){
	for(int i=1;i<=n;i++)
	for(int j=1;j<i;j++){
		dis[i][j]=INF;
		dis[j][i]=INF;
	}
}
void solve(){
	int st,ed;
	cin>>st>>ed;ans=INF;
	for(int i=0;i<G[st].size();i++)
	for(int j=0;j<G[ed].size();j++){
		int u=G[st][i].first;
		int v=G[ed][j].first;
		ans=min(ans,w[st]+w[ed]+dis[u][v]+G[st][i].second+G[ed][j].second);
	}
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;init();
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,u,t;j<=k;j++){
			cin>>u>>t;
			G[u].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
	for(int j=0;j<G[i].size();j++)
	for(int k=0;k<j;k++){
		int u=G[i][j].first;
		int v=G[i][k].first;
		int t=G[i][j].second+G[i][k].second;
		dis[u][v]=min(dis[u][v],t);
		dis[v][u]=min(dis[v][u],t);
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(Q--) solve();
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/