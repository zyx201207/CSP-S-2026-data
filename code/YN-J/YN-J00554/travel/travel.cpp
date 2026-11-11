#include <bits/stdc++.h>
using namespace std;
string rc, rz, xc, xz;

string a = {'0', '0', '0', '0'};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> rc >> rz >> xc >> xz;
	if (rc == xc) {
		a[0] = '1';
	}
	if (a[0] == '1') {
		if (rz[1] == xz[1]) {
			a[1] = '1';
		}
		if (a[1] == '1') {
			if (rz[2] == 'A' && xz[2] == 'B' || xz[2] == 'A' && rz[2] == 'B') {
				a[2] = '1';
			} else if (rz[2] == 'A' && xz[2] == 'C' || xz[2] == 'A' && rz[2] == 'C') {
				a[2] = '1';
			} else if (rz[2] == 'B' && xz[2] == 'C' || xz[2] == 'B' && rz[2] == 'C') {
				a[2] = '1';
			} else if (rz[2] == 'D' && xz[2] == 'F' || xz[2] == 'D' && rz[2] == 'F') {
				a[2] = '1';
			}
			if (a[2] == '1') {
				if (rz[2] - xz[2] == 1 || xz[2] - rz[2] == 1) {
					a[3] = '1';
				}
			}
		}

	}
	for (int i = 0; i <= 4; i++) {
		cout << a[i];
	}

	return 0;
}
