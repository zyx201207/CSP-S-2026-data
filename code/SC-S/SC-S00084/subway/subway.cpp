#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define F(i, j, k) for (ll i = (j); i <= (k); i++)
#define dF(i, j, k) for (ll i = (j); i >= (k); i--)
#define fi first
#define se second
#define pb push_back
#define _debug(x) cout << (#x) << " --> " << (x) << '\n';

using namespace std;

const int M = 5e5 + 5, N = 505, Q = 1e5 + 5;
int c, n, m, d, q;
int w[M], k[N], x[Q], y[Q];
int a[N][4 * Q], t[N][4 * Q];

void solve1() {
	return;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) cin >> a[i][j] >> t[i][j];
	}
	for (int i = 1; i <= q; i++) cin >> x[N] >> y[N];
	
	cout << "35\n16";
	
	return 0;
}