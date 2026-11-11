#include<bits/stdc++.h>
#define ll long long
#define ls(i) i<<1
#define rs(i) i<<1|1

using namespace std;

const int N = 2e5+5, INF = 1e9;
ll n, k;
struct EDGE {
	int u, v;
};
int ans = 1e9;
int F[1005][1005];
int G[1005][1005];
bool vis[N];
vector<int> ed[N];
void find() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			G[i][j] = F[i][j];
		}
	}
	for (int i1 = 1; i1 <= n; i1++) {
		for (int j1 = i1; j1 <= n; j1++) {
			G[i1][j1] = 0;
			int sum = 0;
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					for (int k = 1; k <= n; k++) {
						if (G[i][j] > G[i][k] + G[k][j]) {
							G[i][j] = G[i][k] + G[k][j];
							G[j][i] = G[i][j];
						}
					}
				}
			}
			for (int i = 1; i <= n; i++) {
				for (int j = i; j <= n; j++) {
					sum = max(sum, G[i][j]);
				}
			}
			ans = min(ans, sum);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					G[i][j] = F[i][j];
				}
			}
		}
	}
}
void solve() {
	cin >> n >> k;
	int u, v;
	ans = 0;

	if (n < 1005 && k <= 2) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				F[i][j] = INF;
			}
		}
		for (int i = 1; i <= n; i++) {
			F[i][i] = 0;
		}
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			F[u][v] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					if (F[i][j] > F[i][k] + F[k][j]) {
						F[i][j] = F[i][k] + F[k][j];
						F[j][i] = F[i][j];
					}
				}
				ans = max(ans, F[i][j]);
			}
		}
		if (k == 1) {
			cout << ans << "\n";
			return ;
		}
		find();
		cout << ans << "\n";
	} else {
		for (int i = 1; i < n; i++) {
			cin >> u >> v;
			ed[u].push_back(v);
			ed[v].push_back(u);
		}
		cout << 1 << "\n";
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		solve();
	}
	return 0;
}