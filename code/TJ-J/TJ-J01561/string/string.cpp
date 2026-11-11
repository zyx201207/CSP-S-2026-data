#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a, b, c[200100] = {0}, d = 1, dd = 0;
	char aa;
	cin >> a;
	for (int i = 1; i <= a; i++) {
		cin >> b >> aa;
		for (int j = d; j <= d + b; j++) {
			c[j] = aa - 'a';
		}
		d += b;
	}
	for (int i = 1; i <= d / 2; i++) {
		if (c[i] != c[d - i]) {
			dd++;
		}
	}
	cout << dd;
	return 0;
}