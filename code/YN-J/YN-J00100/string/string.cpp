#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	long long n;
	cin >> n;
	string a;
	long long  count = 0;
	long long t = 0;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		char z;
		cin >> z;
		for (long long j = 0; j < x; j++) {
			a[count] = z;
			count++;
		}
	}
	long long m = 0;
	if (count % 2 == 0) {
		m = count / 2;
	} else {
		m = (count - 1) / 2;
	}
	for (long long i = 0; i < m; i++) {
		if (a[i] != a[count - 1 - i]) {
			t++;
		}
	}
	cout << t;

	fclose(stdin);
	fclose(stdout);
	return 0;
}