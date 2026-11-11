#include <bits/stdc++.h>

using namespace std;


string r11, r22, x11, x22;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> r11 >> r22 >> x11 >> x22;
	if (r11 == x11)
		cout << 1;
	else {
		cout << "0000";
		return 0;
	}
	bool v11 = 0;
	if (r22[0] == x22[0] && r22[1] == x22[1]) {
		v11 = 1;
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	bool v22 = 0;
	if (((r22[2] == 'A' || r22[2] == 'B' || r22[2] == 'C') && (x22[2] == 'A' || x22[2] == 'B' || x22[2] == 'C')) || ((r22[2] == 'E' || r22[2] == 'F') && (x22[2] == 'E' || x22[2] == 'F' ))) {
		if (v11 == 1) {
			cout << 1;
			v22 = 1;
		}
		else
			cout << 0;
	}
	else cout << 0;	
	if (v22 == 1 && abs(r22[2]- x22[2]) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}
