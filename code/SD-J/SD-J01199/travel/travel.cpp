#include <bits/stdc++.h>
using namespace std;

//long long t, n, k, m, a[1000005];

int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000\n";
		return 0;
	}
	if (b[0] != d[0] || b[1] != d[1]) {
		cout << "1000\n";
		return 0;
	}
	if (b[2] <= 'C' && d[2] >= 'D') {
		cout << "1100\n";
		return 0;
	}
	if (b[2] != 'D' && abs (d[2] - b[2]) != 1) {
		cout << "1110\n";
		return 0;
	}
	cout << "1111\n";
	return 0;
}
