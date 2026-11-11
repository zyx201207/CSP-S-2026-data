#include <bits/stdc++.h>
using namespace std;
int n, a[200005];
long long zong, cnt = 0;
char c[200005];
bool flag = 1;
int main ()
{
	freopen ("string.in", "r",stdin);
	freopen ("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		zong += a[i];
		if (flag = 1 && c[i-1] != c[i])
			flag = 0;
	}
	if (flag == 1)
	{
		cout << 0;
		return 0;
	}
	long long la = 1, ra = n;
	while (la <= ra)
	{
		if (c[la] != c[ra])
		{
			if (a[la] > a[ra])
			{
				cnt += a[ra];
				a[la] -= a[ra];
				ra--;
			}
			else if (a[la] < a[ra])
			{
				cnt += a[la];
				a[ra] -= a[la];
				la++;
			}
			else
			{
				cnt += a[ra];
				la++;
				ra--;
			}
		}
		else
		{
			if (a[la] > a[ra])
			{
				a[la] -= a[ra];
				ra--;
			}
			else if (a[la] < a[ra])
			{
				a[ra] -= a[la];
				la++;
			}
			else
			{
				la++;
				ra--;
			}
		}
		
	}
	cout << cnt;
	return 0;
}
