#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define pli pair<long long, int>

const int maxn=2e6+8;
int c, t;
int n;
long long d;
long long x[maxn];
vector<pli> to[maxn];
long long dist[maxn];
int cnt[maxn];

void djikstra(int rt) { 
	priority_queue<pli, vector<pli>, less<pli>> pq;
	for (int i=0; i<=n; ++i) dist[i] = 1e18;
	dist[rt] = 0;
	pq.push({0, rt});
	while (!pq.empty()) {
		int u = pq.top().second;
		if (pq.top().first != dist[u]) {
			pq.pop();
			continue;
		}
		pq.pop();
		for (auto e :to[u]) {
			int v = e.second;
			long long cost = e.first;
			if (dist[v] > dist[u] + cost) {
				dist[v] = dist[u] + cost;
				pq.push({dist[v], v});
				cnt[v] = 1;
			} else if (dist[v] == dist[u] + cost) {
				++cnt[v];
			}
		}
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		cout << n <<"<-n\n";
		for (int i=1; i<=n; ++i) cin >> x[i];
		
//		for (int i=1; i<=n; ++i) cout << x[i] << ' '; cout <<'\n'; 
		
		for (int i=1; i<=n; ++i) {
			int pos = lower_bound(x+1, x+n+1, x[i] + d) - x - 1;
//			cout << x[i] << ' ' << x[pos] <<'\n';
			for (int j=i+1; j<=pos; ++j) {
				to[i].push_back({x[j]-x[i], j});
				to[j].push_back({x[j]-x[i], i});
			}
		}
		int ans=0;
		for (int i=1; i<=n; ++i) {
			djikstra(i);
			for (int j=1; j<=n; ++j) {
				ans += (cnt[j] == 2);
			}
		} 
		cout <<ans<<'\n';
//	cout <<"test\n";
	}
	return 0;
}
