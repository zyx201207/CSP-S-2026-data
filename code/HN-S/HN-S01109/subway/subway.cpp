#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5,INF=1e9+10;
int c,n,m,d,q,w[N],dist[N],x,y;
struct node{
	int v,w;
};
vector<node> adj[N<<1];
struct edge{
	int u,step;
	operator<(const edge &i) const{
		return step<i.step;
	}
};
priority_queue<edge> que;
void Dijkstra(int x){
	for(int i=1;i<=2*m;i++){
		dist[i]=INF;
	}
	dist[x]=0;
	que.push({x,0});
	while(!que.empty()){
		int u=que.top().u,step=que.top().step;
		//cout<<u<<' ';
		que.pop();
		for(node t:adj[u]){
			if(dist[u]+t.w<dist[t.v]){
				//cout<<t.v<<' ';
				dist[t.v]=dist[u]+t.w;
				que.push({t.v,dist[t.v]});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1,k;i<=n;i++){
		cin>>k;
		for(int j=1,a,t;j<=k;j++){
			cin>>a>>t;
			adj[a].push_back({i+m,t});
			adj[i+m].push_back({a,t});
		}
	}
	while(q--){
		cin>>x>>y;
		Dijkstra(x);
		cout<<dist[y]+w[x]+w[y]<<'\n';
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

0 2 5 20 1
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 3 7 20 1
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
*/
