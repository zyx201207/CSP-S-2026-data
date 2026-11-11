#include <bits/stdc++.h>
using namespace std;
int I, you;
string love, yzy;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> I >> love >> you >> yzy;
	if (I != you) {
		cout << "0000";
		return 0;
	} else {
		cout << "1";
	}
	string sx = love.substr(0, 2);
	string sy = yzy.substr(0, 2);
	if (sx != sy) {
		cout << "000";
		return 0;
	} else
		cout << "1";
	char cx = love[2];
	char cy = yzy[2];
	if ((cx <= 'C' && cy >= 'D') || (cx >= 'D' && cy <= 'C')) {
		cout << "00";
		return 0;
	} else
		cout << "1";
	int a = cx - 'A';
	int b = cy - 'A';
	if (abs(a - b) == 1 || (cx == 'D' && cy == 'F') || (cy == 'D' && cx == 'F')) {
		cout << "1";
	} else
		cout << "0";
	return 0;
}
