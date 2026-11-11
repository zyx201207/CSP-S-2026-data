#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005],sum = -10000, num;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++)
	{
		cin >> a[i];
	}
	if (m == n)
	{
		sum = a[1];
		for (int i = 2;i <= n;i ++)
		{
			sum = (sum & a[i]);
		}
		cout << sum;
		return 0;
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i ++)
		{
			if (a[i] > sum)
			{
				sum = a[i];
			}
		}
		cout << sum;
		return 0;
	}
	if (m == 2)
	{
		for (int i = 1;i <= n - 1;i ++)
		{
			for (int j = i + 1;j <= n;j ++)
			{
				if ((a[i] & a[j]) > sum)
				{
					sum = (a[i] & a[j]);
				}
			}
		}
		cout << sum;
		return 0;
	}
	if (m = n - 1)
	{
		for (int i = 1;i <= n;i ++)
		{
			for (int j = 1;j <= n - 1;j ++)
			{
				if (j == i || (j == n - 1 && i == n))
				{
					continue;
				}
				num = (a[i] & a[i + 1]);
			}
			if (num > sum)
			{
				sum = num;
			}
		}
		cout << sum;
	}
	return 0;
}
