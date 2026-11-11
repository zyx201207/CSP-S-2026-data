#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using ll = long long;
constexpr int MAXN = 2e6 + 10;
constexpr int LOG = 21;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;

ll pos[MAXN];
int R[MAXN];
int find[MAXN][22];

inline void solve() {
	int n;
	ll d;
	std::cin >> n >> d;
	
	for (int i = 1; i <= n; i++) {
		std::cin >> pos[i];
	}
	
	std::vector<std::pair<int, int>> seq;
	for (int i = 1; i <= n; i++) {
		int nxt = std::upper_bound(pos + 1, pos + 1 + n, pos[i] + d) - pos - 1;
		R[i] = nxt;
	}
	
	for (int l = 1, r = 1; r <= n; r++) {
		if (R[r] == r) {
			for (int i = l; i <= r; i++) {
				if (R[i] == r) {
					if (pos[i] + d == pos[r]) continue;
					else R[i] = 0;
				}
			}
			seq.push_back({l, r});
			l = r + 1;
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		std::cout << R[i] << ' ';
//	}
//	std::cout << '\n';
	
	for (int j = 1; j <= n; j++) { find[j][0] = R[j]; }
	for (int i = 1; i <= 21; i++) {
		for (int j = 1; j <= n; j++) {
			find[j][i] = find[find[j][i - 1]][i - 1];
		}
	}
	
	ll res = 0;
	
	for (const auto& sol : seq) {
		int l = sol.first, r = sol.second;
//		std::cout << l << ' ' << r << '\n';
		
		for (int u = l; u <= r; u++) {
			if (R[u] == 0) continue;
			for (int v = R[u] + 1; v <= r; v++) {
				int lst = u;
				for (int i = 21; i >= 0; i--) {
					if (find[lst][i] <= v && find[lst][i]) lst = find[lst][i];
				}
				
				
				
				if (pos[v] - pos[lst - 1] <= d && pos[v] - pos[lst - 2] > d) {
					res++;
//					std::cout << u << ' ' << v << ' ' << lst << '\n';
				}
			}
		}
	}
	
	std::cout << res << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int TestCase, T;
	std::cin >> TestCase >> T;
	
	while (T--) {
		solve();
	}
	
	return 0;
}