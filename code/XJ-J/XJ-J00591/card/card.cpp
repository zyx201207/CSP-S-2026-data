#include<bits/stdc++.h>
using namespace std;
int a[500005],z[300005];
int mp[500005];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(mp,0,sizeof(mp));
		for(int j=i;j<=n;j++)
		{
			if(mp[a[j]]==0)
			{
				mp[a[j]]++;
			}
			else
			{
				for(int it=a[j];it<=n;it++)
				{
					mp[it]=0;
				}
				mp[a[j]]++;
			}
		}
		for(int it=1;it<=n;it++)
		{
			z[it]+=mp[it];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<z[i]<<" ";
	}
	return 0;
}