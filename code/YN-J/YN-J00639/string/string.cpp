#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a;
	int d = 0;
	char b;
	cin >> n;
	string c = "";
	for (int i = 0; i < n; i++) {
		cin >> a;
		cin >> b;
		for (int j = 0; j < a; j++) {
			c += b;
		}

	}
	for (int g = 0; g < c.size(); g++) {
		if (int(c[g]) == int(c[c.size() - g])) {
			d += 0;
		}  else {
			d += 1;
		}
	}
	if (d == 0) {
		cout << 0;
	} else {
		cout << d - 1;
	}

	return 0;
}