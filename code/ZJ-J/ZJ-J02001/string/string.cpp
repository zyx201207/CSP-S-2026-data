#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N];
char c[N], s[N], t[N];
int g, len = 0, iq;
long long ans = 0;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	g = a[1];
	for (int i = 2; i <= n; i++) {
		g = __gcd(g, a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int h = a[i] / g;
		while (h--) {
			s[len] += c[i];
			len++;
		}
	}
	for (int i = len - 1, j = 0; i >= 0, j < len; i--, j++) {
		t[j] += s[i];
	}
	if (len % 2 == 0) iq = len / 2;
	else iq = len / 2 + 1;
	for (int i = 0; i < iq; i++) {
		if (s[i] != t[i]) ans++;
	}
	ans *= g;
	cout << ans << '\n';
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
