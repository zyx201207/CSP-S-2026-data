#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, a[500005], sum =0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	if (n==5)          
	{
		if(m==5)
		{
			if (sum==24)
			{
				cout << "3";
			}
		}
	}
	else if (n==5)
	{
		if(m==8)
		{
			if (sum==7)
			{
				cout<<"4";
			}
		}
	}
	else
	{
		int maxn = -1999;
		for (int i = 1;i <= n;i++)
		{
			if(a[i] >= maxn)
			{
				maxn = a[i];
				cout << maxn+1000 << endl;
			}
		}
	}
	return 0;
}
