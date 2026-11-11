#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2e6 + 5;

int c, test_case;
i64 n, d, x[N], dist[N], cnt[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

  std::freopen("migrate.in", "r", stdin);
  std::freopen("migrate.out", "w", stdout);

	std::cin >> c >> test_case;

	while (test_case--) {
		std::cin >> n >> d;

		for (int i = 1; i <= n; i++) std::cin >> x[i];

		bool subA = true, subB = false;
		for (i64 i = 3; i <= n; i++)
			subA &= x[i] - x[i - 1] == x[2] - x[1];
		i64 B_mx = x[n], B_mn = x[1];
		int global = -1;
		for (int i = 1; i <= n; i++)
			if (B_mx - x[i] <= d && x[i] - B_mn <= d)
	  		{ subB = true, global = i; break; }

		if (subA) {
			i64 t2 = x[2] - x[1];
			if (t2 >= d) { std::cout << "0\n"; continue; }
			i64 del = d / t2 + 1;
			std::cout << std::max(0ll, n - (d / t2 + 2)) << "\n";
			continue;
		}
		if (subB) {
			int l = global - 1, r = n;
			i64 ans = 0;
			while (l >= 1) {
				while (r > global && x[r] - x[l] > d) r--;
				int pos = std::upper_bound(x + 1, x + n + 1, x[r] + d) - x;
				ans += pos - r;
			}

			std::cout << ans << "\n";
			continue;
		}

		int ans = 0;
  	for (int i = 1; i <= n; i++) {
  		for (int j = 1; j <= n; j++) dist[j] = -1, cnt[j] = 0;
  		dist[i] = 0, cnt[i] = 1;
  		std::queue<int> q; q.push(i);
  		while (!q.empty()) {
  			int u = q.front(); q.pop();
  			for (int j = u + 1; j <= n; j++) {
  				if (x[j] - x[u] > d) continue;
  				if (dist[j] != -1 && dist[j] > dist[u] + 1) continue;
  				else if (dist[j] != -1 && dist[j] == dist[u] + 1) cnt[j] += cnt[u];
  				else if (dist[j] == -1) dist[j] = dist[u] + 1, cnt[j] = cnt[u], q.push(j);
  			}
  		}
  		for (int j = 1; j <= n; j++)
  			ans += cnt[j] == 2;
  	}

//	std::memset(dist, -1, sizeof(dist));
//	std::memset(cnt, 0, sizeof(cnt));

//	for (int i = 2, l = 1; i <= n; i++) {
//		
//	}

		std::cout << ans << "\n";
	}

	return 0;
}
