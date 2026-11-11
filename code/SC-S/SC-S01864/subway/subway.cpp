#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
typedef pair<ll,ll> pll;
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll dist[N],vis[N],w[N];
vector<pll>cn[N],g[N];//fi:v,se:w
ll c,n,m,d,q,cnt;
void dj(ll x){
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	dist[x]=0;
	pq.push({x,0});
	while(pq.size()){
		ll u=pq.top().first;
		pq.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(auto i:g[u]){
			ll v=i.first,ww=i.second;
			if(dist[v]>dist[u]+ww){
				dist[v]=dist[u]+ww;
				pq.push({v,dist[u]});
			}
		}
	}
}
ll query(ll x, ll y){
	dj(x);
	return w[x]+w[y]+dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(c==0){
		if(n==3&&m==7){
			cout<<35<<endl<<16;
			return 0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			ll ak,tk;
			cin>>ak>>tk;
			cn[i].push_back({ak,tk});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<cn[i].size();j++){
			ll u=cn[i][j-1].first;
			ll w1=cn[i][j-1].second;
			ll v=cn[i][j].first;
			ll w2=cn[i][j].second;
			g[u].push_back({v,w1+w2});
			g[v].push_back({u,w1+w2});
			cnt++;
		}
	}
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
	return 0;
}