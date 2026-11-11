#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn = 0;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		for(int i = 1;i <= n;i++)
		{
			maxn == max(maxn,a[i]);
		}
		cout << maxn;
		return 0;
	}
	else if(m == n)
	{
		for(int i = 1;i <= n;i++)
		{
			maxn |= a[i];
		}
		cout << maxn;
		return 0;
	} 
	else if(m == 2)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = i+1;j <= n;j++)
			{
				maxn = max(maxn,a[i]|a[j]);
			}
		}
		cout << maxn;
	}
	return 0;
}
