#include <bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int flag;
int a1, a2, a3, a4;
int x[2];
int y;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == "01" || c1 == "16" || c2 == "01" || c2 == "16") {
		flag = 1;
	}

	if (c1 != c2 || flag == 1) {
		flag = 1;
	} else {
		a1 = 1;
	}

	if (flag != 1) {
		for (int i = 0; i < 2; i++) {

			if (s1[i] != s2[i]) {
				flag = 1;
				break;
			} else {
				x[i] = 1;
			}
		}

		if (x[0] == 1 && x[1] == 1) {
			a2 = 1;
		}
	}

	if (flag != 1) {
		if ((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'D' || s2[2] == 'F')) {
			flag = 1;
		} else {
			a3 = 1;
		}
	}

	if (flag != 1) {
		if (s1[2] > s2[2]) {
			y = s1[2] - s2[2];
		} else {
			y = s2[1] - s1[2];
		}

		if ((s1[2] == 'C' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'C') || y > 1) {
			flag = 1;
		} else {
			a4 = 1;
		}
	}

	cout << a1 << a2 << a3 << a4;
	return 0;
}