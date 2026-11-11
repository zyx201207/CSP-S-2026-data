#include <bits/stdc++.h>
using namespace std;
string  b, c;
long long a, m = 0;

int main() {
	freopen("string1.in", "r", stdin);
	freopen("string1.out", "w", stdout);
	int n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> a >> b;
		for (long long j = 1; j <= a; j++) {
			c += b;
		}
	}
	int x = c.size() - 1;
	for (long long i = 0; i <= x / 2; i++) {
		if (c[i] != c[x - i]) {
			m++;
		}
	}
	cout << m;
	return 0;
}
