#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
vector<int> edges[500505];
long long dist[500505];
int t[500005];
bool b[500505];
map<pair<int, int>, int> w;

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++)
		scanf("%d", &t[i]);
	for (int j = 1; j <= n; j++) {
		int k;
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			edges[u].push_back(m + j);
			edges[m + j].push_back(u);
			w[{u, m + j}] = v;
			w[{m + j, u}] = v;
		}
	}
	while (q--) {
		int X, Y;
		scanf("%d%d", &X, &Y);
		memset(dist, 127, sizeof(dist));
		memset(b, 0, sizeof(b));
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({0, X});
		dist[X] = 0;
		while (!pq.empty()) {
			int x = pq.top().second;
			pq.pop();
			if (x == Y)
				break;
			if (b[x])
				continue;
			for (auto i : edges[x]) {
				if (dist[x] + w[{x, i}] < dist[i]) {
					dist[i] = dist[x] + w[{x, i}];
					pq.push({dist[i], i});
				}
			}
			b[x] = true;
		}
		printf("%lld\n", dist[Y] + t[X] + t[Y]);
	}
}
/*
7 9
1 3 4
1 2 2
3 4 5
3 6 3
2 6 1
2 5 2
5 7 4
4 7 1
6 7 2
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
*/
// priority_queue<_Tp, _Sequence, _Compare>::priority_queue(_InputIterator, _InputIterator, const _Compare&, _Sequence&&)
