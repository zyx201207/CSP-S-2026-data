#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[600];
vector<pair<int,int> > e[500005];
int dis[4005][4005];
int vis[4005];
struct node{
	int x,y;
};
priority_queue<node> q;
bool operator < (node x,node y){
	return x.y>y.y;
}
void dijkstra(int s){
	for(int i=1;i<=n+m;i++){
		dis[s][i]=1e9;
		vis[i]=0;
	}
	dis[s][s]=0;
	q.push({s,0});
	while(q.size()){
		auto f=q.top();
		q.pop();
		int w=f.x,v=f.y;
		if(vis[w])continue;
		vis[w]=1;
		for(auto i:e[w]){
			int to=i.first,vi=i.second;
			if(dis[s][to]>v+vi){
				dis[s][to]=v+vi;
				q.push({to,dis[s][to]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int pp=0;
		cin>>pp;
		for(int j=1;j<=pp;j++){
			int ai,bi;
			cin>>ai>>bi;
			e[i+m].push_back({ai,bi});
			e[ai].push_back({i+m,bi});
		}
	}
	for(int i=1;i<=m;i++){
		dijkstra(i);
	}
	for(int i=1;i<=p;i++){
		int xx,yy;
		cin>>xx>>yy;
		cout<<dis[xx][yy]+w[xx]+w[yy]<<'\n';
	}
}
