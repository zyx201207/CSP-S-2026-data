#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string sitx, sity, trainx, trainy;
	cin >> trainx >> sitx >> trainy >> sity;
	if (trainx == trainy)
		cout << 1;
	else
		cout << 0;
	if (sitx[0] == sity[0] && sitx[1] == sity[1])
		cout << 1;
	else
		cout << 0;
	int n = int(sitx[2]), m = int(sity[2]);
	if (n == 67 && m == 68)
		cout << 0;
	if (n == 65 || n == 66 || n == 67) {
		if (m == 65 || m == 66 || m == 67)
			cout << 1;
	} else if (n == 68 || n == 70) {
		if (m == 68 || m == 70)
			cout << 1;
	}
	if (n - m == 1 || m - n == 1 || m - n == 2 || n - m == 2)
		cout << 1;
	else
		cout << 0;
	return 0;
}