#include <bits/stdc++.h>
using namespace std;

int main() {
	freopon("travel.in", "r", stdin);
	freopon("travel.out", "w", stdout);
	int a, c;
	string b, d;
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000";
	} else if (a == c) {
		cout << '1';
		if (b[0] == d[0] && b[1] == d[1]) {
			cout << '1';
			if (b[2] <= 'c' && b[2 >= 'A'] && (d[2] <= 'e') && d[2] >= 'A');
			cout << '1';
		} else if ((b[2] == 'E' || b[2] == 'F') && (d[2] == 'c' && d[2] == 'B')) {
			cout << '1';
		} else {
			cout << '0';
		}
	}
	return 0;
}