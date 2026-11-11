#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],mn[505],cd,flag,ans[505],tj[300300],zuiz[300300];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		zuiz[i]=INT_MAX;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n<=500)
	{
		for(int i=1;i<=n;i++)
		{
			cd=0;
			for(int j=i;j<=n;j++)
			{
				flag=0;
				for(int k=cd;k>=1;k--)
				{
					if(mn[k]==a[j])
					{
						cd=k;
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					cd++;
					mn[cd]=a[j];
				}
			}
			for(int j=1;j<=cd;j++)
			{
				ans[mn[j]]++;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			tj[a[i]]++;
			zuiz[a[i]]=min(zuiz[a[i]],i);
		}
		for(int i=1;i<=m;i++)
		{
			if(zuiz[i]==INT_MAX)
			{
				cout<<"0 ";
				continue;
			}
			cout<<zuiz[i]+(tj[i]-1)/2<<" ";
		}
	}
	return 0;
}
