#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n, a;
	cin >> n;
	char b;
	string c;

	for (int i = 1; i <= n; i++) {

		cin >> a >> b;

		for (int j = 1; j <= a; j++) {

			c += b;
		}
	}

	string h;

	for (int i = c.size() - 1; i >= 0; i--) {

		h += c[i];
	}

	long long zh = 0, zh1 = c.size() - 1, sum = 0;
	bool p;

	if (h == c) {
		p = 0;
	} else {
		p = 1;
	}

	if ( p == 0) {
		cout << 0;
	} else {

		while (zh < zh1) {

			if (c[zh] != c[zh1]) {
				sum++;
			}

			zh++;
			zh1--;
		}

		cout << sum;
	}

	return 0;
}
