#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define pii pair<int,int> 

const int maxm=5e5+8, maxn=5e2+8;
int c, n, m, d, q, bw[maxm];
int beg[maxm*2], nxt[maxm*5], wei[maxm*5], to[maxm*5], edgeCnt=0;
int idx;
long long dist[maxm*3];
map<int, int> las, cnt; 
vector<int> line[maxm];
long long floyDist[maxn][maxn];

void addEdgeSingle(int u, int v, int w) {
	nxt[++edgeCnt] = beg[u];
	beg[u] = edgeCnt;
	wei[edgeCnt] = w;
	to[edgeCnt] = v;
}

void addEdge(int u, int v, int w){
	addEdgeSingle(u, v, w);
	addEdgeSingle(v, u, w);
}

void djikstra(int rt) { 
	priority_queue<pii, vector<pii>, less<pii>> pq;
	for (int i=0; i<=idx; ++i) dist[i] = 1e18;
	dist[rt] = 0;
	pq.push({0, rt});
	while (!pq.empty()) {
		int u = pq.top().second;
		if (pq.top().first != dist[u]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (int e=beg[u]; e!=0; e = nxt[e]) {
			int v = to[e], cost = wei[e];
			if (dist[v] > dist[u] + cost) {
				dist[v] = dist[u] + cost;
				pq.push({dist[v], v});
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	
	cin >> c >> n >> m >> d >> q;
	for (int i=1; i <= m; ++i) {
		cin >> bw[i];
	}
	
	if (c >=12 && c <= 19) {
		for (int i=0; i<=n; ++i) {
			for (int j=0; j<=i; ++j) {
				floyDist[i][j] = floyDist[j][i] = 1e18;
			}
		}
		for (int i=1; i<=n; ++i) {
			int k; cin >> k;
			for (int j=1; j<=k; ++j) {
				int a, t; cin >> a >> t;
				line[a].push_back(i);
				cnt[a]++;
				if (cnt[a] == 1) las[a] = i;
				else floyDist[las[a]][i] = floyDist[i][las[a]] = 2*t; 
			}
		}
		
		for (int k=1; k<=n; ++k) {
			for (int i=0; i<=n; ++i) {
				for (int j=0; j<i; ++j) {
					floyDist[j][i] = floyDist[i][j] = min(floyDist[i][j], floyDist[i][k] + floyDist[k][j]);
				}
			}
		}
		
		while(q--) {
			int x, y;
			cin >>x >> y;
			long long ans = 1e18;
			for (auto i : line[x]) {
				for (auto j : line[y]) {
					if (floyDist[i][j] != 1e18) {
						ans = min(ans, floyDist[i][j]);
					}
				}
			}
			cout << ans << '\n';
		} 
	} else {
		idx = m;
		for (int i=1; i<=n; ++i) {
			int k; cin >> k;
			for (int j=1; j<=k; ++j) {
				int a, t; cin >> a >> t;
				addEdge(a, ++idx, t);
				if (j>1) addEdge(idx-1, idx, 0);
			}
		}
		while (q--) {
			int x, y; 
			cin >> x >> y;
			djikstra(x);
			cout << dist[y] + bw[x] + bw[y] <<'\n';
		}
	}
	return 0; 
}
