#include <iostream>
#include <cmath>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	char a, b, c, d;
	bool m = 0, k = 0, o = 0, l = 0, p = 0;
	cin >> a >> c >> b >> d;
	if (a == b) {
		cout << "1";
	} else {
		cout << "0000";
	}
	char pp = c[1], ps = d[1];
	if (a == b) {
		if (pp = ps) {
			m = 1;
			cout << m;
		} else {
			cout << m;
		}
	}
	char pq = c[2], pw = d[2];
	if (m == 1) {
		if (pq == "A" && pw = "B") {
			cout << "11";
		}
		if (pq == "A" && pw = "C") {
			cout << "10";
		}
		if (pq == "A" && pw = "D") {
			cout << "00";
		}
		if (pq == "A" && pw = "F") {
			cout << "00";
		}
		if (pq == "B" && pw = "A") {
			cout << "11";
		}
		if (pq == "B" && pw = "C") {
			cout << "11";
		}
		if (pq == "B" && pw = "D") {
			cout << "00";
		}
		if (pq == "B" && pw = "F") {
			cout << "00";
		}
		if (pq == "C" && pw = "A") {
			cout << "10";
		}
		if (pq == "C" && pw = "B") {
			cout << "11";
		}
		if (pq == "C" && pw = "D") {
			cout << "00";
		}
		if (pq == "C" && pw = "F") {
			cout << "00";
		}
		if (pq == "D" && pw = "A") {
			cout << "00";
		}
		if (pq == "D" && pw = "B") {
			cout << "00";
		}
		if (pq == "D" && pw = "C") {
			cout << "00";
		}
		if (pq == "D" && pw = "F") {
			cout << "11";
		}
		if (pq == "F" && pw = "A") {
			cout << "00";
		}
		if (pq == "F" && pw = "B") {
			cout << "00";
		}
		if (pq == "F" && pw = "C") {
			cout << "00";
		}
		if (pq == "F" && pw = "D") {
			cout << "11";
		}
	}
	return 0;
}