#include<bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
const int inf = 1e18;
const int N = 2e6 + 5;

int n, d, a[N], w[N], len[N];

void solve() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		w[i] = len[i] = 0;
	}
	a[n + 1] = a[n] + 1;
	a[n + 2] = inf;
	int pos = 1;
	bool b = 0;
	for(int i = 1; i <= n; i++) {
		int p = pos;
		while(pos <= n && a[pos + 1] - a[i] <= d) {
			pos++;
		}
		w[pos] += w[i] + 1;
		len[i] = p - i;
		if(pos == n + 1) {
			if(!b) {
				b = 1;
			}
			else {
				len[i] = 0;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += w[i] * len[i];
	}
	cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c, t;
	cin >> c >> t;
	while(t--) {
		solve();
	}
	
	return 0;
	
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/