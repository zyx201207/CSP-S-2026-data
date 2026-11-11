#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int W[20010];
int dis[20010];
bool vis[20010];
int k[510];
int a[510][20010];
int t[510][20010];
struct edge{
	int v,w;
};
bool operator< (edge x,edge y){
	return x.w>y.w;
}
vector<edge> G[20010];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>W[i];
	}
	for(int i=1;i<=n;i++){	
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		for(int x=1;x<k[i];x++){
			for(int y=x+1;y<=k[i];y++){
				G[a[i][x]].push_back({a[i][y],(t[i][x]+t[i][y])});
				G[a[i][y]].push_back({a[i][x],(t[i][x]+t[i][y])});
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(dis,0x3f,sizeof(dis));
		dis[x]=0;
		memset(vis,false,sizeof(vis));
		priority_queue<edge,vector<edge> > pq;
		for(edge i:G[x])pq.push(i);
		while(!pq.empty()){
			edge e=pq.top();
			pq.pop();
			int to=e.v;
			int cost=e.w;
			dis[to]=min(dis[to],cost);
			if(!vis[to])vis[to]=true;
			else continue;
			for(edge i:G[to]){
				int to1=i.v;
				int cost1=i.w;
				if(dis[to]+cost1<dis[to1]){
					dis[to1]=dis[to]+cost1;
					G[x].push_back({to1,dis[to1]});
					G[to1].push_back({x,dis[to1]});
				}
				pq.push({to1,dis[to1]});
			}
		}
		cout<<dis[y]+W[x]+W[y]<<"\n";
	}
	return 0;
}
