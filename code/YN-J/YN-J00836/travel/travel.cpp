#include <bits/stdc++.h>
using namespace std;
string cx1, cx2, zw1, zw2;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cx1 >> zw1 >> cx2 >> zw2;

	if (cx1 == cx2) {
		cout << 1;

		if (zw1[0] == zw2[0] && zw1[1] == zw2[1]) {
			cout << 1;

			if (zw1[2] < 'D' && zw2[2] < 'D') {
				cout << 1;

				if (zw1[2] == 'A' && zw2[2] == 'B' || zw2[2] == 'A' && zw1[2] == 'B')
					cout << 1;
				else if (zw1[2] == 'C' && zw2[2] == 'B' || zw2[2] == 'C' && zw1[2] == 'B')
					cout << 1;
				else
					cout << 0;
			} else if (zw1[2] >= 'D' && zw2[2] >= 'D')
				cout << 1 << 1;
			else
				cout << 0 << 0;
		} else
			cout << 0 << 0 << 0;
	} else
		cout << 0 << 0 << 0 << 0;
	return 0;
}
