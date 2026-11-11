#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a[30000], l = 0, x = 0;
	char c[30000], t[1800000];
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		for (long long j = 1; j <= a[i]; j++)
		{
			t[l + j] = c[i];
		}
		l += a[i];
	}
	if (l % 2 == 1)
	{
		for (long long i = 1; i <= (l - 1) / 2; i++)
		{
			if (t[i] != t[l + 1 - i]) x++;
		}
	}
	if (l % 2 == 0)
	{
		for (long long i = 1; i <= l / 2; i++)
		{
			if (t[i] != t[l + 1 - i]) x++;
		}
	}
	cout << x;
	return 0;
}