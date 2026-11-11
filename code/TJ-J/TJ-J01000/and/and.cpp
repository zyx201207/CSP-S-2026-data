#include <bits/stdc++.h> 
using namespace std;
int main()
{
	
	perfor ("and.in","r",stdin);
	perfor ("and.out","w",stdout);
	int n,m,a[10005];
	cin >> n >> m ;
	if (m == 2) 
	{
		int x = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int j = 1;j <= n;j++)
			{
				if (i != j)
				{
					if (a[i] & a[j] >= x)
					{
						x = a[i] & a[j];
					}
				}
			}
		}
		cout << x;
	}
	else if (m == 3) 
	{
		int x = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int k = 1;k <= n;k++)
			{
				for (int j = 1;j <= n;j++)
				{
					if (i != j && i != k && j != k)
					{
						if (a[i] & a[j] & a[k] >= x)
						{
							x = a[i] & a[j] & a[k];
						}
					}
				}
			}
		}
		cout << x;
	}
	else if (m == 4) 
	{
		int x = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int k = 1;k <= n;k++)
			{
				for (int j = 1;j <= n;j++)
				{
					for (int f = 1;f <= n;f++)
					{
						if (i != j && i != k && j != k && i != f && k != f && j != f)
						{
							if (a[i] & a[j] & a[k] & a[f] >= x)
							{
									x = a[i] & a[j] & a[k];
							}
						}
					}
				}
			}
		}
		cout << x;
	}
	else if (m == 5) 
	{
		int x = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		for (int i = 1;i <= n;i++)
		{
			for (int k = 1;k <= n;k++)
			{
				for (int j = 1;j <= n;j++)
				{
					for (int f = 1;f <= n;f++)
					{
						for (int t = 1;t <= n;t++)
						{
							if (i != j && i != k && j != k && i != f && k != f && j != f && t != j && i != t && t != k && t != f)
							{
								if (a[i] & a[j] & a[k] & a[f] & a[t] >= x)
								{
									x = a[i] & a[j] & a[k];
								}
							}
						}
					}
				}
			}
		}
		cout << x;
	}
	else
	{
		cout << 6;
	}
	return 0;
}
