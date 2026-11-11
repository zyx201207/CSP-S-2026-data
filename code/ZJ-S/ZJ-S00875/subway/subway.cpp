#include<bits/stdc++.h>
using namespace std;
const int N = 500010;
int c, m, n, d, q, t[N];
long long dis1[510][510];
int dis2[N][510];
vector<int> hd[N];
void floyd() {
	for(int k = 1; k <= n; k++) {
		for(int x : hd[k]) {
			for(int y : hd[k]) {
				dis1[x][y] = min(dis1[x][y], (long long)dis2[k][x] + dis2[k][y]);
			}
		}
	}
//	for(int i = 1; i <= m; i++) {
//		for(int j = 1; j <= m; j++) {
//			if(dis1[i][j] == 0x3f3f3f3f) cout << "inf ";
//			else cout << dis1[i][j] << " ";
//		}
//		cout << endl;
//	}cout << endl;
	for(int k = 1; k <= m; k++) {
		for(int i = 1; i <= m; i++) {
			for(int j = 1; j <= m; j++) {
				if(dis1[i][j] > dis1[i][k] + dis1[k][j]) {
					dis1[i][j] = dis1[i][k] + dis1[k][j];
				}
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cin >> c >> m >> n >> d >> q;
//	cout << m << endl;
	for(int i = 1; i <= n; i++) {
		cin >> t[i];
	}
	memset(dis1, 0x3f, sizeof dis1);
	memset(dis2, 0x3f, sizeof dis2);
	for(int i = 1, k; i <= m; i++) {
		cin >> k;
		dis1[i][i] = 0;
		for(int j = 1, v, w; j <= k; j++) {
			cin >> v >> w;
			hd[v].push_back(i);
			dis2[v][i] = min(dis2[v][i], w);
//			cout << i << " " << v << " " << dis2[v][i] << endl;
		}
//		for(int j = 1; j <= n; j++) {
//			cout << dis2[j][i] << " ";
//		}cout << endl;
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) {
//			if(dis2[i][j] == 0x3f3f3f3f) cout << "inf ";
//			cout << dis2[i][j] << " ";
//		}
//		cout << endl;
//	}
	floyd();
//	for(int i = 1; i <= m; i++) {
//		for(int j = 1; j <= m; j++) {
//			if(dis1[i][j] == 0x3f3f3f3f) cout << "inf ";
//			else cout << dis1[i][j] << " ";
//		}
//		cout << endl;
//	}cout << endl;
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			if(dis2[i][j] == 0x3f3f3f3f) cout << "inf ";
//			else cout << dis2[i][j] << " ";
//		}
//		cout << endl;
//	}cout << endl;
//	for(int i = 1; i <= n; i++) {
//		for(int x : hd[i]) {
//			cout << x << " ";
//		}cout << endl;
//	}
	while(q--) {
		int u, v;
		cin >> u >> v;
		long long ans = 1e9;
		for(int x : hd[u]) {
			for(int y : hd[v]) {
				ans = min(ans, (long long)dis1[x][y] + dis2[u][x] + dis2[v][y]);
			}
		}
		ans += t[u] + t[v];
		cout << ans << endl;
	}
	return 0;
}//qwq怎么一直错啊!!!
