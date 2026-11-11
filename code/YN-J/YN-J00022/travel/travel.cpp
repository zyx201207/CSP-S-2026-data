#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	bool ap = 0, bp = 0;
	cin >> a >> b >> c >> d;
	if (a == c)
		cout << 1, ap = 1;
	else
		cout << 0, ap = 0;
	if (ap && b[0] == d[0] && b[1] == d[1])
		cout << 1, bp = 1;
	else
		cout << 0, bp = 0;
	if (bp && (int(b[2]) - 'A' < 3 && int(d[2]) - 'A' < 3) || ((int(b[2]) - 'A' >= 3 && int(d[2]) - 'A' >= 3)))
		cout << 1;
	else
		cout << 0;
	if (abs(int(b[2]) - int(d[2])) == 1 && int(b[0] - '0') * 10 + int(b[1] - '0') == int(d[0] - '0') * 10 + int(d[1] - '0')
	        || b[2] == d[2] && abs(int(b[0] - '0') * 10 + int(b[1] - '0') - int(d[0] - '0') * 10 - int(d[1] - '0')) == 1)
		if (b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C')
			cout << 1;
		else
			cout << 0;
	else
		cout << 0;
	return 0;
}