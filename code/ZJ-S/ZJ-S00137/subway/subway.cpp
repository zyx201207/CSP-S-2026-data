#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
const int N=1e6+5;
int c,n,m,d,q,w[N<<1],k[N<<1],head[N<<1],cnt=0,ans=0,dis[N<<1],vis[N<<1],tot;
struct node{
	int id,val;
};
inline bool operator<(node x,node y){
	return x.val>y.val;
}
struct edge{
	int v,nxt,w;
}e[N<<1];
inline void add(int u,int v,int w){
	e[++cnt].nxt=head[u];
	e[cnt].v=v;
	e[cnt].w=w;
	head[u]=cnt;
}
inline void dijkstra(int s,int t){
	for(int i=1;i<=tot;i++) dis[i]=inf,vis[i]=0;dis[s]=0;
	priority_queue<node> qp;qp.push({s,0});
	while(!qp.empty()){
		node gg=qp.top();qp.pop();
		int u=gg.id;
		if(vis[u]) continue;
		vis[u]=1;
		if(u==t){
			cout<<dis[u]+w[s]+w[t]<<'\n';
			return ;
		}
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				qp.push({v,dis[v]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;tot=m;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];int pp=tot+1;
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			add(a,++tot,t);
			add(tot,a,t);
		}
		for(int j=pp;j<=tot;j++){
			for(int k=pp+1;k<=tot;k++){
				add(j,k,0),add(k,j,0);
			}
		}
	}
	while(q--){
		int s,t;cin>>s>>t;
		dijkstra(s,t);
	}
	return 0;
}