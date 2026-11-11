#include <bits/stdc++.h>
using namespace std;
string a, c;
int b, d;

string pd(string a, string b) {
	if (a[2] == 'A' || a[2] == 'B' || a[2] == 'C') {
		if (b[2] == 'A' || b[2] == 'B' || b[2] == 'C') {
			return "0";
		}

	} else if (a[2] == 'C' || a[2] == 'F') {
		if (b[2] == 'C' || b[2] == 'F') {
			return "0";
		}
	}
	return "1";
}

string pdd(string a, string b) {
	if (a[2] == 'A') {
		if (b[2] == 'B') {
			return "1";
		}
	} else if (a[2] == 'B') {
		if (b[2] == 'A' || b[2] == 'C') {
			return"1";
		}
	} else if (a[2] == 'C') {
		if (b[2] == 'B' ) {
			return "1";
		}
	} else if (a[2] == 'C') {
		if (b[2] == 'B' ) {
			return "1";
		}
	} else {
		if (b[2] == 'D') {
			return "1";
		}
	}
	return "0";
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> b >> a >> d >> c;
	if (b == d) {
		if (a[0] == c[0] && a[1] == c[1]) {
			if (pd(a, c) == "1") {
				cout << "1100";
			} else {
				if (pdd(a, c) == "1") {
					cout << "1111";
				} else {
					cout << "1110";
				}
			}
		} else {
			cout << "1000";
		}
	} else {
		cout << "0000";
	}
	return 0;
}