#include <bits/stdc++.h>
using namespace std;
char a[3], a1[4], b[3], b1[4];
int  f1 = 0, f2 = 0, f3 = 1, f4 = 1;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> a1 >> b >> b1;
	for (int i = 0; i < 2; i++) {
		if (a[i] != b[i]) {
			f1 = 1;
		}
	}
	if (f1 == 1)
		cout << "0000";
	if (f1 == 0) {
		for (int i = 0; i < 2; i++)
			if (a1[i] != b1[i]) {
				f2 = 1;
			}
		if (f2 == 1)
			cout << "1000" << f2;
		if (f2 == 0) {
			if ((a1[2] - 'C' > 0 and b1[2] - 'C' > 0) or (a1[2] - 'C' <= 0 and b1[2] - 'C' <= 0)) {
				f3 = 0;
				cout << "111";
			} else
				cout << "1100";
			if (f3 == 0) {
				if (abs(a1[2] - b1[2]) == 1)
					cout << 1;
				else
					cout << 0;
			}
		}

	}
	return 0;
}