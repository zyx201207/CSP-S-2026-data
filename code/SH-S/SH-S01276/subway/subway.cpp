#include<bits/stdc++.h>
using namespace std;

#define int long long 

const int N=1e6+5;

int c,n,m,d,q,val[N];
int dis[505][505],a[N];
struct edge{int u,v,w;};
vector<edge> g[N];

signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>val[i];
	for(int i=1;i<=n;i++) {
		int k;
		cin>>k;
		for(int j=1;j<=k;j++) {
			int t;cin>>a[j]>>t;
			g[m+i].push_back({m+i,a[j],t});
			g[a[j]].push_back({a[j],m+i,t});
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=1e18;
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) {
		for(int j=0;j<g[i].size();j++) {
			for(int k=0;k<g[i].size();k++) {
				int v=g[i][j].v,w=g[i][j].w;
				int vv=g[i][k].v,ww=g[i][k].w;
				dis[v-m][vv-m]=min(dis[v-m][vv-m],ww+w);
				dis[vv-m][v-m]=min(dis[vv-m][v-m],w+ww);
			}
		}
	}
	for(int k=1;k<=n;k++) {
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=2e18;
		for(int j=0;j<g[x].size();j++) {
			for(int k=0;k<g[y].size();k++) {
				int v=g[x][j].v,w=g[x][j].w;
				int vv=g[y][k].v,ww=g[y][k].w;
				ans=min(ans,w+dis[v-m][vv-m]+ww);
			}
		}
		cout<<ans+val[x]+val[y]<<'\n';
	}
	return 0;
}
