#include <bits/stdc++.h>
using namespace std;
int a[300005],vis[500005],cnt[500005];
int main()
{
	long long n,m;
	int x = 0;
	while (n--)
	{
		for (int i = x+1;i <= m;i++)
		{
			cin >> a[i];
			if (vis[a[i]] == 0)
			{
				vis[a[i]] = 1;
			}
			else
			{
				
			}
		}
	} 
	return 0;
}
