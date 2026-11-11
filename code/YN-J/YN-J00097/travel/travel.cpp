#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	bool flag = true;

	if (c1 == c2) {
		cout << "1";
	} else {
		cout << 0;
		flag = false;
	}

	bool flag1 = true;

	if (s1[0] == s2[0] && s1[1] == s2[1] && flag) {
		cout << 1;
	} else {
		cout << 0;
		flag1 = false;
	}

	int x = s1[2] - 64;
	int y = s2[2] - 64;
	bool flag2 = true;

	if (((x <= 3 && y <= 3) || (x > 3 && y > 3)) && flag1) {
		cout << 1;
	} else {
		cout << 0;
		flag2 = false;
	}

	if (abs(x - y) == 1 && flag2) {
		cout << 1;
	} else {
		cout << 0;
	}

	return 0;
}
