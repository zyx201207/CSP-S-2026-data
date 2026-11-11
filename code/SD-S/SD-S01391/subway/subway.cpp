#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
ll dt[500011];
struct edge {
	ll v,w;
};
void ckmin(ll &x,ll y) {
	x=x<y?x:y;
}
vector<edge> e2[500011];
ll dis[511][511];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>dt[i];
	for(int i=1,k; i<=n; i++) {
		cin>>k;
		for(int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			edge pd= {i,t};
			e2[a].emplace_back(pd);
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1; i<=n; i++)dis[i][i]=0;
	for(int i=1; i<=m; i++) {
		int N=e2[i].size();
		for(int j=0; j<N; j++)
			for(int k=j+1; k<N; k++) {
				ckmin(dis[e2[i][j].v][e2[i][k].v],e2[i][j].w+e2[i][k].w);
				ckmin(dis[e2[i][k].v][e2[i][j].v],e2[i][j].w+e2[i][k].w);
			}
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				ckmin(dis[i][j],dis[i][k]+dis[j][k]);
	while(q--) {
		int u,v;
		ll ans=5e18;
		cin>>u>>v;
		for(edge i:e2[u])
			for(edge j:e2[v])
				ckmin(ans,i.w+j.w+dis[i.v][j.v]);
		cout<<ans+dt[u]+dt[v]<<endl;
	}
	return 0;
}
