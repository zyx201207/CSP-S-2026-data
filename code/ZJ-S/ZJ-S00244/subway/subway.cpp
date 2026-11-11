#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5+5,inf=1e18;
ll wk,n,m,d,q,w[N],dis[505][2005],tot,dist[40005];
bool vis[N];
struct node{
	ll dis,x;
	bool operator<(const node&o)const{
		return dis>o.dis;
	}
};
struct edge{
	ll x,w;
};
vector<edge> G[N];
inline void dijkstra(int s,ll dis[]){
	for(int i=1;i<=tot;i++) dis[i]=inf,vis[i]=0;
	priority_queue<node> q;
	q.push({0,s});dis[s]=0;
	while(q.size()){
		node u=q.top();q.pop();
		if(vis[u.x]) continue;
		vis[u.x]=1;
		for(auto v:G[u.x]){
			if(dis[v.x]>dis[u.x]+v.w){
				dis[v.x]=dis[u.x]+v.w;
				q.push({dis[v.x],v.x});
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>wk>>n>>m>>d>>q;tot=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		ll len;cin>>len;++tot;
		for(int j=1;j<=len;j++){
			ll x,y;cin>>x>>y;
			G[x].push_back({tot,y});
			G[tot].push_back({x,y});
		}
	}
	if(m<=1000 || n<=2) for(int i=1;i<=n;i++) dijkstra(i,dis[i]);
	ll tmp=q;
	while(q--){
		ll x,y;cin>>x>>y;
		if(tmp<=2000){
			dijkstra(x,dist);
			cout<<dist[y]+w[x]+w[y]<<"\n";
		}else{
			ll ans=inf;
			for(int i=1;i<=n;i++) ans=min(ans,dis[i][x]+dis[i][y]);
			cout<<ans+w[x]+w[y]<<"\n";
		}
	}
	return 0;
}
/*
建边对于每个点跑一次dijkstra是m^2 log m的
但是还是没有用上d<=20这个性质先打后面两题的暴力再回来写 
*/
