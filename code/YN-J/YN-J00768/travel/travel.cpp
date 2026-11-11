#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int  e[1001], ee[1001], aa[101], bb[101], h = 0, he = 0, m = 0, n = 0;
	string b, d, a, c;
	cin >> a >> b >> c >> d;

	for (int i = 0; i < 2; i++) {

		aa[i] = int(a[i]);
		bb[i] = int(c[i]);
		m += aa[i];
		n += bb[i];
	}

	if (m == n) {
		cout << "1";
	} else
		cout << "0";


	for (int i = 0; i < 3; i++) {

		e[i] = int(b[i]);
		ee[i] = int(d[i]);
		h = e[0] + e[1];
		he = ee[0] + ee[1];
	}

	if (h == he && m == n) {
		cout << "1";
	} else if (h != he || m != n) {
		cout << "0";
	}




	for (int i = 0; i < 3; i++) {

		if (int(b[2]) <= 67 && int(d[2]) <= 67 && h == he && m == n || int(b[2]) > 67 && int(d[2]) > 67 && h == he
		        && m == n  ) {
			cout << "1";
		} else if (int(b[2]) <= 67 && int(d[2]) > 67 || int(b[2]) > 67 && int(d[2]) <= 67 || h != he || m != n) {
			cout << "0";
		}

		break;
	}

	for (int i = 0; i < 3; i++) {

		if (int(b[2]) - int(d[2]) == 1 && h == he && m == n || int(d[2]) - int(b[2]) == 1 && int(b[2]) + int(d[2]) != 135
		        && h == he && m == n  ) {
			cout << "1";
		}

		else if (int(b[2]) - int(d[2]) != 1 && int(d[2]) - int(b[2]) != 1 || int(b[2]) + int(d[2]) == 135 || h != he
		         || m != n) {
			cout << "0";
		}

		break;
	}

	return 0;
}