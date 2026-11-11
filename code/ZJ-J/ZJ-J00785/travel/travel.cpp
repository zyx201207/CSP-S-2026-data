#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == c) cout << 1;
	else {cout << "0000" << endl; return 0;}
	if (b[0] == d[0] && b[1] == d[1]) cout << 1;
	else {cout << "000" << endl; return 0;}
	int a1 = b[2] - 'A' + 1, a2 = d[2] - 'A' + 1;
	if ((a1 <= 3 && a2 <= 3) || (a1 >= 4 && a2 >= 4)) cout << 1;
	else {cout << "00" << endl; return 0;}
	if (abs(a1 - a2) == 1) cout << 1 << endl;
	else cout << "0" << endl;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	return 0;
}
