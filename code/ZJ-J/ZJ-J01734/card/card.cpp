#include<bits/stdc++.h>
using namespace std;
int n,m;
int mn[300100];
int a[500100];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		getchar();
	}
	int c[500100];
	for(int i=1;i<=n;++i)
	{
		map<int,int>mp;
		int cnt=0;
		for(int j=i;j<=n;++j)
		{
			if(mp[a[j]])
			{
				for(int k=mp[a[j]]+1;k<=cnt;++k)mp[c[k]]=0;
				cnt=mp[a[j]];
			}
			else
			{
				++cnt;
				mp[a[j]]=cnt;
				c[cnt]=a[j];
			}
		}
		for(int j=1;j<=m;++j)
		{
			if(mp[j])
			{
				++mn[j];
			}
		}
	}
	for(int i=1;i<=m;++i)printf("%lld ",mn[i]);
	return 0;
}
/*
4 3
1 2 1 3
3 1 4
10 3
3 1 2 1 3 2 3 1 2 1
10 3 3
*/
