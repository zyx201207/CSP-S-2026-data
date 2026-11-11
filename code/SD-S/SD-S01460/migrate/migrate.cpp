#include <bits/stdc++.h>
#define int long long
#define F first
#define S second

using namespace std;
typedef pair<int, int> pii;
typedef unsigned long long ull;

const int N = 2e6 + 5;
int C, T;
int n, d, x[N];

bool bfs(int st, int ed) {
	int ml = ed - st, cnt = 0;
	bool vis[N] = {0};
	queue<pii> q;
	q.push({st, 0});

	while (q.size()) {
		int len = q.front().S;
		int node = q.front().F;
		q.pop();

		if (len > ml) continue;

		if (node == ed) {
			if (ml < len) {
				cnt = 1;
				ml = len;
			} else ++cnt;
			continue;
		}

		if (vis[node]) continue;
		vis[node] = 1;

		for (int nt = st + 1; x[nt] - x[node] <= d; ++nt) {
			if (!vis[nt]) {
				q.push({nt, len + 1});
			}
		}
	}

	return (cnt > 1);
}

void solve_BF() {
	int ans = 0;

	for (int st = 1; st < n; ++st) {
		for (int ed = st + 1; ed <= n; ++ed) {
			ans += bfs(st, ed);
		}
	}

	cout << ans << '\n';
}

void solve_A() {

}

signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> C >> T;
	while (T--) {
		cin >> n >> d;
		for (int i = 1; i <= n; ++i) cin >> x[i];
		if (C <= 6) solve_BF();
	}

	return 0;
}
