#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
inline int read() {
	char c = getchar();
	int x = 0, f = 1;
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c - 48); 
		c = getchar(); 
	}
	return x * f;
}
const int N = 5e5 + 5;
const int NN = 2005;
const ll inf = 1e16;
int c, n, m, d, q, p[N];
ll dis[NN][NN];
vector<pair<int, int>> e[N];
priority_queue<pli, vector<pli>, greater<pli> > dq;
void dijkstra(int s) {
	for(int i = 1; i <= n + m; ++i)
		dis[s][i] = inf;
	dis[s][s] = 0;
	dq.push(make_pair(dis[s][s], s));
	while(!dq.empty()) {
		int u = dq.top().second;
		ll d = dq.top().first;
		dq.pop();
		if(dis[s][u] != d) continue;
		for(pair<int, int> it : e[u]) {
			int v = it.first, w = it.second;
			if(dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				dq.push(make_pair(dis[s][v], v));
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; ++i)
		p[i] = read();
	for(int i = 1; i <= n; ++i) {
		int k = read();
		for(int j = 1; j <= k; ++j) {
			int v = read(), w = read();
			e[m + i].push_back(make_pair(v, w));
			e[v].push_back(make_pair(m + i, w));
		}
	}
	if(c <= 11) {
		for(int i = 1; i <= m; ++i)
			dijkstra(i);
		for(int i = 1; i <= q; ++i) {
			int x = read(), y = read();
			cout << p[x] + p[y] + dis[x][y] << '\n';
		} 
	}
	return 0;
}
