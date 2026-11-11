#include <bits/stdc++.h>
using namespace std;
string a1, b1, a2, b2;
long long a, b;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> a1 >> a2 >> b1 >> b2;
	if (a2[2] == 'A' || a2[2] == 'B' || a2[2] == 'C')
		a = 1;
	else
		a = 0;
	if (b2[2] == 'A' || b2[2] == 'B' || b2[2] == 'C')
		b = 1;
	else
		b = 0;
	if (a1 == b1) {
		cout << 1;
		if (a2[0] == b2[0] && a2[1] == b2[1]) {
			cout << 1;
			if (a == b) {
				cout << 1;
				if (abs(a2[2] - b2[2]) == 1)
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
}