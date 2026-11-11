#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
struct edge{
	int v,w;
};
vector<edge> G[N];
struct Point{
	int u,dist;
	bool operator < (const Point&p) const{return dist > p.dist}
};
int dist[N];
int bi,n,m,sum,cnt,d,p,ktw[N],ci,ans[N];
bool vis[N],flag;
void djt(int start){
	sum = 0;
	memset(dist,0,sizeof(dist));
	dist[start] = 0;
	vis[start] = true;
	priority_queue<Point> pq;
	pq.push({start,0});
	while(pq.size()){
		int u = pq.top().u;
		int w = pq.top().dist;
		pq.pop();
		if(vis[u] == true) continue;
		vis[u] = true;
		sum+=w;
		cnt++;
		for(auto e : G[u]){
			int v = e.v,w = e.w;
			if(dist[u]+w < dist[v]){
				dist[v] = dist[u]+w;
				pq.push({v,dist[v]});
			}
		}
	}
	flag = cnt == n;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>m>>d>>p;
	while(m--){
		int w;
		cin>>w;
		ktw[ci] = w;
		ci++;
	}
	while(d--){
		int k;
		cin>>k;
		while(k--){
			int v,w;
			cin>>v>>w;
			G[u].push_back(v,w);
			G[v].push_back(u,w);
		}
	}
	while(p--){
		ci = 0;
		int start,en;
		cin>>start>>en;
		djt(start);
		ans[ci] = sum;
		ci++;
	}
	for(int i = 0;i < ci;i++){
		cout<<ans[ci]<<'\n';
	}
}
