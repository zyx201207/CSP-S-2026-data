#include <bits/stdc++.h>
using namespace std;
//#define DBGMODE false
//#define dbg if(DBGMODE)cout
//#define ifd if(DBGMODE)
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(NULL);
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	int r_car, x_car;
	int r_x, x_x, r_y, x_y;
	string r_seat, x_seat;
	cin >> r_car >> r_seat >> x_car >> x_seat;
	r_x = (r_seat[0] - '0') * 10 + (r_seat[1] - '0');
	r_y = (r_seat[2] - 'A' + 1);
	x_x = (x_seat[0] - '0') * 10 + (x_seat[1] - '0');
	x_y = (x_seat[2] - 'A' + 1);
//	dbg << "rx: " << r_x << ' ' << "xx: " << x_x << '\n';
	cout << int(r_car == x_car) << int((r_x == x_x) && (r_car == x_car));
	if ((r_car == x_car) && (r_x == x_x) && ((r_y >= 4 && x_y >= 4) || (r_y <= 3 && x_y <= 3))) {
		cout << 1;
	} else {
		cout << 0;
	}
	if ((r_car == x_car) && (r_x == x_x) && (abs(r_y - x_y) == 1) && ((r_y >= 4 && x_y >= 4) || (r_y <= 3 && x_y <= 3))) {
		cout << 1;
	} else {
		cout << 0;
	}
	return 0;
}
