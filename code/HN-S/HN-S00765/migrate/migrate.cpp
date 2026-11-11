#include <iostream>
using namespace std;

int c, t, n;
long long d, a[5050];

inline long long read() {
	long long res = 0;
	int       sgn = 0, ch = getchar();
	while (ch < 48 || ch >= 58) sgn |= ch == '-',             ch = getchar();
	while (ch >= 48 && ch < 58) res = res * 10ll + (ch ^ 48), ch = getchar();
	return sgn ? -res : res;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--) {
		n = read(); d = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		if (d / (a[2] - a[1]) == 2) cout << n-2 << '\n';
		else                        cout << 0 << '\n';
	}
	return 0;
}

