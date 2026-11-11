#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const int MAXN=5e5+10;
int cn,n,m,dx,q,vis[MAXN],w[MAXN];
long long d[510][510];
vector<pi> G[MAXN];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>cn>>n>>m>>dx>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)d[i][j]=1e18;
	for(int i=1;i<=n;i++){
		d[i][i]=0;
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int ax,tx;
			cin>>ax>>tx;
			for(int k=0;k<G[ax].size();k++){
				long long v=G[ax][k].first,wx=G[ax][k].second;
				d[i][v]=d[v][i]=min(d[i][v],wx+tx);
			}
			G[ax].push_back({i,tx});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		long long ans=1e18;
		for(int j=0;j<G[x].size();j++){
			long long u=G[x][j].first,wu=G[x][j].second;
			for(int k=0;k<G[y].size();k++){
				int v=G[y][k].first,wv=G[y][k].second;
				ans=min(ans,d[u][v]+wu+wv);
			}
		}cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
