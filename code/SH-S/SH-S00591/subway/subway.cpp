#include <bits/stdc++.h>
using namespace std;
struct node{
	int v;
	long long dis;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	}
};
long long c,n,m,d,q;
long long w[500005];
vector<node>g[500505];
vector<node>g2[505];
long long dis[505][505];
int vis[505];
vector<long long>di[500005];
void dij(int x){
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		dis[x][i]=1e18;
	}
	dis[x][x]=0;
	priority_queue<node>q;
	q.push({x,0});
	while(!q.empty()){
		node now=q.top();
		q.pop();
		for(auto z:g2[now.v]){
			int v=z.v;
			long long w=z.dis;
			if(dis[x][v]>dis[x][now.v]+w){
				dis[x][v]=dis[x][now.v]+w;
				if(!vis[v]){
					vis[v]=1;
					q.push({v,dis[x][v]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int num;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin>>a>>t;
			di[a].push_back(t);
			g[a].push_back({i+m,t});
			g[i+m].push_back({a,t});
		}
	}
	for(int i=1;i<=m;i++){
		if(g[i].size()!=1){
			for(int j=0;j<g[i].size();j++){
				for(int k=j+1;k<g[i].size();k++){
					g2[g[i][j].v-m].push_back({g[i][k].v-m,g[i][j].dis+g[i][k].dis});
					g2[g[i][k].v-m].push_back({g[i][j].v-m,g[i][j].dis+g[i][k].dis});
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
	}
	while(q--){
		int a,b;
		cin>>a>>b;
		long long ans=4e18;
		for(int i=0;i<g[a].size();i++){
			for(int j=0;j<g[b].size();j++){
				int x=g[a][i].v-m;
				int y=g[b][j].v-m;
				ans=min(ans,dis[x][y]+di[a][i]+di[b][j]);
			}
		}
		cout<<ans+w[a]+w[b]<<endl;
	}
	return 0;
}
