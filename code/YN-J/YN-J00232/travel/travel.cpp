#include <bits/stdc++.h>
using namespace std;
string cR, sR, cX, sX;
int num;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> cR >> sR >> cX >> sX;
	int ant = abs(sR[2] - sX[2]);
	if (cR == cX) {
		cout << 1;
	} else {
		cout << 0;
	}
	if (sR[0] == sX[0]) {
		if (sR[1] == sX[1]) {
			cout << 1;
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	if (sR[2] >= 'A' && sR[2] <= 'C' && sX[2] >= 'A' && sX[2] <= 'C') {
		cout << 1;
	} else if (sR[2] >= 'D' && sR[2] <= 'E' && sX[2] >= 'D' && sX[2] <= 'E') {
		num = 1;
		cout << num;
	} else {
		num = 0;
		cout << num;
	}
	if (ant == 1) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}