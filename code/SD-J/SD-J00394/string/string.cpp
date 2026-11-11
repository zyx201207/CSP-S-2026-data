# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

const int N = 1e6 + 5;
int n;
string s;
int ans;
bool f;

signed main () {
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	fst;
	cin >> n;
	for (int i = 1; i <= n; i ++ ) {
		int cnt;
		char c;
		cin >> cnt >> c;
		if (c != s[s.size () - 1]) {
			f = 1;
		}
		for (int i = 1; i <= cnt; i ++ ) {
			s += c;
		}
	}
	if (! f) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < s.size () / 2; i ++ ) {
		if (s[i] != s[s.size () - i - 1]) {
			ans ++;
		}
	}
	cout << ans << endl;
	return 0;
}
