#include <bits/stdc++.h>
using namespace std;

int main () {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	long long a;
	int s = 0;
	char b;
	long i;
	for (i = 1; i <= n; ++i) {
		int c;
		cin >> a >> b;
		if (b == c) {
			cout << "0";
			return 0;
		} else {
			s = s + a;
		}
		c = b;
	}
	cout << s / 2;
	return 0;
}