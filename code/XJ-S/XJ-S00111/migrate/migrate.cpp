#include <bits/stdc++.h>
using namespace std;

const int N = 200011;
int c, n, f[N], dist[N];
long long d, x[N];

inline void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &x[i]), f[i] = i;
	for (int i = 1; i <= n; i++) {
		int L = i, R = n + 1;
		while (L + 1 < R) {
			int M = (L + R) / 2;
			if (abs(x[M] - x[i]) <= d)
				L = M;
			else
				R = M;
		}
		f[i] = L;
	}
	if (n <= 300) {
		auto bfs = [&] (int s, int e) -> int {
			int cnt = 0;
			for (int i = s; i <= e; i++) dist[i] = -1;
			dist[s] = 0;
			queue<int> q;
			q.push(s);
			while (!q.empty()) {
				int x = q.front(), y = min(f[x], e);
				q.pop();
				for (int i = x + 1; i <= y; i++) {
					if (dist[i] == -1) {
						dist[i] = dist[x] + 1;
						q.push(i);
						if (i == e) ++cnt;
					} else if (i == e && dist[i] != -1)
						cnt += (dist[x] + 1 == dist[i]);
				}
			}
			return (cnt == 2 ? 1 : 0);
		};
		
		int ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				ans += bfs(i, j);
		printf("%d\n", ans);
		return;
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int test;
	scanf("%d%d", &c, &test);
	while (test--) {
		solve();
	}
	return 0;	
}
