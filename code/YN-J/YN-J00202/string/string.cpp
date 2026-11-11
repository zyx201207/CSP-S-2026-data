#include <bits/stdc++.h>
using namespace std;
long long n, x[20005], num, num2;
char c[20005];
string s1;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	if (n == 1) {
		cout << 0;
	}

	for (int i = 0; i < n; i++) {

		cin >> x[i] >> c[i];

		for (int j = i; j < x[i]; j++) {

			s1[j] = c[i];
		}
	}

	int x2 = 0, x3;

	for (int i = 0; i <= n - 1; i++) {

		if (c[i] != c[i + 1]) {
			x2 = x[i];
			x3 = i;
			break;
		}
	}

	if (x2 == 0) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i <= x3 - 1; i++) {

		num += x[i];
	}

	for (int i = x3 + 1; i < n - 1; i++) {

		num2 += x[i];
	}

	if (num >= num2) {
		cout << num2;
	} else if (num < num2) {
		cout << num;
	} else
		cout << 0;
	return 0;
}
