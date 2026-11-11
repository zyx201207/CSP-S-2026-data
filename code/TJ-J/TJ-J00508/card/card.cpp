#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[500010],ans[500010];
string s;
int a[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		int sum = 0;
		sizeof(cnt,0);
		for(int j = i;j <= n;j++)
		{
			if(cnt[a[j]] == 0)
			{
				cnt[a[j]] = 1;
				sum++;
			}
			else
			{
				for(int k = sum;k > j;k--)
				{
					cnt[a[k]] = 0;
					sum--;
				}
			}
		}
		for(int x = 1;x <= m;x++)
		{ 
			if(cnt[x] != 0)
			{
				ans[x]++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
 } 
