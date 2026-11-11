# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int t;
int n, d;
const int N = 1e6 + 5;
int x[N];
int dif[N], sum[N];
int f[1000][1000];

inline void solve () {
	memset (f, 0, sizeof (f));
	int maxn = LLONG_MIN; 
	int ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i ++ ) {
		cin >> x[i];
	}
	for (int i = 2; i <= n; i ++ ) {
		dif[i - 1] = x[i] - x[i - 1];
	}
	for (int i = 1; i < n; i ++ ) {
		sum[i] = sum[i - 1] + dif[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		if (sum[i] == dif[i]) {
			ans ++;
		}
	}
	cout << ans << endl;
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	fst;
	for (cin >> t; t; t -- ) {
		solve ();
	}
	return 0;
}

