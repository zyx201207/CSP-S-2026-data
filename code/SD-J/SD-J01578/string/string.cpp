#include <bits/stdc++.h>
using namespace std;
unsigned long long n, a[200005], l = 0, s[200005], cnt = 0, g = 1;
char c[200005];
int gcd(int a, int b) {
	while (b != 0) {
		swap(a, b);
		b %= a;
	}
	return a;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> a[i] >> c[i];
	}
	g = a[0];
	for (int i = 1; i < n; i ++) {
		g = gcd(g, a[i]);
	}
	for (int i = 0; i < n; i ++) {
		a[i] /= g;
		l += a[i];
	}
	s[0] = a[0] - 1;
	for (int i = 1; i < n; i ++) {
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 0; i < l / 2; i ++) {
		int p = lower_bound(s, s + n, i) - s;
		int q = lower_bound(s, s + n, l - i - 1) - s;
		if (c[p] != c[q]) {
			cnt ++;
		}
	}
	cout << cnt * g << '\n';
	return 0;
}
