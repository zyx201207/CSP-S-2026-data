#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	string a, b, c, d;
	int e[4] = {};
	cin >> a >> b >> c >> d;
	if (a == c)
		e[0] = 1;
	else
		e[0] = 0;
	if (b[0] == d[0] && b[1] == d[1])
		e[1] = 1;
	else
		e[1] = 0;

	if (b[2] - 'A' == 3 && d[2] - 'A' == 4 || b[2] - 'A' == 4 & d[2] - 'A' == 3) {


		e[2] = 1;
		e[3] = 1;
	}
	if (b[2] - 'A' == 2 && d[2] - 'A' == 3 || b[2] - 'A' == 3 & d[2] - 'A' == 2) {


		e[2] = 0;
		e[3] = 0;
	} else if (b[2] - d[2] == 2 || b[2] - d[2] == -2) {


		e[2] = 1;
		e[3] = 0;
	} else if (b[2] - d[2] == 1 || b[2] - d[2] == -1) {



		e[2] = 1;
		e[3] = 1;
	}

	cout << e[0] << e[1] << e[2] << e[3];
	return 0;
}