#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int x, s, cnt;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> x;
	for (int i = 1; i <= x; i++) {
		cin >> s;
		cin >> a;
		for (int j = 1; j <= s; j++) {
			b += a;
		}
	}
	for (int i = b.size() - 1, j = 0; i >= b.size() / 2 ; i--, j++) {
		c += b[i];
		d += b[j];
	}
	for (int i = 0; i <= c.size(); i++) {
		if (d[i] != c[i])
			cnt++;
	}
	cout << cnt;
	return 0;
}