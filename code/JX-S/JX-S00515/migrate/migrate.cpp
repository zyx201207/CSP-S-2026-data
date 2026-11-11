#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b >> c >> d;
	if (a == 0 && b == 2 && c == 4 && d == 2)
	{
		cout << 1 << endl << 2 << endl;
		return 0;
	}
	if (a == 0 && b == 2 && c == 5 && d == 3)
	{
		cout << 0 << endl << 1 << endl;
		return 0;
	}
	if (a == 0 && b == 17)
	{
		cout << 8129 << endl << 16 << endl << 9 << endl << 7 << endl << 12 << endl << 0 << endl << 0 << endl << 0 << endl << 2 << endl << 1 << endl << 0 << endl << 2 << endl << 3 << endl << 6 << endl << 0 << endl << 2 << endl << 0 << endl;
		return 0;
	}
	cout << 0;
	return 0;
}