#include<bits/stdc++.h>
using namespace std;
#define int long long
//jiang xian lu zuo wei dian
//15 : 48 guo da yang li 
const int M=5e5+5;
const int N=505;
const int inf=1e15+5;
int w[M];
vector<pair<int,int>> stat[M];
int edge[N][N];
int dis[N][N];
void dijkstra(int st);
int c,n,m,d,Q;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			stat[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			edge[i][j]=inf;
		}
		edge[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto p1 : stat[i]){
			int u=p1.first,d1=p1.second;
			for(auto p2 : stat[i]){
				int v=p2.first,d2=p2.second;
				edge[u][v]=min(edge[u][v],d1+d2);
			}
		}
	}
	for(int i=1;i<=n;i++) dijkstra(i);
	while(Q--){
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(auto p1:stat[u]){
			for(auto p2:stat[v]){
				int cur=w[u]+w[v]+p1.second+p2.second;
				if(dis[p1.first][p2.first]==inf) continue;
				cur+=dis[p1.first][p2.first];
				ans=min(ans,cur);
			}
		}
		cout<<ans<<"\n";
	}
}
bool book[N];
struct Edge{
	int u,dist;
	bool operator < (const Edge e) const {
		return dist>e.dist;
	}
};
priority_queue<Edge> pq;
void dijkstra(int st){
	for(int i=1;i<=n;i++){
		book[i]=false;
		dis[st][i]=inf;
	}
	dis[st][st]=0;
	pq.push({st,0});
	while(!pq.empty()){
		int now=pq.top().u;
		pq.pop();
		if(book[now]) continue;
		book[now]=1;
		for(int nxt=1;nxt<=n;nxt++){
			if(edge[now][nxt]>=inf) continue;
			if(dis[st][nxt]>dis[st][now]+edge[now][nxt]){
				dis[st][nxt]=dis[st][now]+edge[now][nxt];
				pq.push({nxt,dis[st][nxt]});
			}
		}
	}
}
