#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pir pair<int,int>
#define x first
#define y second
const int N=5e5+10,M=N*21,Q=1e5+10;
int c,n,m,d,q,a[N];
int ans[N];
struct node{
	int x,y;
	int id;
}qu[Q];
vector<pir>graph[M];
int dist[N];//优化空间，仅保留站台的时间 
bool vis[M];
struct Node{
	int v,w;
	friend bool operator<(const Node&a,const Node&b){
		return a.w>b.w;
	}
};
priority_queue<Node>heap;
void solve(int u){//最短路 
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	dist[u]=0;
	heap.push({u,0});
	while(heap.size()){
		Node f=heap.top();
		heap.pop();
		u=f.v;
		int t=f.w;
		if(vis[u])continue;
		vis[u]=1;
		for(int i=0;i<graph[u].size();i++){
			int v=graph[u][i].x,w=graph[u][i].y;
			if(v<=m){//是原先的站台 
				if(dist[v]>t+w){
					dist[v]=min(dist[v],t+w);
					heap.push({v,dist[v]});
				}
			}
			else heap.push({v,t+w});
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	int u=m;//新节点编号 
	for(int i=1,k;i<=n;i++){//建图 
		cin>>k;
		int pre=-1,v,w;
		while(k--){
			cin>>v>>w;
			u++;//更新新节点编号
			if(~pre){//不是起始站，和前一站连边 
				graph[pre].push_back({u,0});
				graph[u].push_back({pre,0});
			} 
			//和当前站台连边
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
			pre=u;//更新上一站节点编号 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qu[i].x>>qu[i].y;
		qu[i].id=i;
	}
	sort(qu+1,qu+q+1,[](const node&a,const node&b){
		return a.x<b.x;
	});//排序优化 
	u=-1;//起点 
	for(int i=1;i<=q;i++){
		if(qu[i].x!=u){//重新跑一遍最短路 
			u=qu[i].x;
			solve(u);
		}
		ans[qu[i].id]=dist[qu[i].y]+a[qu[i].x]+a[qu[i].y];
	} 
	for(int i=1;i<=q;i++)cout<<ans[i]<<"\n";
	return 0;
} 
/*
先建立所有站台节点
然后根据地铁线路建边
相邻两站建边，边权0
站与站台建边，边权t
最后求x->y最短路，加上起终点权
最短路Dijkstra，实现时间O(qmlogm) 
*/
