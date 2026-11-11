#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
int ans[500005];
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int last[100];
		memset(last,0,sizeof(last));
		map<int,int>mp;
		for(int j=i;j<=n;j++)
		{
			mp[a[j]]++;
			if(mp[a[j]]>1)
			{
				for(int k=last[a[j]];k<j;k++)
				{
					mp[a[k]]=0;
				}
				last[a[j]]=j;
			}
			mp[a[j]]++;
			
		}
		for(int j=1;j<=m;j++)
		{
			if(mp[j]!=0)
			{
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

