#include<bits/stdc++.h>
using namespace std;
const int MX = 5e5;
const int NX = 3e5;
int a[MX + 10],cnt[NX + 10],ans[NX + 10];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,i,j,h,f = 0;
	cin >> n >> k;
	for(i = 1;i <= n;i++)
	{
		cin >> a[i];
		if(a[i] > a[i + 1] && i != n)
		{
			f = 1;
		}
		cnt[a[i]] = i;
	}
	if(f == 0)
	{
		for(i = 1;i <= k;i++)
		{
			cout << cnt[i] << ' ';
		}
	}
	else
	{
		memset(cnt,0,sizeof(cnt));
		for(i = 1;i <= n;i++)
		{
			for(h = i;h <= n;h++)
			{
				if(cnt[a[h]] == 1)
				{
					for(j = h - 1;j >= 1;j--)
					{
						if(a[h] == a[j])
						{
							break;
						}
						cnt[a[j]] = 0;
					}
				}
				else
				{
					cnt[a[h]] = 1;
				}
			}
			for(h = 1;h <= k;h++)
			{
				ans[h] += cnt[h];
				cnt[h] = 0;
			}
		}
		for(i = 1;i <= k;i++)
		{
			cout << ans[i] << ' ';
		}
	}
	return 0;
}
