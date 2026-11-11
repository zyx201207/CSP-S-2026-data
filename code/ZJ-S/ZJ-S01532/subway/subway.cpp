#include<bits/stdc++.h>
using namespace std;
#define PII pair<long long,int>
const int N=505,M=5e5+5;
const long long inf=1e18;
int cid,n,m,d,q,w[M],k[N];
long long dis[N][N],dd[N][N],t[M][25];
vector <int> vec[M];
bool vis[N];
struct node{
	int v;
	long long w;
};
vector <node> g[N];
void Dijkstra(int s){
	for(int i=1;i<=n;i++) vis[i]=0,dis[s][i]=inf;
	priority_queue <PII,vector<PII>,greater<PII>> q;
	q.push({0,s}),dis[s][s]=0,vis[s]=1;
	while(!q.empty()){
		PII x=q.top();q.pop();
		int u=x.second,nowd=x.first;
		if(nowd>dis[s][u]) continue;
		for(auto p:g[u]){
			int v=p.v;
			long long w=p.w;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				if(!vis[v]) vis[v]=1,q.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&cid,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",w+i);
	for(int i=1;i<=n;i++){
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++){
			int a;scanf("%d",&a);
			vec[a].push_back(i);
			int l=vec[a].size();
			scanf("%lld",&t[a][l]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dd[i][j]=inf;
	for(int i=1;i<=m;i++)
		for(int j=0;j<vec[i].size();j++)
			for(int k=j+1;k<vec[i].size();k++)
				dd[vec[i][j]][vec[i][k]]=dd[vec[i][k]][vec[i][j]]=min(dd[vec[i][j]][vec[i][k]],t[i][j+1]+t[i][k+1]);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(dd[i][j]!=inf) g[i].push_back({j,dd[i][j]}),g[j].push_back({i,dd[i][j]});
	for(int i=1;i<=n;i++) Dijkstra(i);
	while(q--){
		int s,e;scanf("%d%d",&s,&e);
		long long ans=inf;
		for(int i=0;i<vec[s].size();i++)
			for(int j=0;j<vec[e].size();j++)
				ans=min(ans,dis[vec[s][i]][vec[e][j]]+t[s][i+1]+t[e][j+1]);
		printf("%lld\n",ans+w[s]+w[e]);
	}
	return 0;
}
