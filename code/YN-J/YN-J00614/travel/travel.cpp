#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.ans", "w", stdout);
	string c1, s1, c2, s2;
	int is_same = -1;
	int rowc, rows;
	string seatc, seats;
	cin >> c1 >> s1 >> c2 >> s2;
	while (true) {
		if (c1 != c2) {
			is_same = 0;
			break;
		}

		seatc = s1[2];
		s1.erase(2);
		seats = s2[2];
		s2.erase(2);
		rowc = stoi(s1);
		rows = stoi(s2);

		if (rowc != rows) {
			is_same = 1;
			break;
		}

		if (seatc == "A" && seats == "B" || seatc == "A" && seats == "C" || seatc == "B" && seats == "C" || seats == "A"
		        && seatc == "B" || seats == "A" && seatc == "C" || seats == "B" && seatc == "C"  || seatc == "D" && seats == "F"
		        || seatc == "F" && seats == "D") {

		} else {
			is_same = 2;
			break;
		}

		if (seatc == "A" && seats == "C" || seatc == "C" && seats == "A") {
			is_same = 3;
			break;
		}

		is_same = 4;
		break;
	}

	for (int i = 0; i < is_same; i++)
		cout << 1;
	for (int i = 0; i < 4 - is_same; i++)
		cout << 0;
	return 0;
}