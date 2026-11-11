#include<bits/stdc++.h>
using namespace std;
int w[500010];
int k[510];
vector<int> a[510];
vector<pair<int,int>> v[500010];
int c,n,m,d,q;
long long dis[510][510];
map<pair<int,int>,long long>vis;
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>k[i];
		a[i].push_back(0);
		for(int j=1; j<=k[i]; j++) {
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			v[x].push_back({i,y});
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1; i<=n; i++) {
		dis[i][i]=0;
	}
	for(int i=1; i<=m; i++) {
		for(auto x:v[i]) {
			for(auto y:v[i]) {
				int u=x.first;
				int v=y.first;
				long long w=x.second+y.second;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--) {
		int x,y;
		cin>>x>>y;
		if(vis[{x,y}]==0) {
			long long ans=1e18;
			for(auto i:v[x]) {
				for(auto j:v[y]) {
					int u=i.first;
					int v=j.first;
					ans=min(ans,w[x]+w[y]+dis[u][v]+i.second+j.second);
				}
			}
			cout<<ans<<"\n";
			vis[{x,y}]=ans;
		}else{
			cout<<vis[{x,y}]<<"\n";
		}
	}
	return 0;
}
