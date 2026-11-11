#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ifstream fin("subway.in");
ofstream fout("subway.out");

const int kN = 5e5 + 1, kM = 501;

int c, n, m, d, q, w[kN];
vector<pll> vec[kN];
ll e[kM][kM];

int main() {
	fin.tie(0)->sync_with_stdio(0);
	fin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		fin >> w[i];
	for (int i = 1, k; i <= n; i++) {
		fin >> k;
		for (int j = 1, a, t; j <= k; j++)
			fin >> a >> t, vec[a].push_back({i, t});
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			e[i][j] = 1e18;
		e[i][i] = 0;
	}
	for (int i = 1; i <= m; i++)
		for (auto j : vec[i])
			for (auto k : vec[i])
				e[j.first][k.first] = e[k.first][j.first] = min(e[j.first][k.first], j.second + k.second);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
	for (int x, y; q--;) {
		fin >> x >> y;
		ll ans = 1e18;
		for (auto i : vec[x])
			for (auto j : vec[y])
				ans = min(ans, e[i.first][j.first] + i.second + j.second);
		fout << ans + w[x] + w[y] << '\n';
	}
	return 0;
}