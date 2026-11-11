#include<bits/stdc++.h>
using namespace std;
long long n, m, a[500010], b[300010], c[500010], d;
bool f;
bool cheek(int x, int y)
{
	for (int i = 1;i < y;i ++)
	{
		if (y == a[i])
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++)
	{
		cin >> a[i];
		c[i] = a[i];
	}
	for (int l = 1;l <= n;l ++)
	{
		for (int y = 1;y <= n;y ++)
		{
			a[y] = c[y];
		}
		for (int i = l;i <= n;i ++)
		{
			f = 0;
			for (int j = l;j < i;j ++)
			{
				if (a[j] = -1)
				{
					continue;
				}
				if (a[i] == a[j])
				{
					f = 1;
				}
				if(f)
				{
					a[j] = -1;
				}
				cout << a[j] << ' ';
			}
		}
		for (int t = l;t <= n;t ++)
		{
			if (a[t] != -1)
			{
				d = a[t];
				b[d] ++;
				cout << b[d] << ' ';
			}
		}
		cout << endl;
	}
	for (int i = 1;i <= m;i ++)
	{
		cout << b[i] << ' ';
	}
	return 0;
}

