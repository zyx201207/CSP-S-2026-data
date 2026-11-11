#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=5005,inf=1e9;
int c,t,n,k,ans,dis[N][N];
vector <int> g[N];
bool vis[N],flag[N],v[N];
void Dijkstra(int s){
	for(int i=1;i<=n;i++) vis[i]=0,dis[s][i]=inf;
	priority_queue <PII,vector<PII>,greater<PII>> q;
	q.push({0,s}),dis[s][s]=0,vis[s]=1;
	while(!q.empty()){
		PII x=q.top();q.pop();
		int u=x.second,nowd=x.first;
		if(nowd>dis[s][u]) continue;
		for(auto v:g[u]){
			if(dis[s][v]>dis[s][u]+1){
				dis[s][v]=dis[s][u]+1;
				if(!vis[v]) vis[v]=1,q.push({dis[s][v],v});
			}
		}
	}
}
void dfs2(int u,int fa){
	flag[u]=1;
	for(auto v:g[u]) if(vis[v]&&v!=fa) dfs2(v,u);
}
void check(){
	int cnt=0;
	for(int i=1;i<=n;i++) flag[i]=0;
	for(int i=1;i<=n;i++){
		if(vis[i]&&!flag[i]){
			cnt++;
			if(cnt>2) return ;
			dfs2(i,0);
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		int now=inf;
		for(int j=1;j<=n;j++) if(vis[j]) now=min(now,dis[i][j]);
		maxx=max(maxx,now);
	}
	ans=min(ans,maxx);
}
void dfs1(int i,int cnt){
	if(n-i+1<k-cnt) return ;
	if(n-i+1==k-cnt){
		for(int j=i;j<=n;j++) vis[j]=1;
		check();return ;
	}
	if(i==n+1){check();return ;}
	if(cnt<k) vis[i]=1,dfs1(i+1,cnt+1);
	vis[i]=0,dfs1(i+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);ans=n;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++){
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++) Dijkstra(i);
		dfs1(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
