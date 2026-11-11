#include <bits/stdc++.h>
using namespace std;
string a[1000000000], b;
char c;
long long n, m, p, mu, nn;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	if (n <= 1) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cin >> m;
		mu += m;
		cin >> a[i];
		for (int j = i; j < m + i; j++) {
			a[j] = a[i];
		}

	}

	for (int i = 0; i < mu / 2; i++) {
		if (a[i] != a[mu - i]) {
			p++;

		}

	}
	cout << p;









	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
