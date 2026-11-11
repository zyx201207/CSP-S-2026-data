#include <bits/stdc++.h>
using namespace std;
string R, r, X, x;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> R >> r >> X >> x;
	if (R != X) {
		cout << "0000";
	} else if (r[0] != x[0] || r[1] != x[1]) {
		cout << "1000";
	} else if (r[2] <= 'C' && x[2] >= 'D' || x[2] <= 'C' && r[2] >= 'D') {
		cout << "1100";
	} else if (r[2] == 'A' && x[2] == 'C' || x[2] == 'A' && r[2] == 'C') {
		cout << "1110";
	} else {
		cout << "1111";
	}
	return 0;
}