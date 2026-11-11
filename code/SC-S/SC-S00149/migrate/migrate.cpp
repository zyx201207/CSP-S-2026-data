
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 10;
int c, T, n, d, a[N];

namespace task10 {
	const int M = 5010;
	vector<int> g[M];
	int dis[M], cnt[M];
	void init() {
		for (int i = 1; i <= n; ++i)	g[i].clear();
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if (abs(a[j] - a[i]) <= d) {
					g[i].push_back(j);
				} else {
					break;
				}
			}
		}
	}
	void calc() {
		init();
		int sum = 0;
		for (int x = 1; x <= n; ++x) {
			memset(dis, 0, sizeof dis);
			memset(cnt, 0, sizeof cnt);
			queue<int> q;
			dis[x] = 0, cnt[x] = 1, q.push(x);
			while (!q.empty()) {
				int u = q.front(); q.pop();
				for (int v : g[u]) {
					if (!dis[v]) {
						dis[v] = dis[u] + 1, cnt[v] = cnt[u];
						q.push(v);
					} else if (dis[v] == dis[u] + 1) {
						cnt[v] += cnt[u];
					}
				}
			}
			for (int i = 1; i <= n; ++i) {
				if (cnt[i] == 2)	sum++;
			}
		}
		printf("%lld\n", sum);
	}
}

namespace task12 {
	void calc() {
		int k = a[2] - a[1];
		if (d < 2 * k) {
			printf("0\n");
		} else {
			printf("%lld\n", max(0ll, n - (2ll * (int)(d / k) - 1)));
		}
	}
}

namespace task14 {
	void calc() {
		int cnt = 0, pre = 0, suf = 0;
		for (int i = 1; i <= n; ++i) {
			if (abs(a[i] - a[n]) > d)	pre++;
			if (abs(a[i] - a[1]) > d)	suf++;
			if (abs(a[i] - a[1]) <= d && abs(a[i] - a[n]) <= d)	cnt++;
		}
		if (cnt == 2) {
			printf("%lld\n", pre * suf);
		} else {
			printf("0\n");
		}
	}
}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%lld%lld", &c, &T);
	while (T--) {
		scanf("%lld%lld", &n, &d);
		for (int i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
		}
//		task10::calc();
//		task12::calc();
		if (c <= 10) {
			task10::calc();
		} else if (c <= 12) {
			task12::calc();
		} else if (c <= 14) {
			task14::calc();
		} else {
			task10::calc();
		}
	}
	return 0;
}
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

6
*/