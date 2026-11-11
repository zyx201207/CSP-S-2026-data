#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int a, b;
	string a1, b1;
	bool flag1 = 0, flag2 = 0, flag3 = 0;
	cin >> a >> a1 >> b >> b1;
	int a2 = a1[0], a3 = a1[1];
	int b2 = b1[0], b3 = b1[1];
	char a4 = a1[2], b4 = b1[2];
	if (a == b) {
		cout << 1;
		flag1 = 1;
	} else {
		cout << 0;
	}
	if (flag1 == 1 && a2 == b2 && a3 == b3) {
		cout << 1;
		flag2 = 1;
	} else {
		cout << 0;
	}
	if (flag2 == 1 && ( (a4 >= 'A' && a4 <= 'C' && b4 >= 'A' && b4 <= 'C') || (a4 >= 'D' && a4 <= 'F' && b4 >= 'D'
	                    && b4 <= 'F'))) {
		cout << 1;
		flag3 = 1;

	} else {
		cout << 0;
	}
	if (flag3 == 1 && ((a4 == 'A' && b4 == 'B') || (b4 == 'A' && a4 == 'B') || (a4 == 'B' && b4 == 'C') || (b4 == 'B'
	                   && a4 == 'C')
	                   || (a4 == 'D' && b4 == 'F') || (b4 == 'D' && a4 == 'F'))) {
		cout << 1;

	} else {
		cout << 0;
	}

	return 0;
}