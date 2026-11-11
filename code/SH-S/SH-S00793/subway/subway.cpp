#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=500+10;
const ll M=5e5+500+10;
const ll inf=1e16;
struct node{
	ll t;
	ll w;
};
ll w[M];
ll g[N][N];
vector <node> es[M];  
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	fill(&g[0][0],&g[0][0]+N*N,inf);
	ll c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(ll i=1;i<=m;i++){
		cin >> w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin >> k;
		for(ll j=1;j<=k;j++){
 			ll a,t;
			cin >> a >> t;
			es[a+n].push_back((node){
				i,t
			});
			es[i].push_back((node){
				a+n,t
			});
		}
	} 
	for(ll i=1;i<=n;i++){
		g[i][i]=0;
	}
	for(ll u=n+1;u<=m+n;u++){
		for(ll i=0;i<es[u].size();i++){
			for(ll j=0;j<es[u].size();j++){
				g[es[u][i].t][es[u][j].t]=min(g[es[u][i].t][es[u][j].t],es[u][i].w+es[u][j].w);
			}
		}
	}
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll u,v,ans=inf;
		cin >> u >> v;
		u+=n;
		v+=n;
		for(ll j=0;j<es[u].size();j++){
			for(ll k=0;k<es[v].size();k++){
				ans=min(ans,es[u][j].w+g[es[u][j].t][es[v][k].t]+es[v][k].w);
			}
		}
		u-=n;
		v-=n;
		cout << ans+w[u]+w[v] << "\n"; 
	} 
	return 0;
}
