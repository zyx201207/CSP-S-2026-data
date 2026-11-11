#include<bits/stdc++.h>
using namespace std;
int n,m,q,d;
long long w[500005];
struct node{
	int subwayid;
	long long time;
};
bool operator < (node x,node y){
	return x.time > y.time;
}
vector<node> di[500005];
long long g[505][505];
long long dis[505][505];
bool vis[505];
void dijkstra(int st){
	memset(vis,0,sizeof vis);
	priority_queue<node> q;
	dis[st][st] = 0;
	q.push({st,0});
	while(!q.empty()){
		int now = q.top().subwayid;
		q.pop();
		vis[now] = 1;
		for(int to = 1;to <= n;to++){
			if(g[now][to] == 0x3f3f3f3f3f3f3f3f || vis[to]) continue;
			if(dis[st][to] > dis[st][now] + g[now][to]){
				dis[st][to] = dis[st][now] + g[now][to];
				q.push({to,dis[st][to]});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c;
	cin >> c;
	memset(g,0x3f3f3f3f,sizeof g);
	memset(dis,0x3f3f3f3f,sizeof dis);
	cin >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		g[i][i] = 0;
		int k;
		cin >> k;
		for(int j = 1;j <= k;j++){
			int a;
			long long t;
			cin >> a >> t;
			di[a].push_back({i,t});
		} 
	}
	for(int i = 1;i <= m;i++){
		int nn = di[i].size();
		for(int j = 0;j < nn;j++){
			for(int k = j + 1;k < nn;k++){
				int u = di[i][j].subwayid,v = di[i][k].subwayid;
				g[u][v] = min(g[u][v],di[i][j].time + di[i][k].time);
				g[v][u] = min(g[v][u],di[i][j].time + di[i][k].time);
			}
		}
	}
	for(int i = 1;i <= n;i++){
		dijkstra(i);
	}
	while(q--){
		int x,y;
		cin >> x >> y;
		long long ans = 0x3f3f3f3f3f3f3f3f;
		int nx = di[x].size(),ny = di[y].size();
		for(int i = 0;i < nx;i++){
			for(int j = 0;j < ny;j++){
				node xx = di[x][i],yy = di[y][j];
				ans = min(ans,xx.time + yy.time + dis[xx.subwayid][yy.subwayid]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
