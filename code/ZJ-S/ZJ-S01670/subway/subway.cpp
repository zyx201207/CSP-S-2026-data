#include <bits/stdc++.h>
#define syc nb666
#define endl '\n'
#define ll long long
using namespace std;
const int N=410,M=500;
int c,n,m,d,q;
int ar[2*N];
int cen[N];
int br[2*N],cr[2*N];
int dis[2*N][505];
int vis[2*N][505];
int diss[2*N][2*N];
struct Edge{
	int to,num,dist;
	Edge(int v,int idx,int w): to(v),num(idx),dist(w){}
	bool operator < (const Edge & x) const{
		return x.dist<dist;
	}
};
vector<Edge> g[2*N];
void dijkstra(int u){
	priority_queue<Edge> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[u][0]=0;
	q.push(Edge(u,0,dis[u][0]));
	while(!q.empty()){
		Edge s=q.top();
		q.pop();
		int u=s.to,num=s.num;
		if(vis[u][num]) continue;
		vis[u][num]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i].to,w=g[u][i].dist,numm=g[u][i].num;
			
			if(dis[v][numm]>dis[u][num]+w){
				dis[v][numm]=dis[u][num]+w;
				q.push(Edge(v,numm,dis[v][numm]));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(diss,0x3f,sizeof diss);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>ar[i];
	}
	for(int i=1;i<=n;i++){
		int len; cin>>len;
		for(int j=1;j<=len;j++){
			cin>>br[j]>>cr[j];
			g[br[j]+m].push_back(Edge(br[j],i,cr[j]));
			g[br[j]].push_back(Edge(br[j]+m,i,cr[j]));
		}
		for(int j=1;j<len;j++){
			g[br[j]].push_back(Edge(br[j+1],i,0));
		}
	}
	for(int i=m+1;i<=2*m;i++){
		dijkstra(i);
		for(int j=m+1;j<=2*m;j++){
			for(int k=1;k<=n;k++){
				diss[i][j]=min(diss[i][j],dis[j][k]);
			}
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		cout<<diss[u+m][v+m]+ar[u]+ar[v]<<endl;
	}
	return 0;
}