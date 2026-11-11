#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll c,n,m,d,q,tot,dis[21000],ans[1100][1100],w[21000],he[21000];
bool vis[21000];
struct edge{
	ll v,w,la;
}e[1100000];
priority_queue<pii,vector<pii>,greater<pii>> p;
queue<ll> b;
void add(ll u,ll v,ll w){
	e[++tot]={v,w,he[u]};he[u]=tot;
	e[++tot]={u,w,he[v]};he[v]=tot;
}
void dij(ll s){
	for(int i=1;i<=n+m;i++)vis[i]=0,dis[i]=inf;
	dis[s]=0;
	p.push({0,s});
	while(!p.empty()){
		pii i=p.top();p.pop();
		ll d=i.first,u=i.second;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=he[u];i;i=e[i].la){
			ll v=e[i].v,w=e[i].w;
			if(vis[v])continue;
			if(dis[v]>d+w){
				dis[v]=d+w;
				p.push({dis[v],v});
			}
		}
	}
}
void bfs(ll s){
	for(int i=1;i<=n+m;i++)vis[i]=0,dis[i]=inf;
	dis[s]=0;
	b.push(s);
	while(!b.empty()){
		ll u=b.front();
		b.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=he[u];i;i=e[i].la){
			ll v=e[i].v;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				b.push(v);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,x,v,w;i<=n;i++){
		cin>>x;
		while(x--){
			cin>>v>>w;
			add(i+m,v,w);
		}
	}
	if(c<=11){
		for(int i=1;i<=m;i++){
			dij(i);
			for(int j=1;j<=m;j++){
				ans[i][j]=dis[j];
			}
		}
		for(int i=1,s,t;i<=q;i++){
			cin>>s>>t;
			cout<<w[s]+w[t]+ans[s][t]<<'\n';
		}
	}else{
		ll x=e[1].w;
		for(int i=1,s,t;i<=q;i++){
			cin>>s>>t;
			bfs(s);
			cout<<dis[t]*x+w[s]+w[t]<<'\n';
		}
	}
	return 0;
}//rp++ rp++ rp++ rp++ rp++