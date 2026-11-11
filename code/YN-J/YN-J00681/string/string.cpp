#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	string a = "";
	string a1 = "";
	string a2 = "";
	long long n = 0;
	long long p = 0;
	cin >> n;
	long long m = 0;//cishu
	long long g = 0;//fanxiang
	char b ;//str
	long long op = 0;
	long long need = 0;

	for (long long i = 0; i < n; i++) {

		cin >> m;
		cin >> b;

		for (long long j = 0; j < m; j++) {

			a += b;
			op++;
		}
	}



	if (op % 2 == 1) {
		p = (op - 1) / 2;

		for (long long o = 0; o < p; o++) {

			a1 += a[o];
		}

		while (g < p) {
			a2 += a[op - 1 - g];
			g++;
		}
	} else {
		p = op / 2;

		for (long long o = 0; o < p; o++) {

			a1 += a[o];
		}

		while (g < p) {
			a2 += a[op - 1 - g];
			g++;
		}
	}

	for (long long k = 0; k < p; k++) {

		if (a1[k] == a2[k]) {
			continue;
		} else {
			need++;
		}
	}


	cout << need;
	return 0;

}
