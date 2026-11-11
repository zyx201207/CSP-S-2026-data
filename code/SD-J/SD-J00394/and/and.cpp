# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int n, m;
const int N = 1e6 + 5;
int a[N];
int num[40];
string s[N];

int b[40];
int ans;
int x;
int er[40];
int cnt;
string str;

signed main () {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	fst;
	cin >> n;
	cin >> m;
	b[1] = 1;
	for (int i = 2; i < 31; i ++ ) {
		b[i] = 2 * b[i - 1];
	}
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		x = a[i];
		memset (er, 0, sizeof (er));
		cnt = 0;
		str = "";
		while (x > 0) {
			er[++ cnt] = x % 2;
			x /= 2;
		}
		for (int i = cnt; i >= 1; i -- ) {
			str += (er[i] + '0');
		}
		s[i] = str;
	}
	sort (s + 1, s + 1 + n);
	for (int i = n; i >= n - m + 1; i -- ) {
		int len = s[i].size ();
		for (int j = 0; j < len; j ++ ) {
			if (s[i][j] == '1') {
				num[len - j] ++; 
			}
		}
	}
	for (int i = 1; i < 31; i ++ ) {
		if (num[i] == m) {
			ans += b[i];
		}
	}
	cout << ans << endl;
	return 0;
}
// Trick||Treat!
