#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005];
map<int,int> mp;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			mp[j]=-1;
		}
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]!=-1)
			{
				for(int k=mp[a[j]];k<j;k++)
				{
					mp[a[k]]=-1;
				}
			}
			mp[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(mp[j]!=-1) ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
