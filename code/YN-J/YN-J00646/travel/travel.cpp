#include <bits/stdc++.h>
using namespace std;

int main(void) {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, a1, b1;
	cin >> a >> b >> a1 >> b1;
	int c = 0, d, e;
	if (a == a1) {

		cout << '1';
		c = 1;
	} else
		cout << '0';

	if (b[0] == b1[0] && b[1] == b1[1])
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	else
		cout << '0';


	if ((b1[2] == 'D' && (b[2] == 'D' || b[2] == 'F')) || (b1[2] == 'F'
	        && (b[2] == 'D' || b[2] == 'F')) || (b1[2] == 'B' && (b[2] == 'A' || b[2] == 'C' || b1[2] == 'B')) || (b1[2] == 'A'
	                && (b[2] == 'A' || b[2] == 'C' || b1[2] == 'B')) || (b1[2] == 'C' && (b[2] == 'A' || b[2] == 'C' || b1[2] == 'B'))) {
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	} else
		cout << '0';

	d = 10 - int(b[1]);
	e = 10 - int(b1[1]);
	if ((int(b[1]) + 1 == int(b1[1]) || int(b[1]) - 1 == int(b1[1])) && (int(b[2]) + 1 == int(b1[2])
	        || int(b[2]) - 1 == int(b1[2])))
		cout << '0';
	else if ((int(b[1]) + 1 == int(b1[1]) || int(b[1]) - 1 == int(b1[1]))) {
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	} else if ( d + 1 == int(b1[1]) ||  d - 1 == int(b1[1]))
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	else if (((int(b[2]) + 1 == int(b1[2]) && (b[2] != 'C' && b1[2] != 'D') && (b[2] != 'D' && b1[2] != 'C'))
	          || (int(b[2]) - 1 == int(b1[2])) && (b[2] != 'C' && b1[2] != 'D') && (b[2] != 'D' && b1[2] != 'C'))) {
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	} else if ((b1[2] == 'D' && b[2] == 'F') || (b[2] == 'D' && b1[2] == 'F'))
		if (c == 1)
			cout << '1';
		else
			cout << '0';
	else
		cout << '0';
	return 0;
}