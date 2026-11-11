#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e3+5,M=3e3+5;
int a[N],cntt[M],n,m;
pair<int,int> cnt[M];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for (int i=1;i<=n;i++)
	{
		memset(cnt,0,sizeof cnt);
		for (int j=i;j<=n;j++)
		{
			cnt[a[j]].first++;
			if (cnt[j].first==2)
			{
				for (int t=cnt[a[j]].second;t<j;t++)
				{
					cnt[a[t]].first--;
				}
			}
			cnt[a[j]].second=j;
		}
		for (int j=1;j<=m;j++)
		{
			if (cnt[j].first==1)
			{
				cntt[j]++;
			}
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout<<cntt[i]<<" ";
	}
	
	return 0;
} 

