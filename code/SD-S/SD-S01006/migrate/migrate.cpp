#include<bits/stdc++.h>
#define int long long
using namespace std;

typedef pair<int,int> pii;
const int N = 5005;
const int INF = 1e18;
int c,t,n,d,x[N];
int dist[N][N],st[N][N],vis[N],sum,ts[N],tot;
vector<int> g[N];
//pii dian[N][N];
int ad(int x) {
	return max(x,-x);
}
void DFS(int u,int sf,int len){
	if(dist[u][sf] == len) st[u][sf] ++;
	else return;
	for(auto v : g[u]) {
		if(vis[v]) continue;
		vis[v] = 1;
		DFS(v,sf,len + 1);
		vis[v] = 0;
	}
}

set<pii> p;
void BFS(int u){
	for(int i = 1;i <= n;i ++) dist[u][i] = INF;
	p.insert({0,u});
	dist[u][u] = 0;
	while(!p.empty()){
		pii now = *p.begin();
		int x = now.second;
		p.erase(now);
		if(ts[x] == tot) continue;
		ts[x] = tot;
		for(auto v : g[x]) {
			if( dist[u][v] > dist[u][x] + 1) {
				dist[u][v] = dist[u][x] + 1;
				p.insert({dist[u][v],v});
			}
		}
	} 
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t --) {
		scanf("%lld%lld",&n,&d);
		for(int i = 1;i <= n;i ++) {
			g[i].clear();
			for(int j = 1;j <= n;j ++) dist[i][j] = INF,st[i][j] = 0;
		}
		for(int i = 1;i <= n;i ++) scanf("%lld",&x[i]);
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= n;j ++) {
				if(ad(x[i] - x[j]) <= d) g[i].push_back(j),dist[i][j] = 1;
			}
			dist[i][i] = 0;
			st[i][i] = 0;
		}
		for(int i = 1;i <= n;i ++) {
			++tot;
			BFS(i);
		}
		for(int i = 1;i <= n;i ++) {
			vis[i] = 1;
			DFS(i,i,0);
			vis[i] = 0; 
		}
		int cnt = 0;
		for(int i = 1;i <= n;i ++) {
			for(int j = i + 1;j <= n;j ++) {
				sum = 0;
			//	cout << i << " " << j << " " << st[i][j] << " " << dist[i][j] << "\n";
				if(st[i][j] == 2) cnt ++;
			}
		} 
		printf("%lld\n",cnt);
	}
	return 0;
}
