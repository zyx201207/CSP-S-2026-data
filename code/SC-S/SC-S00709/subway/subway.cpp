#include<bits/stdc++.h>
#define N 500505
//#define int long long
#define endl '\n'
#define PII pair<int,int>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

int c,n,m,d,qq,a[N],w;
bool vis[N];
vector<vector<long long> > dis;
struct edge{
	int v,w;
};
vector<edge> e[N];

void dijkstra(int s){
	priority_queue<PII,vector<PII>,greater<PII> > q;
	memset(vis,0,sizeof(vis));
	dis[s].resize(m+n+2);
	for(int i=1;i<dis[s].size();i++){
		dis[s][i]=INF;
	}
	dis[s][s]=0;
	q.push(make_pair(0,s));
	while(q.size()){
		PII f=q.top();
		q.pop();
		int u=f.second;
		if(vis[u]) continue;
		vis[u]=1;
		for(edge ed:e[u]){
			int v=ed.v,w=ed.w;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}
void bfs(int s){
	queue<PII> q;
	memset(vis,0,sizeof(vis));
	dis[s].resize(m+n+2);
	for(int i=1;i<dis[s].size();i++){
		dis[s][i]=INF;
	}
	dis[s][s]=0;
	q.push(make_pair(0,s));
	int u;
	while(q.size()){
		PII f=q.front();
		q.pop();
		u=f.second;
		if(vis[u]) continue;
		vis[u]=1;
		int len=e[u].size();
		for(int i=0;i<len;i++){
			int v=e[u][i].v;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push(make_pair(dis[s][v],v));
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway6.in","r",stdin);
//	freopen("subway6_my.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&qq);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t;
			scanf("%d%d",&a,&t);
			e[i].push_back(edge{a+n,t});
			e[a+n].push_back(edge{i,t});
			w=t;
		}
	}
	for(int i=1;i<=n+1;i++){
		vector<long long> vec;
		vec.resize(m+n+2);
		dis.push_back(vec);
	}
	if(c>=16&&c<=19){
		for(int i=1;i<=n;i++){
			bfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
//		printf("tiaoshi:%d\n",i);
	}
	for(int i=1;i<=qq;i++){
		int u,v;
		long long ans=INF;
		scanf("%d%d",&u,&v);
		for(edge son1:e[u+n]){
			for(edge son2:e[v+n]){
//				printf("tiaoshi:%d %d %lld",son1,son2,)
				ans=min(ans,dis[son1.v][son2.v]+son1.w+son2.w);
			}
		}
		printf("%lld\n",ans+a[u]+a[v]);
	}
	return 0;
}//知颖你太美