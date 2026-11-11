#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n, m = 1, x = 1, p = 1, q = 1;
	long long a[200005] = {0};
	char s[200005] = {0};
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i];
		cin >> s[i];

		if (s[i] == s[i - 1]) {
			m++;
		}

		if (a[i] == a[i - 1]) {
			x++;
		} else {
			p = x;
		}
	}

	if (m == n) {
		cout << 0;
	} else {
		if (x != 1 and a[n] == 1) {
			cout << x;
		} else {
			if (m <= x) {
				cout << (m - p - 1)*a[n];
			}
		}


	}

	fclose(stdin);
	fclose(stdout);


	return 0;
}