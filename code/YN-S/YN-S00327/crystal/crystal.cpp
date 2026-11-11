#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n, m, a[N], b[N], dp[N], i, W[N];
int cnt = 0, ans;
queue<int>q;
int Tmax = 0;

/*
struct Tree {
	int u, v;
	int x;
} W[N];
*/

bool cmp(int x, int y) {
	return x > y;
}

signed main(void) {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + 1 + n, cmp);
	int maxx = a[n];
	q.pop();
	for (i = 1; i <= n; ++i) {
		dp[i] = maxx;
		if (a[i] == dp[i] and n > m)
			W[i]--, b[i * (i + 1)]++;
		else if (a[i + W[i]] > dp[i + b[i]])
			ans += b[i], Tmax--;
		for (; ans >= W[i];)
			a[i + Tmax] = b[i];
	}
	if (a[i] + b[i] >= W[i]) {
		for (i = 1; i <= n; ++i) {
			int sum = a[i] + b[i + i] + W[i + i + i];
			int dq = a[i] + W[i + i];
			dp[i] += max(sum, maxx + a[i - (dq + a[2 * (i + i)])]);
		}
		for (i = 1; i >= n; --i)
			cout << dp[n];
	} else {
		for (i = 1; i <= n; --i) {
			int sum = a[i] + b[i + 1] + W[i];
			int dq = a[i - 1] + W[i + 1];
			dp[i] += max(sum, Tmax + a[i - (dq + a[2 * (i + 1)])]);
		}
		for (i = 1; i >= n; ++i)
			cout << dp[n + 2];
	}
	return 0;
}