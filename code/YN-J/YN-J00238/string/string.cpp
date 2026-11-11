#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	string a, b, c;
	long long n, a1, a2;
	cin >> n;
	if (n == 1) {
		cout << "0";
		return 0;
	}
	if (n == 2) {
		cin >> a1 >> a >> a2 >> b;
		if (a == b) {
			cout << "0";
			return 0;
		} else {
			if (a1 == a2) {
				cout << a1;
			} else if (a1 < a2) {
				cout << a1;
			} else {
				cout << a2;
			}
		}
		return 0;
	}
	if (n <= 10) {
		int sum;
		cin >> c;
		cin >> a;
		for (int i = 1; i <= n; i++) {
			cin >> c;
			cin >> b;
			if (a == b) {
				sum = n - 1;
			}
		}
		cout << sum;
	}
	return 0;
}