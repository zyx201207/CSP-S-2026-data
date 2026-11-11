#include <bits/stdc++.h>
using namespace std;

int ans[4] = {0, 0, 0, 0};

int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != c) {
		cout << "0000" << endl;
		return 0;
	}
	ans[0] = 1;
	int x = -1, y = -1;
	if (b[0] == d[0] && b[1] == d[1]) ans[1] = 1; 
	if (b[2] >= 'D' && b[2] <= 'F') x = 1;
	else x = 0;
	if (d[2] >= 'D' && d[2] <= 'F') y = 1;
	else y = 0;
	if (x == y && ans[1] == 1) ans[2] = 1;
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		if (ans[i] == 0) ok = false;
	}
	if (ok) {
		if (b[2] + 1 == d[2] || b[2] - 1 == d[2]) ans[3] = 1;	
	}
	for (int i = 0; i < 4; i++) cout << ans[i];
	cout << endl;
	return 0;
} 
