#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 505, M = 5e5 + 5;
int test, n, m, d, q, dis[N][N];
struct Station {
	int w;
	vector<pair<int, int>> step;
} s[M];

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> test >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> s[i].w;
	}
	for (int i = 1; i <= n; i++) {
		int tmpk, tmpa, tmpt;
		cin >> tmpk; 
		for (int j = 1; j <= tmpk; j++) {
			cin >> tmpa >> tmpt;
			s[tmpa].step.push_back({i, tmpt});
		}
	}
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < s[i].step.size(); j++) {
			for (int k = 0; k < s[i].step.size(); k++) {
				int u = s[i].step[j].first, v = s[i].step[k].first, w = s[i].step[j].second + s[i].step[k].second;
				dis[u][v] = min(dis[u][v], w);
				dis[v][u] = min(dis[v][u], w);
			}
		}
	}
//	cout << "debug\n";
//	for (int i = 1; i <= m; i++) {
//		for (int j = 0; j < s[i].step.size(); j++) {
//			cout << s[i].step[j].first << ' ' << s[i].step[j].second << ' ';
//		}
//		cout << endl;
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << ' ';
//		}
//		cout << endl;
//	} 
//	cout << "accept\n";
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
//	cout << "debug\n";
//	for (int i = 1; i <= n; i++) {
//		for (int j = 1; j <= n; j++) {
//			cout << dis[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << "accept\n";
	while (q--) {
		int st, fi, ans = 1e18;
		cin >> st >> fi;
		for (int i = 0; i < s[st].step.size(); i++) {
			for (int j = 0; j < s[fi].step.size(); j++) {
				int u = s[st].step[i].first, v = s[fi].step[j].first, w = s[st].step[i].second + s[fi].step[j].second;
				ans = min(ans, dis[u][v] + w);
			}
		}
		ans += s[st].w + s[fi].w;
		cout << ans << endl;
	}
	return 0;
}

