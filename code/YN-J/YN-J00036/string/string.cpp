#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a, sum = 0;
	string s = "";
	cin >> a;
	for (int i = 0; i < a; i++) {
		long long c;
		char b;
		cin >> c >> b;
		sum += c;
		for (int j = 0; j < c; j++) {
			s += b;
		}
	}
	long long l = sum / 2;
	string x = "", y = "";
	if (sum & 1) {
		x = s.substr(0, l - 1);
		y = s.substr(l + 1, sum - 1);
	} else {

		x = s.substr(0, l - 1);
		y = s.substr(l, sum - 1);
	}
	if (x == y) {
		cout << '0';
	} else {
		bool flag = 0;
		long long d = x.size();
		for (int i = 0; i < d; i++) {
			if (x[i] != y[d - i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			cout << '0';
		} else {
			cout << d + 1;
		}
	}
	return 0;
}