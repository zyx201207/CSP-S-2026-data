#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a1, a2, b1, b2;
	cin >> a1 >> a2 >> b1 >> b2;

	if (a1 != b1) {
		cout << "0000";
		return 0;
	}

	int z1 = (a2[0] - '0') * 10 + (a2[1] - '0'), z2 = (b2[0] - '0') * 10 + (b2[1] - '0');

	if (z1 != z2) {
		cout << "1000";
		return 0;
	}

	int a = a2[2] - 'A' + 1, b = b2[2] - 'A' + 1;

	if (!((a <= 3 && b <= 3) || (a > 3 && b > 3))) {
		cout << "1100";
		return 0;
	}

	if (abs(a - b) == 1) {
		cout << "1111";
	} else {
		cout << "1110";
	}

	return 0;
}
