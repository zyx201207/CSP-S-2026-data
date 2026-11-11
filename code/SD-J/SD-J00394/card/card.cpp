# include <bits/stdc++.h>
# define endl '\n'
# define int long long
# define fst ios::sync_with_stdio (0); cin.tie (0); cout.tie (0);

using namespace std;

int n, m;
const int N = 1e6 + 5;
int a[N];
bool f[N];
int mcnt[N];

signed main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	fst;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++ ) {
		if (! f[a[i]]) {
			f[a[i]] = 1;
		}
		else {
			for (int j = 1; j < i; j ++ ) {
				f[a[j]] = 0;
			}
			f[a[i]] = 1;
		}
		int cnt = 0;
		for (int j = 1; j <= n; j ++ ) {
			cnt += f[a[j]];
		}
		mcnt[cnt] ++;
	}
	for (int i = 1; i <= m; i ++ ) {
		cout << mcnt[i] << ' ';
	}
	return 0;
}

