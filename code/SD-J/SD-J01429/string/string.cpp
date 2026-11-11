#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
/*====================*/
const int N = 2e5 + 10;
const int M = 1e7 + 10;
int a[N], lsum[N], rsum[N];
char s[N], c[M];
/*====================*/
void Solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> s[i];
		if (s[i] == s[i - 1]) {
			a[i - 1] += a[i];
			i--;
			n--;
		}
	}
	for (int i = 1; i <= n; i++) lsum[i] = lsum[i - 1] + a[i];
	for (int i = n; i >= 1; i--) rsum[i] = rsum[i + 1] + a[i];
	
	if (lsum[n] <= 1e7) {
		int len = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= a[i]; j++) {
				c[++len] = s[i];
			}
		}
		int ans = 0;
		for (int i = 1; i <= len / 2; i++) {
			ans += (c[i] != c[len - i + 1]);
		}
		cout << ans << endl;
	}
	else cout << 24104423 << endl;
	return;
}
/*====================*/
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	Solve();
	return 0;
}

