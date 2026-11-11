#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	string l, w, k;
	long long m = 0, r;
	cin >> n;


	for (int i = 1; i <= n; i++) {

		cin >> r >> k;
		m += r;

		for (int i = 0; i < r; i++) {

			l += k ;
		}


	}

	int z = 0;

	for (int i = 0; i < m / 2; i++) {

		if (l[i] != l[m - i - 1]) {
			z++;
		}
	}

	cout << z;
	return 0;
}
