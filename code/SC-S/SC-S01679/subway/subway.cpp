#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void read(T& x) {
	x = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) ;
	for (;  isdigit(c); c = getchar()) x = x * 10 + (c ^ '0');
}

template <typename T, typename... other>
inline void read(T& x, other&... y) {
	read(x);
	read(y...);
}

int c, n, m, d, q;
int w[500005];
vector<pair<int, int>> v[500005];
long long dis[505][505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	read(c, n, m, d, q);
	for (int i = 1; i <= m; i++)
		read(w[i]);
	for (int i = 1, k, a, t; i <= n; i++)
		for (read(k); k--; )
			read(a, t), v[a].emplace_back(i, t);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			dis[i][j] = dis[j][i] = LLONG_MAX / 2;
	for (int i = 1; i <= m; i++)
		for (const auto& [lx, tx] : v[i])
			for (const auto& [ly, ty] : v[i])
				dis[lx][ly] = min<long long>(dis[lx][ly], tx + ty);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int x, y; q--; ) {
		read(x, y);
		long long res = LLONG_MAX;
		for (const auto& [lx, tx] : v[x])
			for (const auto& [ly, ty] : v[y])
				res = min(res, w[x] + tx + dis[lx][ly] + ty + w[y]);
		printf("%lld\n", res);
	}
	return 0;
}