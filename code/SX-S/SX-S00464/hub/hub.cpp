#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k, d[1000005], s[1000005], mx[1000005];
vector<long long>l[1000005];
bool y[1000005];

void dfs(long long u, long long fa, long long x) {
	s[u] = s[fa] + 1;
	d[u] = mx[u] = 1;
	if (u == x)
		y[u] = true;
	else
		y[u] = false;
	for (auto v : l[u]) {
		if (v == fa)
			continue;
		dfs(v, u, x);
		d[u] += d[v];
		y[u] |= y[v];
		mx[u] = max(mx[u], mx[v] + 1);
	}
}

long long dfss(long long u, long long fa, long long mid) {
	if (mx[u] <= mid)
		return 0;
	long long sum = 1;
	for (auto v : l[u]) {
		if (v == fa || y[v])
			continue;
		sum += dfss(v, u, mid);
	}
	return sum;
}

bool ck(long long mid) {
	for (long long i = 1; i < n; i++) {
		long long ans = 0;
		dfs(i, 0, 0);
		ans += max(1ll, dfss(i, 0, 0));
		if (ans <= k)
			return true;
		for (long long j = i + 1; j <= n; j++) {
			ans = 0;
			dfs(i, 0, j);
			ans += max(1ll, dfss(i, 0, mid));
			ans += max(1ll, dfss(j, 0, mid));
			ans += max(s[j] - 2 - 2 * mid, 0ll);
			if (ans <= k)
				return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		cin >> n >> k;
		for (long long i = 1; i < n; i++) {
			long long u, v;
			cin >> u >> v;
			l[u].push_back(v);
			l[v].push_back(u);
		}
		long long ll = 0, r = n;
		while (ll < r) {
			long long mid = (ll + r) / 2;
			if (ck(mid))
				r = mid;
			else
				ll = mid + 1;
		}
		cout << ll << '\n';
		for (long long i = 1; i <= n; i++)
			while (l[i].size() > 0)
				l[i].pop_back();
	}
	return 0;
}