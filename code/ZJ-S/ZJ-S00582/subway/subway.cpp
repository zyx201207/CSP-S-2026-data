#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=500+10,M=1e6+10;
ll c,n,m,d,q,k[N],a,t,f[N][N],w[M];
vector<pii>g[M];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];f[i][i]=0;
		for(int j=0;j<k[i];++j) cin>>a>>t,g[a].pb({i,t});
	}
	for(int i=1;i<=m;++i){
		int gh=g[i].size(),u,v;
		for(int j=0;j<gh;++j)
			for(int k=j+1;k<gh;++k){
				u=g[i][j].first,v=g[i][k].first;
				f[v][u]=f[u][v]=min(f[u][v],g[i][j].second+g[i][k].second);
			}
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(pii b:g[x])
			for(pii e:g[y])
				ans=min(ans,f[b.first][e.first]+b.second+e.second);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
