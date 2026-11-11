#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a, b, n, m;
	cin >> n >> a >>  m >> b ;

	if (n == m) {
		cout << "1";
	} else {
		cout << "0";
	}

	for (int i = 1; i <= 999; i++) {

		if (a[i] - '0' == b[i] - '0') {
			cout << "1";
			break;
		} else {
			cout << "0";
			break;
		}

	}

	for (int i = 1; i <= 999; i++) {

		if ( a[i] - '0' == b[i] - '0' && n == m && (a[i] - 'A' == 3 || a[i] - 'A' == 4 && b[i] - 'A' == 3 || b[i] - 'A' == 4)) {
			cout << "0";
			break;
		} else if (a[i] - '0' == b[i] - '0' && n == m && (a[i] - 'A' == 0 || a[i] - 'A' == 1 || a[i] - 'A' == 2
		           && b[i] - 'A' == 0 || b[i] - 'A' == 1 || b[i] - 'A' == 2)) {
			cout << "0";
			break;
		} else {
			cout << "1";
			break;
		}
	}

	for (int i = 1; i <= 999; i++) {

		if (n == m && a[i] - 'A' == b[i] - 'A' || b[i] - 'A' - a[i] - 'A' == 1 || a[i] - 'A' - b[i] - 'A' == 1) {
			cout << "1";
			break;
		} else {
			cout << "0";
			break;
		}
	}

	return 0;
}
