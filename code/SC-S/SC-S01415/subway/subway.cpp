#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505;
const int M = 5e5+5;
const ll inf = 1e18;
int c,n,m,d,q;
int w[M];
vector<pair<int,ll>>g[N+M];
ll dis[N+M];
bool vis[N+M];
void djstra(int s){
	fill(dis+1,dis+1+n+m,inf);
	memset(vis,0,sizeof(vis));
	priority_queue<pair<ll,int>>q;
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(auto [y,w]:g[x]){
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push({-dis[y],y});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i+m].push_back({a,t});
			g[a].push_back({i+m,t});
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		djstra(x);
//		for(int i=1;i<=n+m;i++)
//			cout<<dis[i]<<' ';
//		cout<<'\n';
		cout<<dis[y]+w[x]+w[y]<<'\n';
	}
	return 0;
}