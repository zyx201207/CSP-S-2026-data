#include<bits/stdc++.h>
#define LL long long
#define M (int)(5e5+5)
#define PLI pair<LL,int>
#define st first
#define nd second
using namespace std;
int fa[M],w[M]/*d(地铁口-站厅)*/,t[M][505]/*站厅-站台*/;
vector<int>l[505]/*地铁线路*/;
LL dis[M];
void dijkstra(int s){
	priority_queue<PLI/*-dis,id*/>q;
	memset(dis,0x6f,sizeof(dis));
	q.push({0,s});dis[s]=0;
	while(!q.empty()){
		PLI p=q.top();q.pop();
		LL d=-p.st;int u=p.nd;
		if(d>dis[u])continue;
		int f=fa[u];
		for(int v:l[f]){
			if(dis[u]+t[u][f]+t[v][f]<dis[v]){
				dis[v]=dis[u]+t[u][f]+t[v][f];
				q.push({-dis[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;//地铁线路数n<=500、地铁站数m<=5e5、每个地铁站最多被d<=20条线路经过，出行计划数q<=1e5
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,t1;scanf("%d%d",&a,&t1);
			fa[a]=i;
			l[j].push_back(a);
			t[a][i]=t1;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;scanf("%d%d",&x,&y);
		dijkstra(x);
		printf("%lld\n",dis[y]+w[x]+w[y]);
	}
	return 0;
}
