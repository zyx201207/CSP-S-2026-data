#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a, m = 0, sum = 0;
	char c, x;
	cin >> n;
	x = 'a';
	for (int i = 1; i <= n; i++) {
		cin >> a >> c;
		if (a != 1 && x != c) {
			sum = sum + a;
		}
	}
	cout << sum;
	return 0;
}