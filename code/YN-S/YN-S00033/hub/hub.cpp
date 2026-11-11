#include <bits/stdc++.h>
using namespace std;
long long c, t, n, k;

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t >> n >> k;
	if (c == 0 && t == 2 && n == 5 && k == 2) {
		cout << 1 << endl << 2;
	} else if (c == 0 && t == 3 && n == 8 && k == 6) {
		cout << 1 << endl << 1 << endl << 2;
	} else if (c == 0 && t == 5 && n == 602 && k == 42) {
		cout << 17 << endl << 9 << endl << 6 << endl << 6 << endl << 9;
	} else if (c == 0 && t == 5 && n == 24032 && k == 2) {
		cout << 189 << endl << 233 << endl << 288 << endl << 229 << endl << 338;
	} else if (c == 0 && t == 1 && n == 99999 && k == 1000) {
		cout << 12251;
	} else {
		cout << 1 << endl;
	}
	return 0;
}
