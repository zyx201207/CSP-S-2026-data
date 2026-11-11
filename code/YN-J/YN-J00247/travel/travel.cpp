#include <bits/stdc++.h>
using namespace std;
#define int long long
string a, b, c, d, x, y;
bool ans[5];

bool aaa() {
	bool f = 1;
	if (b[2] == 'C' && d[2] == 'D')
		return 0;
	if (d[2] == 'C' && b[2] == 'D')
		return 0;
	return 1;
}

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	int A = stoll(a), C = stoll(c);
	x[0] = b[0], x[1] = b[1];
	y[0] = d[0], y[1] = d[1];
	int B = stoll(x), D = stoll(y);
	if (b[2] == 'F')
		b[2] = 'E';
	if (d[2] == 'F')
		d[2] = 'E';
	if (A == C)
		ans[1] = 1;
	else {
		cout << "0000";
		return 0;
	}
	if (B == D && ans[1])
		ans[2] = 1;
	else {
		cout << "1000";
		return 0;
	}
	if (((b[2] >= 'A' && b[2] <= 'C') && (d[2] >= 'A' && d[2] <= 'C')) || ((b[2] >= 'D' && b[2] <= 'E') && (d[2] >= 'D'
	        && d[2] <= 'E')) && ans[2])
		ans[3] = 1;
	else {
		cout << "1100";
		return 0;
	}
	if (abs((int)d[2] - (int)b[2]) == 1 && aaa() && ans[3])
		ans[4] = 1;
	else {
		cout << "1110";
		return 0;
	}
	cout << ans[1] << ans[2] << ans[3] << ans[4];
	return 0;
}
