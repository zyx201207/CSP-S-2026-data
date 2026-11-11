#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n;
ll m;
ll ans;
ll a[N], s[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		ll res = 1ll;
		for (int j = i + 1; j <= n; j++) {
			if ((a[j] * (ll)(j - i + 1) - (s[j] - s[i - 1])) > m) {
//				cout << "BREAK" << (a[j] * (ll)(j - i + 1) - (s[j] - s[i - 1])) << "J" << j << endl;
				break;
			}
			res++;
		}
//		cout << i << ' ' << res << endl;
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
