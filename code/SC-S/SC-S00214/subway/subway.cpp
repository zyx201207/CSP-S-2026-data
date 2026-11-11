#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+505,M=5e5+5;
const ll inf=1e18;
int c,n,m,d,Q,w[N],s,e;
struct node{
	int v,w;
};
vector<node> G[N];
struct edge{
	int u;
	ll dis;
	bool operator<(const edge &a) const{
		return a.dis<dis;
	}
};
priority_queue<edge> q;
ll dis[N];
bool vis[N],f1,f2;
ll dij(int start,int end){
	for(int i=1;i<=n+m;i++){
		dis[i]=inf,vis[i]=0;
	}
	q.push({start,0});
	dis[start]=0;
	while(!q.empty()){
		int u=q.top().u;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:G[u]){
			int v=x.v,w=x.w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push({v,dis[v]});
			}
		}
	}
	return dis[end];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x>2) f1=1;
		for(int j=1;j<=x;j++){
			int u,v;cin>>u>>v;
			G[i].push_back({u+n,v});
			G[u+n].push_back({i,v});
		}
	}
	for(int i=1;i<=Q;i++){
		cin>>s>>e;
		ll ans=w[s]+w[e];
		int add=0;
		ans+=dij(s+n,e+n);
		cout<<ans<<"\n";
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/