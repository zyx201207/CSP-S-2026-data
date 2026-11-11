#include <bits/stdc++.h>
using namespace std;

long long a[5000005],vis[5000005],ans[5000005],q[5000005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= n;i++)
	{
		memset(q,0,sizeof(q));
		memset(vis,0,sizeof(vis));
		for(int j = i;j <= n;j++)
		{
			if(vis[a[j]] == 0)
			{
				q[j] = a[j];
				vis[a[j]] = 1;
			}
			else
			{
				for(int k = j - 1;k >= 1;k--)
				{
					if(q[k] != a[j])
					{
						vis[q[k]] = 0;
						q[k] = 0;
					}
					else
					{
						q[k] = 0;
						break;
					}
				}
				q[j] = a[j];
			}
		}
		for(int j = 1;j <= m;j++)
		{
			ans[j] += vis[j];
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
} 
