#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define x first
#define y second
using namespace std;
const ll N=505,M=5e5+5;
ll c,n,m,d,q,w[M],dis[N][N];
vector<pair<ll,ll>> edges[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			edges[a].push_back({i,t});
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<edges[i].size();j++){
			for(ll k=j+1;k<edges[i].size();k++){
				ll u=edges[i][j].x,v=edges[i][k].x,w=edges[i][j].y+edges[i][k].y;
				dis[u][v]=min(dis[u][v],w);
				dis[v][u]=min(dis[v][u],w);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i==j || j==k || i==k)continue;
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll a,b;
		cin>>a>>b;
		ll ans=inf;
		for(ll i=0;i<edges[a].size();i++){
			for(ll j=0;j<edges[b].size();j++){
				ll u=edges[a][i].x,v=edges[b][j].x,w=edges[a][i].y+edges[b][j].y;
				if(u==v)ans=min(ans,w);
				else ans=min(ans,w+dis[u][v]);
			}
		}
		cout<<ans+w[a]+w[b]<<'\n';
	}
	return 0;
}