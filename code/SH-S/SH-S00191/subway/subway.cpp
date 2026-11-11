#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll N=509;
const ll D=29;
const ll M=500009;
const ll INF=1e18;
ll c,n,m,d,q,k[N],w[M],f[N][N];
vector<pll> G[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		cin>>k[i];
		for(ll j=1;j<=k[i];j++){
			ll a,t;cin>>a>>t;
			G[a].push_back({i,t});
		}
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=n;j++)
			if(i!=j) f[i][j]=INF;
	for(ll i=1;i<=m;i++)
		for(auto p:G[i])
			for(auto q:G[i]){
				ll j=p.first,k=q.first,t1=p.second,t2=q.second;
				if(j==k) continue;
				f[j][k]=min(f[j][k],t1+t2);
			}
	for(ll k=1;k<=n;k++)
		for(ll i=1;i<=n;i++)
			for(ll j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	for(ll i=1;i<=q;i++){
		ll u,v,ans=INF;
		cin>>u>>v;
		for(auto p:G[u])
			for(auto q:G[v]){
				ll j=p.first,k=q.first,t1=p.second,t2=q.second;
				ans=min(ans,f[j][k]+t1+t2);
			}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return 0;
}
