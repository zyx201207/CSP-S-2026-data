#include <bits/stdc++.h>
#define INF 0x3f3f3f
#define ll long long
using namespace std;
const int N = 5010;
ll d, n, a[N], ans = 0, lg[N][N], plan[N][N];

void dfs(ll j, ll start, ll l) {
	lg[start][j] = min(lg[start][j], l);
	for (ll k = 1; k <= n - j; k++) {
		if (a[j + k] - a[j] <= d) {
			dfs(j + k, start, l + 1);
		} else {
			break;
		}
	}
}

void DFS(ll j, ll start, ll l) {
	if (l == lg[start][j]) {
		plan[start][j]++;
	}
	for (ll k = 1; k <= n - j; k++) {
		if (a[j + k] - a[j] <= d) {
			DFS(j + k, start, l + 1);
		} else {
			break;
		}
	}
}

int main() {
	freopen("migrate4.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	int c, t;
	cin >> c >> t;
	for (int i = 1; i <= t; i++) {
		ans = 0;
		memset(a, 0, sizeof a);
		memset(lg, INF, sizeof lg);
		memset(plan, 0, sizeof plan);
		cin >> n >> d;
		for (ll j = 1; j <= n; j++) {
			cin >> a[j];
		}
		for (ll j = 1; j <= n; j++) {
			dfs(j, j, 1);
		}
		for (ll j = 1; j <= n; j++) {
			DFS(j, j, 1);
		}
		for (ll j = 1; j <= n; j++) {
			for (ll k = j; k <= n; k++) {
				if (plan[j][k] == 2) {
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}