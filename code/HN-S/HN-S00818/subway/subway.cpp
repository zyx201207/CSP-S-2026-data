#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5,M=505;
int c,n,m,d,q;
int tot;
bool vis[N],ok[N];
int dis[M][M],w[M],dis2[N];
struct NODE{
	int v,val;
	bool operator < (const NODE &b) const{
		return val>b.val;
	}
};
struct EDGE{
	int v,w;
};
vector<EDGE> G[N];

void dijkstra(int s){
	for(int i=1;i<=tot;i++)
		vis[i]=0,dis2[i]=1e18;
	priority_queue<NODE> pq;
	pq.push({s,0});
	dis2[s]=0;
	while(!pq.empty()){
		auto cur=pq.top();
		pq.pop();
		if(vis[cur.v])
			continue;
		vis[cur.v]=1;
		for(auto i:G[cur.v]){
			if(dis2[cur.v]+i.w<dis2[i.v]){
				dis2[i.v]=dis2[cur.v]+i.w;
				pq.push({i.v,dis2[i.v]});
			}
		}
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>m>>n>>d>>q; 
	for(int i=1;i<=n;i++)
		cin>>w[i];
	tot=n;
	for(int i=1,k;i<=m;i++){
		cin>>k;
		int st=tot+1;
		for(int j=1,u,w;j<=k;j++){
			cin>>u>>w;
			tot++;
			G[u].push_back({tot,w});
			G[tot].push_back({u,w});
		}
		for(int j=st;j<tot;j++)
			G[j].push_back({j+1,0}),G[j+1].push_back({j,0});
	}
	for(int i=1;i<=n;i++){
		dijkstra(i);
		for(int j=1;j<=n;j++)
			dis[i][j]=dis2[j];
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+dis[x][y]+w[y]<<'\n';
	}
	return 0;
}
