#include <bits/stdc++.h>
using namespace std;

struct node {
	string cx, zw;
} a, b;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> a.cx >> a.zw >> b.cx >> b.zw;
	if (a.cx == b.cx) {
		cout << 1;
		if (a.zw[0] == b.zw[0] && a.zw[1] == b.zw[1]) {
			cout << 1;
			if (a.zw[2] >= 'A' && a.zw[2] <= 'C' && b.zw[2] >= 'A' && b.zw[2] <= 'C') {
				cout << 1;
				if (abs(a.zw[2] - b.zw[2]) == 1)
					cout << 1;
				else
					cout << 0;
			} else if ((a.zw[2] == 'D' || a.zw[2] == 'F') && (b.zw[2] == 'D' || b.zw[2] == 'F'))
				cout << "11";
			else
				cout << "00";
		} else
			cout << "000";
	} else
		cout << "0000";
	return 0;
}