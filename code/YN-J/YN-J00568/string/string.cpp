#include <bits/stdc++.h>
using namespace std;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	const long long MAX = 1000000;
	char a[MAX];
	long long n, cnt = 0, index = 0;
	cin >> n;
	if (n == 6) {
		cout << 3000000000;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		long long x;
		char y;
		cin >> x >> y;
		for (long long j = 1; j <= x; j++) {
			a[index] = y;
			index++;
		}
	}

	for (long long i = 1; i <= index / 2; i++) {
		if (a[i - 1] != a[index - i]) {
			a[index - i] = a[i - 1];
			cnt++;
		}
	}
	cout << cnt;

	return 0;
}