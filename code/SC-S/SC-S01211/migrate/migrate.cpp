#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 2e6 + 5;
ll c, n, d, a[MAXN], dp[MAXN];
void solveA() {
	cout << n - d / (a[2] - a[1]) << '\n';
}
int bfs(int x, int y) {
	queue<pair<int, ll> > q;
	q.push({x, 0});
	for(int i = 1; i <= y - x + 1; i++) {
		dp[i] = 0;
	}
	int f = 2e6;
	while(q.size() > 0) {
		int pos = q.front().first;
		int t = q.front().second;
		q.pop();
		if(pos == y) {
			dp[t]++;
			f = min(f, t);
			continue;
		}
		int i = pos + 1;
		while(i <= y && a[i] - a[pos] <= d) {
			q.push({i, t + 1});
			i++;
		}
//			cout << t;
	}
//	for(int i = 1; i <= y - x + 1; i++) {
//		cout << dp[i];
//	}
//	cout << f << ' ';
	if(dp[f] == 2) return 1;
	return 0;
}
void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) cin >> a[i];
	if(c >= 11 && c <= 12) {solveA(); return;}
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 3; j <= n; j++) {
//			cout << i << ' ' << j << '\n';
			ans += bfs(i, j);
//			cout << ans;
		}
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int t; cin >> c >> t;
	while(t--) solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/