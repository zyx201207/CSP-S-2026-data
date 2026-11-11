#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
const int N=2e6+5,inf=1e9;
int cid,t,n,dis[N];
long long d,x[N],ans,cnt[N];
bool vis[N];
vector <int> g[N];
void Dijkstra(int s){
	for(int i=s+1;i<=n;i++) vis[i]=0,dis[i]=inf;
	priority_queue <PII,vector<PII>,greater<PII>> q;
	q.push({0,s}),dis[s]=0,cnt[s]=1,vis[s]=1;
	while(!q.empty()){
		PII x=q.top();q.pop();
		int u=x.second,nowd=x.first;
		if(nowd>dis[u]) continue;
		for(auto v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1,cnt[v]=cnt[u];
				if(!vis[v]) vis[v]=1,q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1) cnt[v]++;
		}
	}
	for(int e=s+1;e<=n;e++) if(cnt[e]==2) ans++;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cid,&t);
	while(t--){
		scanf("%d%lld",&n,&d);ans=0;
		for(int i=1;i<=n;i++) cnt[i]=0;
		for(int i=1;i<=n;i++) scanf("%lld",x+i),g[i].clear();
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d) g[i].push_back(j);
				else break;
			}
		for(int i=1;i<=n;i++) Dijkstra(i);
		printf("%lld\n",ans);
	}
	return 0;
}