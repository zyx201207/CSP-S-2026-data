#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
char c[200005];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, cnt = 0;
	string s1, s2, ss;
	cin >> n;
	int l = 0, ll;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		l += a[i];
	}
	ll = l;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i]; j++) {
			ss += c[i];
		}
	}
	if (l % 2 == 0)
		l /= 2;
	else
		l = (l - 1) / 2;
	for (int i = 0; i <= l - 1; i++) {
		s1 += ss[i];
	}
	reverse(s1.begin(), s1.end());
	if (ll % 2 == 0) {
		for (int i = l; i <= ll - 1; i++) {
			s2 += ss[i];
		}
	} else {
		for (int i = l + 1; i <= ll - 1; i++) {
			s2 += ss[i];
		}
	}
	int m = s1.size();
	for (int i = 0; i <= m - 1; i++) {
		if (s1[i] != s2[i])
			cnt++;
	}
	cout << cnt ;
	return 0;
}