#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	int n, x = 0;
	cin >> n;
	string s, d;
	int a, sum = 0;
	char c;
	for (int i = 0; i < n; i++) {
		cin >> a >> c;
		sum += a;
		for (int j = sum - a; j < sum; j++) {
			s[j] = c;
		}
	}
	for (int i = sum - 1; i >= 0; i--) {
		d[i] = s[sum - i - 1];
	}
	for (int i = 0; i < d.size(); i++) {
		if (d[i] == s[i]) {
			x += 0;
		} else {
			x += 1;
		}
		cout << d[i];
	}
	cout << x;

	return 0;
}