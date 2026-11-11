#include <bits/stdc++.h>
using namespace std;
int a_car, b_car;
string a_seat, b_seat;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a_car >> a_seat >> b_car >> b_seat;
	bool q1 = false, q2 = false, q3 = false, q4 = false;
	if (a_car == b_car) {
		cout << 1;
		q1 = true;
	} else
		cout << 0;
	if (q1 && a_seat[0] == b_seat[0] && a_seat[1] == b_seat[1]) {
		cout << 1;
		q2 = true;
	} else
		cout << 0;
	if ((a_seat[2] >= 'A' && a_seat[2] <= 'C') && (b_seat[2] >= 'A' && b_seat[2] <= 'C') && q1 && q2) {
		q3 = true;
		cout << 1;
	} else if (a_seat[2] >= 'D' && b_seat[2] >= 'D' && q1 && q2) {
		q3 = true;
		cout << 1;
	} else
		cout << 0;
	if (q1 && q2 && q3) {
		char ch = a_seat[2] + 1, ch1 = a_seat[2] - 1;
		if (ch == b_seat[2] || ch1 == b_seat[2]) {
			cout << 1;
		} else
			cout << 0;
	} else
		cout << 0;
	return 0;
}