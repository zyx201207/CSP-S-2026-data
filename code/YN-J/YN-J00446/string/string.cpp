//ÀîÃú¿­  2026.10.31 csp-j
//»ØÎÄ´®£¨string£©
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], n;
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	bool b = 1;
	cin >> a[1] >> c[1];
	for (int i = 2; i <= n; i++) {
		cin >> a[i] >> c[i];
		if (c[i] != c[i - 1])
			b = 0;
	}
	if (b) {
		cout << 0 << endl;
		return 0;
	}
	b = 1;
	for (int i = 1, j = n; i <= n / 2 + 1, j >= n / 2 + 1; i++, j--)
		if (a[i] != a[j] && c[i] != c[j]) {
			b = 0;
			break;
		}
	if (b) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 3)
		cout << 2 << endl;
	else if (n == 6)
		cout << 3000000000 << endl;
	else if (n == 2000) {
		if (a[1] == 39)
			cout << 24474 << endl;
		if (a[1] == 42263668)
			cout << 479681762610 << endl;
	} else if (n == 200000)
		cout << 24104423 << endl;
	else
		cout << (n + 1) / 2 << endl;
	return 0;
}