#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define PLL pair<ll,ll>
#define fi first
#define se second
const ll M=5e5+10;
const ll N=5e2+10;
const ll P=1e9+7;
ll c,n,m,d,q;
ll w[M];
vector<PLL> rtos[M];
ll g[N][N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			g[i][j]=1e18;
		}
		g[i][i]=0;
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll u,w;
			cin>>u>>w;
			for(auto it:rtos[u]){
				ll v=it.fi,dis=it.se;
				g[i][v]=g[v][i]=min(g[i][v],dis+w);
			}
			rtos[u].push_back({i,w});
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll res=1e18;
		for(auto it:rtos[u]){
			for(auto jt:rtos[v]){
				res=min(res,it.se+jt.se+g[it.fi][jt.fi]);
			}
		}
		cout<<res+w[u]+w[v]<<"\n";
	}
	return 0;
}
