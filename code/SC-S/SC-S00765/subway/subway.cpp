#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,M=1005;
int c,n,m,d,Q;
int w[M],k[N],dis[N+M][N+M],vis[N+M];
vector<pair<int,int> >g[M+N];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void dijkstra(int s){
	memset(dis[s],0x3f,sizeof(dis[s]));dis[s][s]=0;
	memset(vis,0,sizeof(vis));
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(pair<int,int> i:g[u]){
			int v=i.first,w=i.second;
			if(dis[s][u]+w<dis[s][v]){
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v}); 
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x,y;
			cin>>x>>y;
			g[x].push_back({m+i,y});
			g[m+i].push_back({x,y});
		}
	}
	for(int i=1;i<=m;i++)dijkstra(i);
	
	while(Q--){
		int x,y;cin>>x>>y;
		cout<<dis[x][y]+w[x]+w[y]<<"\n";
	}
	return 0;
}