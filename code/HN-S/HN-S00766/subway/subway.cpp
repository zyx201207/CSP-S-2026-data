#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数。
int w[500005];//从每个地铁站的地铁口走到站厅需要的时间
int x,y;
long long ans;
struct node{
	long long id,t;
	bool operator<(const node&d)const{
		return t>d.t;
	}
};
/*-------地铁线路---------*/
int siz[505];//从每个地铁站的地铁口走到站厅需要的时间
vector<int> line[505];//第 i 条线路经过的地铁站
vector<node> inln[500005];//第 i 个地铁站的线路

bitset<500005> vis;
long long dist[500005];
long long len[500005][55];
static inline long long dijkstra(int id,int to,int tm){
	priority_queue<node> q;
	q.push(node{id,0});
	while(!q.empty()){
		node t=q.top();q.pop();
		if(t.id==to) return t.t;
		dist[t.id]=(vis[t.id]==tm?dist[t.id]:LLONG_MAX);
		if(vis[t.id]==tm||dist[t.id]<t.t) continue;
		else vis[t.id]=tm,dist[t.id]=t.t;
		for(const node&nl:inln[t.id]){
			for(const int&i:line[nl.id]){
				dist[i]=(vis[i]==tm?dist[i]:LLONG_MAX);
				if(dist[i]<=t.t+nl.t) continue;
				q.push(node{i,nl.t+t.t+len[i][nl.id]});
			}
		}
	}
	return -1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>siz[i];
		for(int j=1;j<=siz[i];j++){
			cin>>x>>y;
			line[i].push_back(x);
			inln[x].push_back(node{i,y});
			len[x][i]=y;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y,vis.reset();
		cout<<w[x]+w[y]+dijkstra(x,y,i)<<"\n";
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
