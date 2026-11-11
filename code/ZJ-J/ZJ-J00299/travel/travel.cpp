#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string r1, r2, x1, x2;
	int cnt = 0;
	cin >> r1 >> r2 >> x1 >> x2;
	if (r2[2] > x2[2]) {
		char a = x2[2];
		x2[2] = r2[2];
		r2[2] = a;
	}
	if (r1 == x1) {
		cnt++;
		cout << 1;
		if (r2[0] == x2[0] && r2[1] == x2[1]) {
			cnt++;
			cout << 1;
			if (r2[2] == x2[2] - 1 && r2[2] != 'C') {
				cnt += 2;
				cout << 11;
			} else if (r2[2] == 'A' && x2[2] == 'C') {
				cnt += 1;
				cout << 1;
			}
		}
	}
	while (cnt < 4) {
		cout << 0;
		cnt++;
	}
	return 0;
}