#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=505,M=5e5+5;
int c,n,m,d,q;
int w[M];
struct Edge{
	int target,tim;
};
vector<Edge>g[M];
struct Node{
	int idx;
	ll dis;
	bool operator < (const Node& Other)const{
		return dis>Other.dis;
	}
};
priority_queue<Node>pq;
ll dis[N+M];
ll dijkstra(int Start,int End){
	fill(dis,dis+n+m+3,1e18);
//	memset(dis,0x3f,sizeof(dis));
	while(!pq.empty())pq.pop();
	pq.push({Start,0});
	dis[Start]=0;
	while(!pq.empty()){
		const int u=pq.top().idx;
		const ll d=pq.top().dis;
		pq.pop();
		if(d>dis[u])continue;
//		if(u==10)cout<<"Right"<<dis[u]<<"\n";
		if(u==End)return dis[u];
		for(Edge E:g[u]){
			const int v=E.target,w=E.tim;
//			if(v==10)cout<<"Yes:"<<u<<" "<<dis[u]<<" "<<d+w<<" "<<dis[v]<<"\n";
			if(d+w<dis[v]){
				dis[v]=d+w;
//				if(v==10)cout<<"Yes:"<<u<<" "<<dis[u]<<" "<<d+w<<" "<<dis[v]<<"\n";
				pq.push({v,dis[v]});
			}
		}
	}
//	for(int i=1;i<=n+m;i++)cout<<dis[i]<<" ";
//	cout<<"\n";
	return dis[End];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("subway3.in","r",stdin);
//	freopen("subway3.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[a].emplace_back((Edge){m+i,t});
			g[m+i].emplace_back((Edge){a,t});
		}
	}
//	for(int u=1;u<=n+m;u++){
//		cout<<u<<":";
//		for(Edge E:g[u]){
//			int v=E.target,w=E.tim;
//			cout<<v<<","<<w<<" ";
//		}
//		cout<<"\n";
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<1ll*w[x]+w[y]+dijkstra(x,y)<<"\n";
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/