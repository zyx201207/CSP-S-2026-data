#include<bits/stdc++.h>
using namespace std;
constexpr int M=2e4;
constexpr int N=507;

int c,n,m,d,q,T;
int w[M];//每个地铁口到站厅的时间 
int k[N];//每个地铁线经过的站数
int a[N][M];//第i个地铁线经过的每个站
int t[N][M];//a[i][j]地铁站从站厅到地铁线i站台的时间 
struct node{
	int v,w;
};
vector<node> g[M+N];
bool operator<(node aa,node bb){
	return aa.w>bb.w;
}
int dij(int s,int endd){
	int dist[M];
	priority_queue<node> pq;
	for(int i=1;i<=n;i++){
		dist[i]=1e9;
	}dist[s]=0;
	pq.push({s,0});
	while(!pq.empty()){
		int uu=pq.top().v;
		pq.pop();
		for(auto i:g[uu]){
			if(dist[i.v]>dist[uu]+i.w){
				dist[i.v]=dist[uu]+i.w;
				pq.push(i);
			}
		}
	}return dist[endd];
}
void solve(int x,int y){
	int ans=w[x]+w[y];
	cout<<dij(x,y)+ans<<"\n";
}
bool vis[N+M];int dist[M];
int bfs(int sta,int en){
	queue<int> q;
	q.push(sta);
	while(!q.empty()){
		int f=q.front();
		q.pop();
		for(auto i:g[f]){
			if(!vis[i.v]){
				q.push(i.v);
				dist[i.v]=dist[f]+1;
			}
		}
	}return dist[en];
}
void solveb(int x,int y){
	cout<<bfs(x,y)*T+w[x]+w[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}int tmn=m+n;
	int tmm=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		tmm+=x;
		for(int j=1;j<=x;j++){
			int fir,sec;
			T=sec;
			cin>>fir>>sec;
			g[m+i].push_back({fir,sec});
			g[fir].push_back({m+i,sec});
		}
	}n=tmn;
	m=tmm;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(c>=12&&c<=19)solveb(x,y);
		else solve(x,y);
	}
	return 0;
}
