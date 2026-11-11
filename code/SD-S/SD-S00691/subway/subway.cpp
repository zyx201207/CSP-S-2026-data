#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,Q;
int w[M],dis[505][505],minn[505][505];
vector<pair<int,int> > edge[505];
vector<pair<int,int> > poi[M];
struct Edge{
	int id,dis;
	bool operator <(const Edge &t)const{
		return dis>t.dis;
	}
};
priority_queue<Edge> q,q1;
int vis[505];
void dijkstra(int s){
	q=q1;
	memset(vis,0,sizeof(vis));
	q.push({s,0});
	dis[s][s]=0;
	while(!q.empty()){
		int u=q.top().id;
		q.pop();
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=0;i<edge[u].size();i++){
			int v=edge[u][i].first,w=edge[u][i].second;
			if(dis[s][v]>dis[s][u]+w){
				dis[s][v]=dis[s][u]+w;
				if(vis[v]==0){
					q.push({v,dis[u][v]});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			poi[x].push_back({i,y});
		}
	}
	memset(minn,0x3f,sizeof(minn));
	for(int i=1;i<=m;i++){
		for(int j=0;j<poi[i].size();j++){
			int l1=poi[i][j].first,l1t=poi[i][j].second;
			for(int k=0;k<poi[i].size();k++){
				int l2=poi[i][k].first,l2t=poi[i][k].second;
				minn[l1][l2]=min(minn[l1][l2],l1t+l2t);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(minn[i][j]!=0x3f3f3f3f){
				edge[i].push_back({j,minn[i][j]});
				edge[j].push_back({i,minn[i][j]});
			}
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++){
		dijkstra(i);
	}
	while(Q--){
		int u,v;
		cin>>u>>v;
		int ans=0x3f3f3f3f;
		for(int i=0;i<poi[u].size();i++){
			int from=poi[u][i].first,tfrom=poi[u][i].second;
			for(int j=0;j<poi[v].size();j++){
				int to=poi[v][j].first,tto=poi[v][j].second;
				ans=min(ans,dis[from][to]+tfrom+tto);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
	return 0;
}
