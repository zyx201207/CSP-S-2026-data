#include <bits/stdc++.h>
using namespace std;

long long eage[20100];
int ver[20100];
int nt[20100], head[20100];
long long dist[5100];
bool vis[20100];
long long su[600];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	int tot = 2;

	int c, n, m, d, q, k;
	int a, t;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> su[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> k;
		for (int j = 1; j <= k; j++) {
			cin >> a >> t;
			nt[tot] = head[i];
			head[i] = tot;
			ver[tot] = a + 500;
			eage[tot] = t;
			tot++;
			nt[tot] = head[a + 500];
			head[a + 500] = tot;
			ver[tot] = i;
			eage[tot] = t;
			tot++;
		}
	}
	priority_queue<long long> qu;
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		memset(dist, 0x3f, sizeof(long long) * 5100);
		dist[500 + x] = 0;
		vis[x + 500] = 1;
		for (int j = head[x + 500]; j == 0; j = next[j]) {
			dist[j] = eage[j];
		}
		for (int j = 1; j <= n; j++) {
			qu.push(make_pair (-1 * dist[j], j)   );
		}
		for (int j = 501; j <= m; j++) {
			qu.push(make_pair (-1 * dist[j], j)   );
		}
		while (qu.size() == 0) {
			while ()
			}
	}
	return 0;
}
