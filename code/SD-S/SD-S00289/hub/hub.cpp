# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int c, t;
int n, k;
const int N = 1e6 + 5;
vector < int > mp[N];
int in[N];

inline void solve () {
	memset (in, 0, sizeof (in));
	cin >> n >> k;
	for (int i = 1, u, v; i < n; i ++ )  {
		cin >> u >> v;
		mp[u].push_back (v);
		mp[v].push_back (u);
		in[u] ++;
		in[v] ++;
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++ ) {
		ans = max (ans, in[i]);
	}
	cout << ans / 2 << endl;
}

signed main () {
	freopen ("hub.in", "r", stdin);
	freopen ("hub.out", "w", stdout);
	fst;
	cin >> c;
	for (cin >> t; t; t -- ) {
		solve ();
	}
	return 0;
}

