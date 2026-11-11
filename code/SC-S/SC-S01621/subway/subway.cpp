#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
typedef long long ll;
using namespace std;
ll c,n,m,d,q;ll w[500001],dis[501][501];
vector<pair<ll,ll>> dy[500001];
int main(){
	freopen("subway.in","r",stdin);freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;for(ll i=1;i<=m;i++)cin>>w[i];
	for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)dis[i][j]=dis[j][i]=1e18;
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		while(k--){
			ll p,z;cin>>p>>z;
			dy[p].push_back({i,z});
		}
	}
	for(ll i=1;i<=m;i++)for(ll j=0;j<dy[i].size();j++)
		for(ll k=j+1;k<dy[i].size();k++){
			ll u=dy[i][j].first,v=dy[i][k].first,
				a=dy[i][j].second,b=dy[i][k].second;
			dis[u][v]=dis[v][u]=min(dis[u][v],a+b);
		}
	for(ll k=1;k<=n;k++)for(ll i=1;i<=n;i++)for(ll j=1;j<=n;j++)
		dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--){
		ll x,y;cin>>x>>y;ll ans=1e18;
		for(ll i=0;i<dy[x].size();i++)for(ll j=0;j<dy[y].size();j++){
			auto xs=dy[x][i];auto ys=dy[y][j];
			ll a=xs.first,b=ys.first,c=xs.second,d=ys.second;
			ans=min(ans,dis[a][b]+c+d);
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}