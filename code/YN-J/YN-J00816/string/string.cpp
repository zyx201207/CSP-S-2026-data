#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a;
	string b, c;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		for (int i = 1; i <= a; i++) {
			c += b;
		}
	}
	long long d, e = 0;
	d = n;
	for (int i = 0; i <= d; i++) {
		if (c[i] != c[abs(n - i)]) {
			e++;
		}
	}
	int f = 0;
	f += e / 2;
	cout << f;
	return 0;
}