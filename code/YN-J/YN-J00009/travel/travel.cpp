#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string r1, r2, x1, x2;
	cin >> r1 >> r2 >> x1 >> x2;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 1; i <= 2; i++) {
		if (r1[i] == x1[i])
			cnt1++;
	}
	if (cnt1 == 2) {
		cout << '1';
		if (r2[3] == x2[3]) {
			cout << "1";
			if (r2[2] == x2[2]) {
				cout << '1';
				if (r2[3] == 'F' || r2[3] == 'D')
					cout << '1';
				else if (r2[3] == x2[3] + 1 || r2[3] + 1 == x2[3])
					cout << '1';
				else if (r2[3] == x2[3])
					cout << '1';
				else
					cout << '0';
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}