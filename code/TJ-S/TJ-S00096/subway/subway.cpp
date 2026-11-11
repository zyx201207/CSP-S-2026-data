#include <bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long LL;
typedef pair<long long,long long> pii;

const int N = 2e4+10;
LL n, m, a[N], head[N], cnt, dis[510][N];
struct Node {
	int to, nxt, val;
}g[40*N];

void add(int x, int y, int z) {
	g[++cnt].to = y;
	g[cnt].nxt = head[x];
	g[cnt].val = z;
	head[x] = cnt;
} 
void Dijkstra(int s) {
	dis[s][s+m] = 0;
	priority_queue<pii,vector<pii>,greater<pii> > q;
	q.push( {dis[s][s+m],s+m} );
	while (!q.empty()) {
		int d = q.top().first, u = q.top().second;
		q.pop();
		if (d != dis[s][u]) continue;
		for (int i = head[u]; i; i=g[i].nxt) {
			int v = g[i].to, w = g[i].val;
			if (dis[s][u]+w < dis[s][v]) {
				dis[s][v] = dis[s][u] + w;
				q.push({dis[s][v],v});
			}
		}
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	memset(dis,0x3f,sizeof dis);
	int c, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1, num; i <= n; i++) {
		cin >> num;
		for (int j = 1; j <= num; j++) {
			int x, y;
			cin >> x >> y;
			add(i+m,x,y);
			add(x,i+m,y);
		}
	}
	for (int i = 1; i <= n; i++) {
		Dijkstra(i);
	}
	while (q--) {
		int x, y;
		LL minn = INF;
		cin >> x >> y;
		for (int i = 1; i <= n; i++) {
			LL num = dis[i][x] + dis[i][y] + a[x] + a[y];
			minn = min(minn,num);
		}
		cout << minn << "\n";
	} 
	return 0;
} 
//Dijkstra(±©Á¦) 
// 6/7 TLE
