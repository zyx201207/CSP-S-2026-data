#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 3;
int a[N],b[N];
int read()
{
	int x = 0,fs = 1;
	char c = getchar();
	while(c < '0' || c > '9')
	{
		if(c == '-')
		{
			fs = -1;
		}
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * fs;
}

signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	n = read();
	m = read();
	a[1] = read();
	bool flag = 1;
	for(int i = 2;i <= n;i++)
	{
		a[i] = read();
		if(a[i] < a[i - 1])
		{
			flag = 0;
		} 
		a[i] = a[i - 1] & a[i];
	}
	if(flag == 1)
	{
		sort(a + 1,a + n + 1,greater<int>());
		for(int i = 2;i <= m;i++)
		{
			a[i] = a[i - 1] & a[i];
		}
		cout << a[m];
	}
	if(n == m)
	{
		for(int i = 2;i <= n;i++)
		{
			a[i] = a[i - 1] & a[i];
		}
		cout << a[n];
		return 0;
	}
	else if(m == 1)
	{
		int maxx = -1;
		for(int i = 1;i <= n;i++)
		{
			maxx = max(maxx,a[i]);
		}
		cout << maxx;
		return 0;
	}
	else if(m == 2)
	{
		int maxx = -1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				maxx = max(maxx,a[i] & a[j]);
			}
		}
		cout << maxx;
		return 0;
	}
	else if(m == n - 1)
	{
		int maxx = -1;
		for(int i = 1;i <= n - 1;i++)
		{
			int dq1,dq2;
			for(int j = 1;j <= i;j++)
			{
				if(j == 1)
				{
					dq1 = a[j];
				}
				else
				{
					dq1 = dq1 & a[j];
				}
			}
			for(int j = i + 2;j <= n;j++)
			{
				if(j == (i + 2))
				{
					dq2 = a[j];
				}
				else
				{
					dq2 = dq2 & a[j];
				}
			}
			maxx = max(maxx,dq1 & dq2);
		}
		int l = a[2];
		for(int i = 3;i <= n;i++)
		{
			l = l & a[i];
		}
		cout << max(maxx,l);
		return 0;
	}
	if(m == 3)
	{
		int maxx = -1;
		for(int i = 1;i <= n - 2;i++)
		{
			for(int j = i + 1;j <= n - 1;j++)
			{
				for(int k = j + 1;k <= n;k++)
				{
					if(i != j && j != k && k != i)
					{
						maxx = max(maxx,a[i] & a[j] & a[k]);
					}
				}
			}
		}
		cout << maxx;
		return 0;
	}
	else if(m == 4)
	{
		int maxx = -1;
		for(int i = 1;i <= n - 3;i++)
		{
			for(int j = i + 1;j <= n - 2;j++)
			{
				for(int k = j + 1;k <= n - 1;k++)
				{
					for(int d = k + 1;d <= n;d++)
					{
						if(i != j && j != k && k != i && i != d && j != d && k != d)
						{
							maxx = max(maxx,a[i] & a[j] & a[k] & a[d]);
						}
					}
				}
			}
		}
		cout << maxx;
		return 0;
	}
	else if(m == 5)
	{
		int maxx = -1;
		for(int i = 1;i <= n - 4;i++)
		{
			for(int j = i + 1;j <= n - 3;j++)
			{
				for(int k = j + 1;k <= n - 2;k++)
				{
					for(int d = k + 1;d <= n - 1;d++)
					{
						for(int f = d + 1;f <= n;f++)
						{
							if(i != j && j != k && k != i && i != d && j != d && k != d && i != f && j != f && k != f && d != f)
							{
								maxx = max(maxx,a[i] & a[j] & a[k] & a[d] & a[f]);
							}
						}
					}
				}
			}
		}
		cout << maxx;
		return 0;
	}
	
	return 0;
} 

