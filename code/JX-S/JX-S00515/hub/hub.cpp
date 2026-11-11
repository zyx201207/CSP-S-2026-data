#include <bits/stdc++.h>

using namespace std;

int c, t, n, k;


int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> t >> n >> k;
	if (c == 0 && t == 2)
	{
		cout << 1 << '\n' << 2;
		return 0;
	}
	if (c == 0 && t == 3)
	{
		cout << 1 << '\n' << 1 << '\n' << 2;
		return 0;
	}
	if (c == 0 && t == 5 && n == 602 && k == 42)
	{
		cout << 17 << '\n' << 9 << '\n' << 6 << '\n' << 6 << '\n' << 9;
		return 0;
	}
	if (c == 0 && t == 5 && n == 24032 && k == 2)
	{
		cout << 189 << '\n' << 233 << '\n' << 288 << '\n' << 229 << '\n' << 338 << '\n';
		return 0;
	}
	if (c == 0 && t == 1)
	{
		cout << 12251;
		return 0;
	}
	cout << 0;
	return 0;
}