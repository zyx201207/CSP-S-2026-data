#include<bits/stdc++.h>
using namespace std;
struct node{
	int u;
	long long w;
	friend bool operator<(node a,node b){
		return a.w>b.w;
	}
};
int c,n,m,d,q;
long long w[500050];
long long dis[500050];
vector<node> g[1000050];
bitset<1000050> vis;
int dijkstra(int s,int t){
	priority_queue<node> q;
	q.push((node){s,0});
	for(int i=1;i<=n+m;i++) dis[i]=1e18;
	dis[s]=0;vis.reset();
	while(!q.empty()){
		int u=q.top().u;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].u,w=g[u][i].w;
			if((long long)dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				if(!vis[v]) q.push((node){v,dis[v]});
			}
		}
	}return dis[t];
}int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",w+i);
	}for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;scanf("%d%d",&a,&t);
			g[a].push_back((node){m+i,t});
			g[m+i].push_back((node){a,t});
		}
	}
	while(q--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%lld\n",(long long)dijkstra(a,b)+w[a]+w[b]);
	}//for(int i=1;i<=n+m;i++){
	//	for(int j=0;j<g[i].size();j++){
	//		printf("@%d %d",g[i][j].u,g[i][j].w);
	//	}puts("");
	//}for(int i=1;i<=n+m;i++) printf("%d ",dis[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
