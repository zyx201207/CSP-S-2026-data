#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
typedef long long LL;
const int N = 500 + 5, M = 1e6 + 10;

namespace problem {

bool BEgin;
int n, m, C, d, q;
int k[N];
LL f[N][N];
int ct[M];
int g[M][22];
LL t[M][22];
LL w[M];
bool ENd;
void solve() {
	std::cerr << (&BEgin - &ENd) / 1024 / 1024 << "\n";
	memset(f, 0x3f, sizeof(f));
	std::cin >> C >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		std::cin >> w[i];
		ct[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			int a, tim;
			std::cin >> a >> tim;
			g[a][++ct[a]] = i;
			t[a][ct[a]] = tim;
//			std::cerr << a << " " << ct[a] << " " << g[a][1] << " " << "\n";
		}
	}
//	std::cerr << "okk";
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= ct[i]; j++) {
			for (int p = 1; p <= ct[i]; p++) {
				f[g[i][j]][g[i][p]] = std::min(f[g[i][j]][g[i][p]], t[i][j] + t[i][p]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			for (int z = 1; z <= n; z++) {
				f[x][y] = std::min(f[x][y], f[x][z] + f[z][y]);
			}
		}
	}
	while (q--) {
		int x, y;
		std::cin >> x >> y;
		LL ans = 1e18;
		for (int i = 1; i <= ct[x]; i++) {
			for (int j = 1; j <= ct[y]; j++) {
				ans = std::min(ans, w[x] + w[y] + t[x][i] + t[y][j] + f[g[x][i]][g[y][j]]);
			}
		}
		std::cout << ans << "\n";
	}
}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	problem::solve();
	return 0;
}