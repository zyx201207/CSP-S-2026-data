#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[500005];
bool f(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (a[i] == a[i - 1])
		{
			return false;
		}
	}
	return true;
}
bool f1(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (a[i - 1] > a[i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (f(n))
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i;j <= n;j++)
			{
				b[a[j]]++;
			}
		}
		for (int i = 1;i <= m;i++)
		{
			cout << b[i] << " ";
		}
		return 0;
	}
	if (f1(n))
	{
		for (int i = 1;i <= n;i++)
		{
			for (int j = i + 1;j <= n;j++)
			{
				if (a[j - 1] != a[j])
				{
					b[a[j]]++;
				}
			}
		}
		for (int i = 1;i <= m;i++)
		{
			cout << b[i] << " ";
		}
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = i;j <= n;j++)
		{
			c[j] = a[j];
			for (int k = 1;k < j;k++)
			{
				if (c[k] == a[j])
				{
					for (int l = k;l < j;l++)
					{
						c[l] = 0;
					}
					break;
				}
			}
		}
		for (int j = i;j <= n;j++)
		{
			b[c[j]]++;
			c[j] = 0;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
