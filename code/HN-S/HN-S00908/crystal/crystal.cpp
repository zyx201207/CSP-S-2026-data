#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],maxn; 
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int flag = 0;
	int x=a[1]-a[0];
	for(int i = 0;i < n-1;i++)
	{
		if(a[i+1]-a[i] != x)
		{
			flag = 1;
		}
	}
	if(flag==0)
	{
		if(m > n*2)
		{
			cout << n;
			return 0;
		}
		else
		{
			while(n)
			{
				if(n * 2 < m)
				{
					cout << n+1;
					return 0;
				}
				n--;
			}
		}
	}
	int o = ceil(n/2),sum=1;
	for(int i = 0;i < n;i++)
	{
		if(a[i] >= 0)
		{
			if(m - (a[o] - a[i]) >= 0)
			{
				sum++;
				m -= (a[o] - a[i]);
			}
		}
		else
		{
			if(m - (a[o] + a[i]) > 0)
			{
				sum++;
				m -= (a[o] + a[i]);
			}
		}
	}
	cout << sum;
	return 0;
}
