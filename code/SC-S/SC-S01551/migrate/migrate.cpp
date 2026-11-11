#include <bits/stdc++.h>
using namespace std;
int a[5005];
int able[5005][5005];
int dfs(int start,int end)
{
	int as=0;
	if(start==end)
	{
		return 1;
	}
	for(int i=start+1;i<=end;i++)
	{
		if(able[start][i]==1)
		{
			as+=dfs(i,end);
		}
	}
	return as;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i = 1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d)
				{
					able[i][j]=1;
				}
			}
		}
		for(int i = 1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(dfs(i,j)==2)
				{
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}