#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int c1, c2;
string sn, sm;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c1 >> sn >> c2 >> sm;
	bool cx = false, cp = false, pc = false, xl = false;
	if (c1 == c2) {
		cx = true;
	} else {
		cout << "0000";
		return 0;
	}
	int p1 = 0, p2 = 0;
	char R, X ;
	for (int i = 0; i <= 2; i++) {
		if (sn[i] >= '0' && sn[i] <= '9') {
			p1 = p1 * 10 + int(sn[i] - '0');
		}
		if (sn[i] >= 'A' && sn[i] <= 'Z') {
			R = sn[i];
		}
	}
	for (int i = 0; i <= 2; i++) {
		if (sm[i] >= '0' && sm[i] <= '9') {
			p2 = p2 * 10 + int(sm[i] - '0');
		}
		if (sm[i] >= 'A' && sm[i] <= 'Z') {
			X = sm[i];
		}
	}
	if (p2 == p1) {
		cp = true;
	}
	if (((R == 'D' || R == 'F') && (X == 'D' || X == 'F')) || ((R == 'A' || R == 'B' || R == 'C') && (X == 'A' || X == 'B'
	        || X == 'C')) && p2 == p1) {
		pc = true;
	}
	if (pc && (char(R + 1) == X || char(X + 1) == R) && !(R == 'C' && X == 'D')) {
		xl = true;
	}
	cout << cx << cp << pc << xl;
	return 0;
}