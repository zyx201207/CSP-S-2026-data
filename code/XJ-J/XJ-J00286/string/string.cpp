#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n,a,ans = 0,sum = 0;
	string c,s;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		cin >> c;
		for (int j = 1; j <= a; j++)
		{
			s += c;
			sum++;
		}
	}
	string x;
	for (int i = sum - 1; i >= 0; i--)
	{
		x += s[i];
	}
	if (x == s)
	{
		cout << ans;
	}
	else
	{
		for (int i = 0; i < sum; i++)
		{
			if (s[i] != x[i])
			{
				x[i] = s[i];
				s[sum - 1 - i] = s[i];
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
}