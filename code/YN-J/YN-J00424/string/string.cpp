#include <bits/stdc++.h>
using namespace std;

long long a[210000];
char b[210000];


int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	long long n;
	cin >> n;
	long long m = 0;

	for (int i = 0; i < n; i ++) {

		cin >> a[i];
		cin >> b[i];
	}

	long long l = 0, r = n - 1;

	while (l < r) {
		if (b[l] != b[r])
			m += min(a[l], a[r]);

		int p = min(a[r], a[l]);
		a[l] -= p;
		a[r] -= p;

		if (a[l] == 0)
			l ++;

		if (a[r] == 0)
			r--;

	}

	cout << m;


	return 0;
}