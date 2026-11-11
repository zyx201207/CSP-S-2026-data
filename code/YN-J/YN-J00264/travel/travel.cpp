#include <bits/stdc++.h>
using namespace std;

string a, b, x, y, ans;
int f;

signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ans = "0000";
	cin >> a >> b >> x >> y;
	if (a == x)
		ans[0] = '1';
	else {
		cout << ans;
		return 0;
	}
	string l = "", r = "";
	for (int i = 0; i < 2; i++)
		l += b[i], r += y[i];
	if (l == r && !f)
		ans[1] = '1';
	else {
		cout << ans;
		return 0;
	}
	if (((b[2] == 'D' && y[2] == 'F') || (b[2] == 'F' && y[2] == 'D')) && !f)
		ans[2] = ans[3] = '1';
	else if ((b[2] == 'A' || b[2] == 'B' || b[2] == 'C') && (y[2] != 'D' && y[2] != 'F') && !f)
		ans[2] = '1';
	else {
		cout << ans;
		return 0;
	}
	if (b[2] == y[2] + 1 || b[2] == y[2] - 1)
		ans[3] = '1';
	cout << ans;
	return 0;
}
//ToonoHanna