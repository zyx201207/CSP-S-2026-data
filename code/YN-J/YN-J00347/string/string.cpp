#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int a;
	cin >> a;

	int sum = 0;

	for (int i = 1; i <= a; i ++) {

		char l, r;
		cin  >> l >> r;
		sum += l;

		if (sum % 2 != 0) {
			cout << 0;
		}
	}

	return 0;
}