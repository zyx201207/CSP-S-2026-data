#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M=5e5+5;
const int N=5e2+5;
const int inf=1e18;
int Tc,n,m,d,q;
array<array<int,N>,N> dis;
array<int,M> w;
array<vector<pair<int,int> >,M> g;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	clock_t Start=clock();
	cin>>Tc>>n>>m>>d>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=inf;
	for(int i=1;i<=n;i++)
		dis[i][i]=0;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			g[a].push_back(make_pair(i,t));
		}
	}
	for(int i=1;i<=m;i++)
		for(size_t j=0;j<g[i].size();j++)
			for(size_t k=j+1;k<g[i].size();k++){
				int u=g[i][j].first,v=g[i][k].first,w=g[i][j].second+g[i][k].second;
				if(dis[u][v]>w)
					dis[u][v]=dis[v][u]=w;
			}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		cout<<i<<' '<<j<<' '<<dis[i][j]<<endl;
	while(q--){
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(size_t i=0;i<g[u].size();i++)
			for(size_t j=0;j<g[v].size();j++){
				int a=g[u][i].first,b=g[v][j].first,w=g[u][i].second+g[v][j].second;
				ans=min(ans,dis[a][b]+w);
			}
		cout<<ans+w[u]+w[v]<<endl;
	}
	cerr<<(double)(clock()-Start)/CLOCKS_PER_SEC<<endl;
	return 0;
}
/*
15:27

natsu
*/