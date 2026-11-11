#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vec vector
#define pii pair<int,int>
#define pb push_back
int n,m,d,q;
int a[505][1300],t[505][1300];
int cnt[505][1300];
struct node{
	int to,w;
};
vec<node>G[505];
int dis[505];
bool vis[505];
 
inline void dijkstra(int x,int y){
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,x});
	dis[x]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto &e:G[u]){
			if(dis[e.to]>dis[u]+e.w){
				dis[e.to]=dis[u]+e.w;
				q.push({e.to,dis[e.to]});
			}
		}
	}
}
inline void Solve(int _){
	cin>>n>>m>>d>>q;
	int w[m+100];
	int ppp;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cin>>a[i][1]>>t[i][1];
		for(int j=2;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			ppp=t[i][j];
			G[a[i][j-1]].pb({a[i][j],1});
			G[a[i][j]].pb({a[i][j-1],1});
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		dijkstra(x,y);
		cout<<dis[y]*ppp<<"\n";
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int _;
	cin>>_;
	Solve(_);
	return 0;
}

