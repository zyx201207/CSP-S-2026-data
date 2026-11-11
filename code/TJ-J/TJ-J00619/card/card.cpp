#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],cnt[300005],flag[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
	    memset(flag,false,sizeof(flag));
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[j]==a[k]&&flag[a[j]]==false&&flag[a[k]]==false)
				{
					for(int t=j;t<k;t++)
					{
						flag[a[t]]=true;
					}
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]]==false)
			{
				cnt[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
