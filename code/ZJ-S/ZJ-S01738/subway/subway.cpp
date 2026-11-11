#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const int N=5e5+10;
ll c,n,m,d,q,w[N],dis[N];
vector<pll> g[N];
void dij(ll s){
	memset(dis,0x3f,sizeof(dis));
	queue<ll> q;
	q.push(s);
	dis[s]=0;
	while(q.size()){
		ll u=q.front();
		q.pop();
		for (auto x:g[u]){
			ll v=x.first,w=x.second;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				q.push(v);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (ll i=1;i<=m;i++){
		cin>>w[i];
	}
	ll k;
	for (ll u=m+1;u<=m+n;u++){
		cin>>k;
		ll v,w;
		for (int j=1;j<=k;j++){
			cin>>v>>w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}
	}
	ll s,e;
	while(q--){
		cin>>s>>e;
		dij(s);
		cout<<dis[e]+w[s]+w[e]<<"\n";
	}
	return 0;
}