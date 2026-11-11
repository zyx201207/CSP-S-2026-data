#include <bits/stdc++.h>
using namespace std;
string x, y, a, b;
int xx, yy, u, v;
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> x >> a >> y >> b;
	xx = x[0] * 10 + x[1];
	yy = y[0] * 10 + y[1];
	if (xx == yy) cout << 1;
	else
	{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	u = a[0] * 10 + a[1];
	v = b[0] * 10 + b[1];
	if (u == v) cout << 1;
	else
	{
		cout << 0 << 0 << 0;
		return 0;
	}
	if ((a[2] == 'A' || a[2] == 'B' || a[2] == 'C') && (b[2] == 'A' || b[2] == 'B' || b[2] == 'C'))
		cout << 1;
	else if ((a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F'))
	{
		cout << 1 << 1;
		return 0;
	}
	else
	{
		cout << 0 << 0;
		return 0;
	}
	if ((a[2] == 'A' && b[2] == 'B') || (a[2] == 'B' && (b[2] == 'C' || b[2] == 'A'))
	|| (a[2] == 'C' && b[2] == 'B') || ((a[2] == 'D' || a[2] == 'F') && (b[2] == 'D' || b[2] == 'F')))
		cout << 1;
	else cout << 0;
	return 0;
}