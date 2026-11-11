#define USE_FREOPEN
//#define IN_TEST

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
constexpr int MAXN = 505, MAXM = 5e5 + 5, MAXQ = 1e5 + 5;
int c, n, m, d, q, w[MAXM], k[MAXN], ql[MAXQ], qr[MAXQ], visit[MAXM * 2];
std::vector<std::pair<int, int>> kl[MAXN];
std::vector<int> a[MAXN], t[MAXN];
std::vector<std::pair<int, int>> edge[MAXN];

long long dfs(int x, int y, long long dis = 0) {
	if (x == y)
		return dis;
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (const auto& v : edge[x]) {
		int p = v.first;
		int tm = v.second;
		if (visit[p])
			continue;
		visit[p] = true;
		ans = std::min(ans, dfs(p, y, dis + tm));
		visit[p] = false;
	}
	return ans;
}

int main() {
#ifdef USE_FREOPEN
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
		kl[i].resize(d + 1);
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> k[i];
		a[i].resize(k[i] + 1);
		t[i].resize(k[i] + 1);
		for (int j = 1; j <= k[i]; j++) {
			std::cin >> a[i][j] >> t[i][j];
			kl[a[i][j]].emplace_back(i, t[i][j]);
		}
	}
	for (int i = 1; i <= q; i++)
		std::cin >> ql[i] >> qr[i];
	
	for (int i = 1; i <= m; i++)
		for (const auto& v : kl[i]) {
			int p = v.first;
			long long tm = v.second;
			for (int j = 1; j <= k[p]; j++) {
				long long sm = 0;
				bool flag = false;
				for (auto& tmp : edge[i])
					if (tmp.first == a[p][j] + m) {
						tmp.second += tm;
						flag = true;
					}
				if (flag)
					for (auto& tmp : edge[a[p][j]])
						if (tmp.first == i)
							tmp.second += tm;
				if (!flag) {
					edge[i].emplace_back(a[p][j] + m, tm);
					edge[a[p][j] + m].emplace_back(i, tm);
				}
			}
		}

#ifdef IN_TEST
	std::cout << "edge:" << std::endl;
	for (int i = 1; i <= m; i++)
		for (const auto& v : edge[i])
			std::cout << "X" << i << "->" << v.first - m << "=" << v.second << std::endl;
	for (int i = m + 1; i <= 2 * m; i++)
		for (const auto& v : edge[i])
			std::cout << i - m << "->X" << v.first << "=" << v.second << std::endl;
#endif

	for (int i = 1; i <= q; i++)
		std::cout << dfs(ql[i], qr[i]) + w[ql[i]] + w[qr[i]] << std::endl;
}