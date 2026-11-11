#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[505],vis[505],x,y,k[20005],a[505][20005],t[505][20005],dist[505];
vector<vector<pair<int,int> > > g(505);
struct node{
	int id,jl;
};
void bfs(int x){
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++) dist[i]=1e14;
	dist[x]=0;
	queue<node> q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.front().id;
		q.pop();
		if(vis[u]) continue;
		for(int i=0;i<(int)g[u].size();i++){
			int v=g[u][i].first;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push({v,dist[v]});
			}
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				g[a[i][j-1]].push_back({a[i][j],k[i]});
				g[a[i][j]].push_back({a[i][j-1],k[i]});
			}
		}
	}
	while(q--){
		cin>>x>>y;
		bfs(x);
		cout<<w[x]+w[y]+dist[y]<<endl;
	}
	return 0;
}
