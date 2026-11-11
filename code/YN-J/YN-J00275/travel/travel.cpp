#include <bits/stdc++.h>
using namespace std;

char s1, s2, st1s, st2s;
long long nm1, st1, nm2, st2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> nm1 >> s1 >> s2 >> st1s;
	st1 = (s1 - '0') * 10 + (s2 - '0');
	cin >> nm2 >> s1 >> s2 >> st2s;
	st2 = (s1 - '0') * 10 + (s2 - '0');
	if (nm1 == nm2) {
		cout << 1;
		if (st1 == st2) {
			cout << 1;
			if ((st1s >= 'A') && (st1s <= 'C') && (st2s >= 'A') && (st2s <= 'C')) {
				cout << 1;
				if (((st1s + 1) == st2s) || ((st1s - 1) == st2s))
					cout << 1;
				else
					cout << 0;
			}
			else {
				if (((st1s == 'D') && (st2s == 'F')) || ((st1s == 'F') && (st2s == 'D')))
					cout << "11";
				else
					cout << "00";
			}
		}
		else {
			cout << "000";
		}
	}
	else {
		cout << "0000";
	}
	return 0;
}
