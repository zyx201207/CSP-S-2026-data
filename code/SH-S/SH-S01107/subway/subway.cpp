#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509,M=500009,Q=100009,INF=1e18;
vector<pair<ll,ll> > to[M];
ll f[N][N],qu[Q],qv[Q],g[M];
vector<ll> vans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++)cin>>g[i];
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll a,t;
			cin>>a>>t;
			to[a].push_back(make_pair(i,t));
		}
	}
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++)f[i][j]=INF;
		f[i][i]=0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<to[i].size();j++){
			for(ll k=0;k<to[i].size();k++){
				ll u=to[i][j].first;
				ll v=to[i][k].first;
				ll w=to[i][j].second+to[i][k].second;
				f[u][v]=min(f[u][v],w);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++)cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
//	cout<<"\n";
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
//	for(ll i=1;i<=n;i++){
//		for(ll j=1;j<=n;j++)cout<<f[i][j]<<" ";
//		cout<<"\n";
//	}
//	cout<<"\n";
	for(ll i=1;i<=q;i++){
		ll ans=INF,u,v;
		cin>>u>>v;
		for(ll j=0;j<to[u].size();j++){
			for(ll k=0;k<to[v].size();k++){
				ll x=to[u][j].first;
				ll uw=to[u][j].second;
				ll y=to[v][k].first;
				ll vw=to[v][k].second;
				ans=min(ans,g[u]+uw+f[x][y]+vw+g[v]);
			}
		}
		vans.push_back(ans);
	}
//	freopen("subway7.ans","r",stdin);
//	ll cnt=0;
	for(ll i=1;i<=q;i++){
		cout<<vans[i-1]<<"\n";
//		ll ac;
//		cin>>ac;
//		cout<<ac<<" "<<vans[i-1]<<"\n";
//		cnt+=(vans[i-1]==ac);
	}
//	cout<<q<<" "<<cnt<<"\n";
	return 0;
}
