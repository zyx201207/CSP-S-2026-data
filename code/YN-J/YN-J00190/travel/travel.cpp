#include <bits\stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
//	cout << a << b << c << d;
	if (a != c) {
		cout << "0000";
		return 0;
	}
	cout << 1;
	if (b[0] != d[0] || b[1] != d[1]) {
		cout << "000";
		return 0;
	}
	cout << 1;
	char bb = b[2], dd = d[2];
	cout << bb << " " << dd << endl;
	if ((bb == 'A' || bb == 'B' || bb == 'C') && (dd == 'A' || dd == 'B' || dd == 'C'))
		cout << 1;
	else if ((bb == 'D' || bb == 'E') && (dd == 'D' || dd == 'E')) {
		cout << 1;
	} else {
		cout << "00";
		return 0;
	}
	if (bb + 1 == dd || bb - 1 == dd)
		cout << 1;
	else
		cout << 0;
	return 0;
}