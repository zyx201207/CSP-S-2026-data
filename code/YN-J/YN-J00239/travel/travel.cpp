#include <bits/stdc++.h>
using namespace std;
string r1, r2, x1, x2;

int toi(char c) {
	if (c == 'A')
		return 1;
	if (c == 'B')
		return 2;
	if (c == 'C')
		return 3;
	if (c == 'D')
		return -1;
	if (c == 'F')
		return -2;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r1 >> r2 >> x1 >> x2;
	if (r1 == x1) {
		cout << 1;
		int l1, l2;
		if (r2[0] == 0)
			l1 = r2[1] - '0';
		else
			l1 = 10 * (r2[0] - '0') + r2[1] - '0';
		if (x2[0] == 0)
			l2 = x2[1] - '0';
		else
			l2 = 10 * (x2[0] - '0') + x2[1] - '0';
		if (l1 == l2) {
			cout << 1;
			int s1 = toi(r2[2]), s2 = toi(x2[2]);
			if ((s1 * s2) > 0) {
				cout << 1;
				if (abs(s2 - s1) == 1)
					cout << 1;
				else
					cout << 0;
			} else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
	fclose(stdin);
	fclose(stdout);
}