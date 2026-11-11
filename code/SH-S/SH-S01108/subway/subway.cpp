#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e2+10;
const ll M=5e5+10;
const ll INF=1e18;
ll c,n,m,d,q;
ll w[M];
ll dis[N][N];
vector<pair<ll,ll> > s[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		while(k--){
			ll sta,t;
			cin>>sta>>t;
			s[sta].push_back({i,t});
		}
		for(ll j=1;j<=n;j++) dis[i][j]=INF;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<s[i].size();j++){
			ll lns1_u=s[i][j].first,lns1_w=s[i][j].second;
			for(ll k=j+1;k<s[i].size();k++){
				ll lns2_u=s[i][k].first,lns2_w=s[i][k].second;
				dis[lns1_u][lns2_u]=dis[lns2_u][lns1_u]=lns1_w+lns2_w;
			}
		}
	}
	for(ll i=1;i<=n;i++) dis[i][i]=0;
	for(ll k=1;k<=n;k++){
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		ll u,v;
		cin>>u>>v;
		ll minn=INF;
		for(auto i:s[u]){
			ll lns_u=i.first,lns_w1=i.second;
			for(auto j:s[v]){
				ll lns_v=j.first,lns_w2=j.second;
				minn=min(minn,dis[lns_u][lns_v]+lns_w1+lns_w2);
			}
		}
		cout<<minn+w[u]+w[v]<<"\n";
	}
	return 0;
}
