#include<bits/stdc++.h>
using namespace std;
int a[500005],flag[300005],ans[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,f=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1]) f=1;
	}
	if(f==0)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]>a[i-1])
			{
				cout<<i-1<<" "; 
			} 
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(flag[a[j]]!=0)
			{
				for(int k=flag[a[j]];k<j;k++)
				{
					flag[a[k]]=0;
				}
			}
			flag[a[j]]=j;
		}
		for(int j=1;j<=m;j++)
		{
			if(flag[j]!=0)
			{
				ans[j]++;
			}
		} 
		memset(flag,0,sizeof(flag));
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
