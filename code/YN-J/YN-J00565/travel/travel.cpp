#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1, s1, c2, s2;
	string d1, d2, d3, d4;
	cin >> c1 >> s1 >> c2 >> s2;

	if (c1 == c2) {
		d1 = "1";
	} else {
		d1 = "0";
	}

	string zwp1 = s1.substr(0, 2), zwp2 = s2.substr(0, 2);

	if (d1 == "1" && zwp1 == zwp2) {
		d2 = "1";
	} else {
		d2 = "0";
	}

	string zwh1 = s1.substr(2, 1), zwh2 = s2.substr(2, 1);

	if (d2 == "1") {
		if ((zwh1[0] <= 'C' && zwh2[0] >= 'D') || (zwh1[0] >= 'D' && zwh2[0] <= 'C')) {
			d3 = "0";
		} else {
			d3 = "1";
		}
	} else {
		d3 = "0";
	}

	if (d3 == "1") {
		if ((zwh1 == "A" && zwh2 == "B") || (zwh2 == "A" && zwh1 == "B") ||
		        (zwh1 == "B" && zwh2 == "C") || (zwh2 == "B" && zwh1 == "C") ||
		        (zwh1 == "D" && zwh2 == "F") || (zwh2 == "D" && zwh1 == "F")) {
			d4 = "1";
		} else {
			d4 = "0";
		}
	} else {
		d4 = "0";
	}

	string sd = d1 + d2 + d3 + d4;
	cout << sd;
	return 0;
}































