#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int c,n,m,d,q,a[N],dis[N];
int cnt;
bool vis[N];
struct node{
	int v,w;
};
struct edge{
	int u,dis;
	bool operator <(const edge &o)const{
		return dis>o.dis;
	}
};
vector<node> g[N];
void solve(){
	int x,y;
	cin>>x>>y;
	for(int i=1;i<=n+m;i++){
		dis[i]=1e9;
		vis[i]=0;
	}
	priority_queue<edge> q;
	q.push({x,0});
	dis[x]=0;
	while(q.size()){
		int cur=q.top().u;
		q.pop();
		if(vis[cur]) continue;
		vis[cur]=1;
		for(int i=0;i<g[cur].size();i++){
			int v=g[cur][i].v;
			int w=g[cur][i].w;
			if(dis[cur]+w<dis[v]){
				dis[v]=dis[cur]+w;
				q.push({v,dis[v]});
			}
		}
	}
	cout<<dis[y]+a[x]+a[y]<<"\n";
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}cnt=m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,w;
			cin>>v>>w;
			g[v].push_back({i+m,w});
			g[i+m].push_back({v,w});
		}
	}
	while(q--){
		solve();
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
