#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	char a[6], b[6];
	for (int i = 1; i <= 5; i++)
		cin >> a[i];
	for (int i = 1; i <= 5; i++)
		cin >> b[i];
	if (a[1] == b[1] && a[2] == b[2])
		q++;
	else {
		cout << "0000";
		return 0;
	}
	if (a[3] == b[3] && a[4] == b[4])
		q++;
	else {
		cout << 1000;
		return 0;
	}
	if (a[5] == 'B' && b[5] == 'A' || a[5] == 'A' && b[5] == 'B' || a[5] == 'E' && b[5] == 'D') {
		q++;
	} else if ( a[5] == 'B' && b[5] == 'C' || a[5] == 'C' && b[5]  == 'B' || a[5] == 'D' && b[5] == 'E')
		q++;
	else {
		cout << 1000;
		return 0;
	}
	if (int(a[5]) + 1 == int(b[5]) || int(a[5]) - 1 == int(b[5]))
		cout << 1111;
	else
		cout << 1110;
	return 0;
}