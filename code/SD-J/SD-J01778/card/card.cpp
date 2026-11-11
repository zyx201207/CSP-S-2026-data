#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005];
bool c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","a",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if(!c[a[j]])
			{
				c[a[j]] = true;
			}
			else
			{
				for(int k = j-1;k >= 1;k--)
				{
					c[a[k]] = false;
				}
			}
		} 
		for(int j = i;j <= n;j++)
		{
			if(c[a[j]])
				cnt[a[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << cnt[i] <<" ";
	}
	return 0;
}
