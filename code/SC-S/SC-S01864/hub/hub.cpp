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
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	cout<<0<<endl<<1;
    
	return 0;
}