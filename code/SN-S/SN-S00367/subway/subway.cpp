// SN-S00367 李天江 西安交通大学附属中学 
#include <bits/stdc++.h>

using namespace std;
constexpr int64_t inf = 1e18;
int test_c, n, m, d, q;
array<int, 500005> w;
array<array<int64_t, 505>, 505> dis_subways;
array<vector<pair<int, int>>, 500505> e;

int main() {
//	const auto start_t = chrono::steady_clock::now();
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> test_c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		int k;
		cin >> k;
		
		for (int j = 0; j < k; ++j) {
			int v, t;
			cin >> v >> t;
			
			e[i + m].emplace_back(v, t);
			e[v].emplace_back(i + m, t);
		}
	}
	
	/*for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < e[i].size(); ++j) {
			clog << e[i][j].first << ' ';
		}
		clog << '\n';
	}
	exit(0);*/
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis_subways[i][j] = inf;
		}
		dis_subways[i][i] = 0;
	}
	
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < e[i].size(); ++j) {
			for (int k = j + 1; k < e[i].size(); ++k) {
				const int v1 = e[i][j].first - m, t1 = e[i][j].second;
				const int v2 = e[i][k].first - m, t2 = e[i][k].second;
//				clog << i << ' ' << v1 << ' ' << v2 << ' ' << t1 + t2 << '\n';
				
				dis_subways[v1][v2] = min(dis_subways[v1][v2], (int64_t) t1 + t2);
				dis_subways[v2][v1] = dis_subways[v1][v2];
			}
		}
	}
	
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				dis_subways[j][i] = dis_subways[i][j] = min(dis_subways[i][j], dis_subways[i][k] + dis_subways[k][j]);
			}
		}
	}
	
	/*for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			clog << dis_subways[i][j] << ' ';
		}
		clog << '\n';
	}*/
	
	for (int _ = 0; _ < q; ++_) {
		int s, t;
		cin >> s >> t;
		
		int64_t ans = w[s] + w[t], tmp = inf;
		for (int i = 0; i < e[s].size(); ++i) {
			for (int j = 0; j < e[t].size(); ++j) {
				const int v1 = e[s][i].first - m, v2 = e[t][j].first - m;
				tmp = min(tmp, (int64_t) e[s][i].second + e[t][j].second + dis_subways[v1][v2]);
			}
		}
		ans += tmp;
		cout << ans << '\n';
	}
//	clog << (chrono::steady_clock::now() - start_t).count();
	return 0;
}
