#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define fi first
#define se second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll maxn=509;
const ll maxm=500009;
const ll inf=1e18;
ll Cid,n,m,d,q,w[maxm],dst[maxn][maxn];
vector<pll> vec[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>Cid>>n>>m>>d>>q;
	rep(i,1,m)	cin>>w[i];
	rep(i,1,n){
		ll k;
		cin>>k;
		rep(id,1,k){
			ll a,t;
			cin>>a>>t;
			vec[a].push_back(mk(i,t));
		}
	}
	rep(i,1,n)	rep(j,1,n)
		dst[i][j]=(i==j?0:inf);
	rep(id,1,m){
		ll sz=vec[id].size();
		rep(a,0,sz-1)rep(b,a+1,sz-1){
			ll u=vec[id][a].fi,v=vec[id][b].fi;
			ll w=vec[id][a].se+vec[id][b].se;
			dst[u][v]=min(dst[u][v],w);
			dst[v][u]=min(dst[v][u],w);
		}
	}
	rep(k,1,n)rep(i,1,n)rep(j,1,n)
		dst[i][j]=min(dst[i][j],dst[i][k]+dst[k][j]);
	rep(qid,1,q){
		ll u,v;
		cin>>u>>v;
		ll ans=inf;
		for(pll pru:vec[u])for(pll prv:vec[v]){
			ans=min(ans,pru.se+prv.se+dst[pru.fi][prv.fi]);
		}
		ans+=w[u]+w[v];
		cout<<ans<<'\n';
	}
	return 0;
}
