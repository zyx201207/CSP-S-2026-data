#include<bits/stdc++.h>

using namespace std;

#define int long long

mt19937_64 rdm(time(0));

const int N=4e2+5,M=2e2+5,inf=1e18;

int dis[N],sum[N],w[N],k[M],v[N],W[N];

int c,n,m,d,q;

int g[N][N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		for(int j=1;j<=m;j++){
			g[i][j]=inf;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>v[j]>>W[j];
			for(int k=1;k<j;k++){
				g[v[j]][v[k]]=min(W[k]+W[j],g[v[j]][v[k]]);
				g[v[k]][v[j]]=min(W[k]+W[j],g[v[k]][v[j]]);
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				g[i][j]=min(g[i][k]+g[k][j],g[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<g[u][v]+w[u]+w[v]<<'\n';
	}
	return 0;
}

