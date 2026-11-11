#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
int n, a[M];
string s;
char c[M];
int main()
{
	freopen ("string.in", "r", stdin);
	freopen ("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> c[i];
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	if (c[1] == c[2])
	{
		cout << 0;
		return 0;
	}
	else
	{
		if(a[1] > a[2])
		{
			cout << a[2];
			return 0;
		}
		else
			cout << a[1];
	}
	return 0;
}
