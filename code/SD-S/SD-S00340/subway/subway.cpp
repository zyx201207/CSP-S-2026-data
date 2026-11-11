#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	ll v,w;
	friend bool operator <(node aa,node bb){
		return aa.w>bb.w;
	}
};
const ll maxx=1e6+1005;
vector<node> g[maxx];
ll w[maxx];
ll dis[maxx];
vector<ll> a[505],t[505];
bool vis[maxx];
ll c,n,m,d,q;
void add(ll u,ll v,ll w){
	g[u].push_back((node){v,w});
	g[v].push_back((node){u,w});
	return;
}
void dij(ll k){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[k]=0;
	priority_queue<node> pq;
	pq.push((node){k,0});
	while(!pq.empty()){
		node fr=pq.top();
		pq.pop();
		ll u=fr.v;
		if(vis[u]) continue;
		vis[u]=1;
		int siz=g[u].size();
		for(int i=0;i<siz;i++){
			ll v=g[u][i].v;
			ll w=g[u][i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				pq.push((node){v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++) cin>>w[i];
	for(ll i=1;i<=m;i++) add(n+m+i,n+i,w[i]);
	for(ll i=1;i<=n;i++){
		a[i].push_back(0);
		t[i].push_back(0);
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		} 
		for(ll j=1;j<=k;j++) add(a[i][j]+n,i,t[i][j]);
	}
	for(ll i=1;i<=q;i++){
		ll pp,qq;
		cin>>pp>>qq;
		dij(pp+n+m);
		cout<<dis[qq+n+m]<<'\n';
	}
	return 0;
}
