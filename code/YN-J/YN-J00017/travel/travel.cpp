#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string x, r, nx, nr;
	char c, s;
	cin >> x >> nx >> r >> nr ;
	int len = nx.length();
	if (x == r)
		cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	bool f = 1;
	for (int i = 0; i < len - 1; i++) {
		if (nx[i] != nr[i])
			f = 0;
	}
	if (f)
		cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if (nx[len - 1] == 'D' && nr[len - 1] == 'F' || nx[len - 1] == 'F' && nr[len - 1] == 'D') {
		cout << 1;
	} else if (nx[len - 1] == 'A' && nr[len - 1] == 'B' || nx[len - 1] == 'A' && nr[len - 1] == 'C')
		cout << "1";
	else if ( nx[len - 1] == 'B' && nr[len - 1] == 'A' || nx[len - 1] == 'B' && nr[len - 1] == 'C')
		cout << "1";
	else if ( nx[len - 1] == 'C' && nr[len - 1] == 'A' || nx[len - 1] == 'C' && nr[len - 1] == 'B')
		cout << "1";
	else
		cout << "00";
	if (nx[len - 1] == 'C' && nr[len - 1] == 'D' || nx[len - 1] == 'D' && nr[len - 1] == 'C') {
		cout << "0";
		return 0;
	} else if ((int)nx[len - 1] - 1 == (int)nr[len - 1] || (int)nx[len - 1] + 1 == (int)nr[len - 1]) {
		cout << "1";
	}	else if (nx[len - 1] == 'D' && nr[len - 1] == 'F' || nx[len - 1] == 'F' && nr[len - 1] == 'D')
		cout << "1";
	else
		cout << "0";
	return 0;
}