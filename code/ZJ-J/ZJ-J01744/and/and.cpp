#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool f(int n)
{
	for (int i = 1;i <= n;i++)
	{
		if (a[i] > 3)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxx = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m == 1)
	{
		for (int i = 1;i <= n;i++)
		{
			maxx = max(maxx,a[i]);
		}
		cout << maxx;
	}
	else if (m == n)
	{
		int u = a[1];
		for (int i = 2;i <= n;i++)
		{
			u &= a[i];
		}
		cout << u;
	}
	else if (m == 2)
	{
		for (int i = 1;i <= n;i++)
		{
			int u = a[i];
			for (int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,u & a[j]);
			}
		}
		cout << maxx;
	}
	else if (m == n - 1)
	{
		int l = 2,u = a[1];
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (j != l)
					u &= a[j];
			}
			l++;
			if (l > n)
			{
				l = 1;
				u = a[2];
			}
			else
			{
				u = a[1];
			}
		}
	}
	else if (f(n))
	{
		sort(a + 1,a + 1 + n);
		reverse(a + 1,a + 1 + n);
		if (a[m] == 3)
		{
			cout << 3;
		}
		else if (a[m] = 2)
		{
			cout << 2;
		}
		else if (a[m] == 1)
		{
			int s = 0;
			for (int i = 1;i <= m;i++)
			{
				if (a[i] == 1 or a[i] == 3)
				{
					s++;
				}
			}
			if (s >= m)
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		sort(a + 1,a + 1 + n);
		reverse(a + 1,a + 1 + n);
		cout << a[m];
	}
	return 0;
}
