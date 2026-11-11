#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int c,n,m,d,q;//c为测试点编号，有m个地铁站，有n条地铁线路，最多有d条线路经过 
int used[N];//
vector<PII> g[N];//邻接表 
int dist[N];//最短路 
bool flag[N];//是否被搜素到最短路 
int Dijstra(int x,int y){
	memset(dist,0x3f,sizeof(dist));
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({0,x});
	dist[x]=0;
	for(int i=1;i<=flag.size();i++) flag[i]=0;
	while(!q.empty()){
		PII t=q.top();
		q.pop();
		int vis=g[t].second;
		if(flag[vis]==1) continue;
		flag[vis]=1;
		for(int i=0;i<(int)g[vis].size();i++){
			int j=g[vis][i].first,w=g[vis][i].second;
			if(dist[j]>dist[vis]+w){
				dist[j]=dist[vis]+w;
				q.push({dist[j],j});
			}
		}
	}
	return dist[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&used[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			g[x].push_back({j,y});
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",Dijstra(x,y));
	}
	return 0;
}