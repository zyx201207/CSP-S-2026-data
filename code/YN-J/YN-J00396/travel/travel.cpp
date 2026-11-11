#include <bits/stdc++.h>
#define ll long long
using namespace std;
string cR, sR, cX, sX;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> cR >> sR >> cX >> sX;
	if (cR != cX) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (sR[0] != sX[0] || sR[1] != sX[1]) {
		cout << "000";
		return 0;
	}
	cout << 1;
	if (sR[2] <= 'C' && sX[2] >= 'D') {
		cout << "00";
		return 0;
	}
	cout << 1;
	if (abs(sR[2] - sX[2]) == 1)
		cout << 1;
	else
		cout << 0;
	return 0;
}