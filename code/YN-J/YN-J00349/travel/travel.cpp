#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2, t, t2;

char a[10] = {'O', 'A', 'B', 'C', 'D', 'F'};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	} else {
		cout << "0000";
		return 0;
	}
	t = s1[0] + s1[1];
	t2 = s2[0] + s2[1];
	if (t == t2) {
		cout << 1;
	} else {
		cout << "000";
		return 0;
	}
	if ((s1[2] <= 'C' && s2[2] <= 'C') || (s1[2] >= 'D' && s2[2] >= 'D')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	for (int i = 1; i <= 5; i++) {
		if (s1[2] == a[i]) {
			if (s2[2] == a[i - 1] || s2[2] == a[i + 1]) {
				cout << 1;
				return 0;
			} else {
				cout << 0;
				return 0;
			}
		}
	}
	return 0;
}