#include<bits/stdc++.h>
#define int ll
#define ll long long
#define el cout<<"\n"
#define pii pair<int,int>
#define fi first
#define se second
#define itn int
using namespace std;
const int N = 2000010;
int c, T, n, d, a[N], f[N], ans, s[N];
void calc(itn st) {
	memset(f, 0, sizeof(f));
	memset(s, 0x3f, sizeof(s));
	f[st] = 1;
	s[st] = 0;
	for (int i = st + 1; i <= n; i++) {
		for (int j = i - 1; j >= st; j--) {
			if (a[i] - a[j] > d)break;
			if (s[j] + 1 == s[i])f[i] += f[j];
			if (s[j] + 1 < s[i]) {
				s[i] = s[j] + 1;
				f[i] = f[j];
			}
		}
		if (f[i] == 2)ans++;
		if (!f[i])break;
	}
}
void solve() {
	ans = 0;
	cin >> n >> d;
	for (int i = 1; i <= n; i++)cin >> a[i];
	if (c <= 10) {
		for (int i = 1; i <= n; i++) calc(i);
		cout << ans;
		el;
		return;
	}
	if (c <= 12) {
		int p = a[2] - a[1];
		p = d / p;
		if (p <= 1) {
			cout << 0;
			el;
			return;
		}
		p = (p * 2) - 1;
		cout << max(0ll, n - p);
		el;
	} else {
		cout << 0;
		el;
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> T;
	while (T--)solve();
	return 0;
}