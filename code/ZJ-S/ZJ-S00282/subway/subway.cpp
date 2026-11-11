#include<bits/stdc++.h>
using namespace std;
long long w[500010];
struct node1 {
	long long idx,t;
};
vector<node1>adj[500010];
long long dis[510][510];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1; i<=m; i++)cin>>w[i];
	for(long long i=1; i<=n; i++) {
		long long k;
		cin>>k;
		for(long long j=1; j<=k; j++) {
			long long a,t;
			cin>>a>>t;
			adj[a].push_back({i,t});
		}
	}
	for(long long i=1; i<=n; i++) {
		for(long long j=1; j<=n; j++) {
			dis[i][j]=1e16;
		}
		dis[i][i]=0;
	}
	for(long long i=1; i<=m; i++) {
		for(long long j=0; j<adj[i].size(); j++) {
			for(long long k=j+1; k<adj[i].size(); k++) {
				long long u=adj[i][j].idx;
				long long v=adj[i][k].idx;
				long long val=adj[i][j].t+adj[i][k].t;
				dis[u][v]=min(dis[u][v],val);
				dis[v][u]=min(dis[v][u],val);
			}
		}
	}
	for(long long k=1; k<=n; k++) {
		for(long long i=1; i<=n; i++) {
			if(i==k)continue;
			for(long long j=1; j<=n; j++) {
				if(i==j||j==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) {
		long long x,y;
		cin>>x>>y;
		long long val=1e16;
		for(long long i=0; i<adj[x].size(); i++) {
			for(long long j=0; j<adj[y].size(); j++) {
				long long u=adj[x][i].idx;
				long long v=adj[y][j].idx;
				long long vv=dis[u][v]+adj[x][i].t+adj[y][j].t;
				val=min(val,vv);
			}
		}
		cout<<val+w[x]+w[y]<<'\n';
	}
	return 0;
}