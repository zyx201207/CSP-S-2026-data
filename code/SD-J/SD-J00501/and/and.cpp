#include <bits/stdc++.h>
typedef long long ll;
const int N = 2e5 + 5;
#define endl '\n'

using namespace std;

int n, m;

ll a[N], vis[N], maxx = -1, dp[N];

vector <int> yyy;

inline ll dfs (ll x, ll sum) {
	if (x == m) {
		maxx = max(maxx, sum);
		return sum;
	}
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		dfs(x + 1, x == 0 ? a[i] : sum & a[i]);
		vis[i] = 0;
	}
}

int main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(0, 0);
	cout << maxx << endl;
	return 0;
}
