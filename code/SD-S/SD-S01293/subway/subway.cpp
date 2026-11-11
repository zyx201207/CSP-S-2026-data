#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
struct Node{
	int v,w;
};
int c,n,m,dm,q;
int w[500010];
vector<Node>d[500010];
vector<Node>G[510];
int dis[510][510];
int vis[510];
void dij(int x){
	for(int i=1;i<=n;i++) vis[i]=0;
	priority_queue<pair<int,int> >Q;
	dis[x][x]=0;
	Q.push({0,x});
	while(!Q.empty()){
		int u=Q.top().second;
		Q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(Node v:G[u]){
			if(dis[x][v.v]>dis[x][u]+v.w){
				dis[x][v.v]=dis[x][u]+v.w;
				Q.push({-dis[x][v.v],v.v});
			}
		}
	}
}
signed main(){
	fast;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dm>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			d[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<d[i].size();j++){
			for(int k=j+1;k<d[i].size();k++){
				G[d[i][j].v].push_back({d[i][k].v,d[i][j].w+d[i][k].w});
				G[d[i][k].v].push_back({d[i][j].v,d[i][j].w+d[i][k].w});
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) dis[i][j]=1e18;
		dij(i);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<dis[i][j]<<' ';
//		}
//		cout<<endl;
//	}
	while(q--){
		int xr,yr,ans=1e18;
		cin>>xr>>yr;
		for(int j=0;j<d[xr].size();j++){
			for(int k=0;k<d[yr].size();k++){
				ans=min(ans,dis[d[xr][j].v][d[yr][k].v]+d[xr][j].w+d[yr][k].w+w[xr]+w[yr]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

