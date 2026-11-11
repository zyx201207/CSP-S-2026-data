#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(m == 1)
	{
		int maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			max(maxn,a[i]);
		}
		cout << maxn;
	} 
	else if(m == 2)
	{
		int maxn = -1;
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++)
			if(a[i] == a[j])
			{
				continue;
			}
			else
			{
				int x = a[i] & a[j];
				max(maxn,x); 
			}
		}
		cout << maxn; 
	}
	return 0;
} 
