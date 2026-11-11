#include <bits/stdc++.h>
using namespace std;

int n, st, re[10000005], ans = 1, sum;
char re1[2 * 10005];

int main() {

	freopen("string.in","r",stdout);
	freopen("string.out","w",stdout);

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> re[i] >> re1[i];
	}

	for (int i = 1; i <= n; i++) {

		if (re1[i] == re1[i - 1]) {
			ans++;
			st = 1;
		} else {
			st = 0;
			break;
		}
	}

	if (st == 1) {
		cout << "0";
	} else {
		for (int i = 1; i <= ans; i++) {

			sum += re[i];
		}

		cout << sum;
	}

	return 0;
}
