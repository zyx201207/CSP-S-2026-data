#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int b[500005];
int c[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 0)
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i] < 0)
			{
				c[abs(a[i])]++;
			}
			else
			{
				b[a[i]]++;
			}
		}
		sort(b,b+n);
		sort(c,c+n);
		int z = n,x,y;
		while(z--)
		{
			if(b[z] != 0)
			{
				x = b[z];
				break;
			}
		}
		while(n--)
		{
			if(c[n] != 0)
			{
				y = b[n];
				break;
			}
		}
		cout << max(x,y);
		return 0;
	}
	else
	{
		int t = a[2]-a[1];
		int l = 1;
		while(m > 0 && l <= n)
		{
			m -= l*t;
			if(m < 0)
			{
				break;
			}
			sum++;
			l++;
		}
		cout << sum;
		return 0;
	}
	return 0;
}
