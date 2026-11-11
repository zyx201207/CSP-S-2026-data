#include <bits/stdc++.h>
using namespace std;
int n[5];
int m[5];
char c[5];

signed main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	for (int i = 1; i <= 2; i++) {
		int a;
		string b;
		cin >> a >> b;
		n[i] = a;
		for (int j = 0; j < b.size(); j++) {
			if (b[j] >= '0' && b[j] <= '9') {
				m[i] += int(b[j] - '0') * 10;
			} else if (b[j] >= 'A' && b[j] <= 'F' && b[j] != 'E') {
				c[i] = b[j];
			}
		}
	}
	if (n[1] == n[2]) {
		cout << 1;
		if (m[1] == m[2]) {
			cout << 1;
			if ((c[1] >= 'A' && c[1] <= 'C' && c[2] >= 'A' && c[2] <= 'C') || (c[1] >= 'D' && c[1] <= 'F' && c[2] >= 'D'
			        && c[2] <= 'F')) {
				cout << 1;
				if ((abs(c[1] - c[2]) == 1 && c[1] >= 'A' && c[1] <= 'C' && c[2] >= 'A' && c[2] <= 'C') || (c[1] == 'D' && c[2] == 'F')
				        || (c[1] == 'F' && c[2] == 'F')) {
					cout << 1;
				} else {
					cout << 0;
				}
			} else {
				cout << "00";
			}
		} else {
			cout << "000";
		}
	} else {
		cout << "0000";
	}


	return 0;
}