#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string c1, c2, c3, c4;
	int f1 = 0, f2 = 0, f3 = 0, f4 = 0;
	string n, m;
	char n1, m1;
	cin >> c1 >> c2 >> c3 >> c4;
	if (c1 != c3) {
		cout << "0000";
		return 0;
	} else {
		f1 += 1;
	}
	n[0] = c2[0];
	n[1] = c2[1];
	m[0] = c4[0];
	m[1] = c4[1];
	n1 = c2[2];
	m1 = c4[2];
	if (n[0] == m[0] && n[1] == m[1]) {
		f2 += 1;
		if (n1 == 'D' && m1 == 'F' || m1 == 'D' && n1 == 'F') {
			cout << "1111";
			return 0;
		} else if (n1 == 'A' || n1 == 'B' || n1 == 'C' && m1 == 'A' || m1 == 'B' || m1 == 'C') {
			f3 += 1;
			if (n1 == 'A' && m1 == 'B' || m1 == 'A' && n1 == 'B') {
				f4 += 1;
			} else if (n1 == 'B' && m1 == 'C' || m1 == 'B' && n1 == 'C') {
				f4 += 1;
			}
		}
	} else if (n != m) {
		cout << "1000";
		return 0;
	}
	cout << f1 << f2 << f3 << f4;

	return 0;
}