#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000050],dp[2000050],xx[2000050],sum,minn;
int dfs(int ff,int bushu,int z)
{
	if(ff==z)
	{
	    xx[bushu]++;
	    minn=min(bushu,minn);
		return 0;
	}
	for(int i=ff+1;i<=z;i++)
	{
		if(a[i]-a[ff]<=d)
		{
			dfs(a[i],bushu+1,z);
		}
	}
	return 0;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>d;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			for(int l=1;l<j;l++)
			{
				minn=0x7f7f7f7f;
				dfs(l,0,j);
				if(xx[minn]==2)
				{
					//cout<<l<<' '<<j<<endl;
					sum++;
				}
				for(int f=0;f<=n;f++)
				{
					xx[f]=0;
				}
			}
		}
	    cout<<sum<<endl;
	    sum=0;
	}
	return 0;
}
