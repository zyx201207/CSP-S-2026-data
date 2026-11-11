//SN-S00509 李泽琛 西安交通大学附属中学
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e4+510;
struct node{
	int v;
	int w;
};
vector<node> G[maxn];
int dis[maxn],vis[maxn];
int ans[maxn][maxn];
int W[maxn],l;
int c,n,m,d,q,k,a,t;
void Dijkstra(int s){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(0));
	queue<int> Q;
	dis[s] = 0;
	Q.push(s);
	vis[s] = 1;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		vis[u] = 0;
		for(int i=0;i<G[u].size();i++){
			int v = G[u][i].v,w = G[u][i].w;
			if(dis[u] + w <= dis[v]){
				dis[v] = dis[u] + w;
				if(vis[v]==0){
					Q.push(v);
					vis[v] = 1;
				}			
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >> W[i];
	}
	for(int i=1;i<=n;i++){
		cin >> k;
		l = 0;
		for(int j=1;j<=k;j++){
			cin >> a >> t;
			G[m+i].push_back(node{a,t});
			G[a].push_back(node{m+i,t});
		}
	}
	for(int i=1;i<=m;i++){
		Dijkstra(i);
		for(int j=1;j<=m;j++){
			ans[i][j] = dis[j];
		} 
	}
	for(int i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		cout << ans[x][y] + W[x] + W[y] << endl;
	}
} 
