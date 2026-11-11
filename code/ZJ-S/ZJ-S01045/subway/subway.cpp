#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 505, M = 5e5 + 5, Q = 1e5 + 5;
ll c, n, m, d, q;
ll w[M], x[Q], y[Q], dis[N][N];
struct yrd {
	ll time, id;
};
vector<yrd> st[M];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		int k, a, t;
		cin >> k;
		for(int j = 1; j <= k; j++) {
			cin >> a >> t;
			st[a].push_back((yrd){t, i});
		}
	}
//	for(int i = 1; i <= m; i++) {
//		for(int j = 0; j < st[i].size(); j++) {
//			cout << st[i][j].id << " " << st[i][j].time << endl;
//		}
//		cout << endl;
//	}
	for(int i = 1; i <= q; i++) {
		cin >> x[i] >> y[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dis[i][j] = 2e18;
		}
	}
	for(int i = 1; i <= n; i++) {
		dis[i][i] = 0;
	}
	for(int i = 1; i <= m; i++) {
		int len = st[i].size();
		for(int j = 0; j < len; j++) {
			for(int k = 0; k < len; k++) {
				dis[st[i][j].id][st[i][k].id] = min(dis[st[i][j].id][st[i][k].id], st[i][j].time + st[i][k].time);
			}
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			cout << dis[i][j] << " ";
//		}
//		cout << endl;
//	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for(int i = 1; i <= q; i++) {
		ll ans = 2e18;
		int len1 = st[x[i]].size(), len2 = st[y[i]].size();
		for(int j = 0; j < len1; j++) {
			for(int k = 0; k < len2; k++) {
				ans = min(ans, st[x[i]][j].time + st[y[i]][k].time + dis[st[x[i]][j].id][st[y[i]][k].id]);
			}
		}
		ans += w[x[i]] + w[y[i]];
		cout << ans << endl;
	}
	return 0;
}
