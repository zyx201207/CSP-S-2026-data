#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, z;
vector <pair<int, int>> e[10000005];
int a[500005];
int cnt[500005];//第i个站厅所连接的站台的数 
int vis[10000005], p[10000005];
struct node{
	int x, u;
	bool operator < (const node &k) const{
		return x > k.x;
	}
};
//priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
priority_queue <node> q;
void dijkstra(int s){
	memset(vis, 0, sizeof(vis));
	memset(p, 0x3f, sizeof(p));
	q.push({0, s});
	p[s] = 0;
	while(q.size()){
		int x = q.top().x;
		int u = q.top().u;
		q.pop();
		if(vis[u])
			continue;
		vis[u] = 1;
		for(int j = 0;j < e[u].size();j++){
			int v = e[u][j].first;
			int w = e[u][j].second;
			if(p[v] > p[u] + w){
				p[v] = p[u] + w;
				q.push({p[v], v});
			}
		}
	}
}
int check(int u, int fa){
	cout << u << " ";
	for(int j = 0;j < e[u].size();j++){
		if(e[u][j].first != fa){
			check(e[u][j].first, u);
		}
	}
}
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> c >> n >> m >> d >> z;
	for(int i = 1;i <= m;i++){
		int w;
		cin >> w;
		int u = i * (d + 2);//地铁口 
		int v = i * (d + 2) + 1;//站厅 
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	for(int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for(int j = 0;j <= k;j++)
			a[j] = 0;
		for(int j = 1;j <= k;j++){
			int t;
			cin >> a[j] >> t;
			++cnt[a[j]];
			if(j > 1){//连接地铁线 
				int u = a[j - 1] * (d + 2) + 1 + cnt[a[j - 1]];
				int v = a[j] * (d + 2) + 1 + cnt[a[j]];
				e[u].push_back({v, 0});
				e[v].push_back({u, 0});
			}
			int u = a[j] * (d + 2) + 1;//第a[j]个站厅 
			int v = a[j] * (d + 2) + 1 + cnt[a[j]];//第a[j]个地铁的第++cnt个站台 
			e[u].push_back({v, t});
			e[v].push_back({u, t});
		}
	}
	//check(22, 0);
	while(z--){
		int x, y;
		cin >> x >> y;
		dijkstra(x * (d + 2));//从地铁口跑一遍最短路
		cout << p[y * (d + 2)] << '\n';
	}
	return 0;
}
