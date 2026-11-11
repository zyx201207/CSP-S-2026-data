#include <bits/stdc++.h>
using namespace std;
long long a1, b1;
string a2, b2;

void solveabc() {
	if (!(a2[2] == 'A' && b2[2] == 'C' || a2[2] == 'C' && b2[2] == 'A')) {
		cout << "1111";
		return;
	} else {
		cout << "1110";
		return;
	}
}

void solvea() {
	if (a2[0] == b2[0] && a2[1] == b2[1]) {
		cout << "11";
		if (a2[2] == 'C' && b2[2] == 'B' || a2[2] == 'A' && b2[2] == 'C' || a2[2] == 'C' && b2[2] == 'A' || a2[2] == 'A'
		        && b2[2] == 'B' || a2[2] == 'B' && b2[2] == 'A' || a2[2] == 'B' && b2[2] == 'C' || a2[2] == 'D' && b2[2] == 'F'
		        || a2[2] == 'F' && b2[2] == 'D') {
			cout << "1";
			if (!(a2[2] == 'A' && b2[2] == 'C' || a2[2] == 'C' && b2[2] == 'A')) {
				cout << "1";
				return;
			} else {
				cout << '0';
				return;
			}
		} else {
			cout << "00";
			return;
		}
	} else {
		cout << "1000";
		return;
	}
}

void solve() {
	cin >> a1 >> a2 >> b1 >> b2;
	if (a1 != b1) {
		cout << "0000";
		return;
	}
	if (a1 == b1 && a2[0] == b2[0] && a2[1] == b2[1]) {
		if (a2[2] == 'C' && b2[2] == 'B' || a2[2] == 'A' && b2[2] == 'C' || a2[2] == 'C' && b2[2] == 'A' || a2[2] == 'A'
		        && b2[2] == 'B' || a2[2] == 'B'
		        && b2[2] == 'A' || a2[2] == 'B' && b2[2] == 'C' || a2[2] == 'D' && b2[2] == 'F' || a2[2] == 'F' && b2[2] == 'D') {
			solveabc();
			return;
		} else {
			cout << "1100";
			return;
		}
	}
	if (a1 == b1) {
		solvea();
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	solve();
	return 0;
}