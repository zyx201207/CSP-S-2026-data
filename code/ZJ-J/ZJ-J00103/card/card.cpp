#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int b[500010];
int ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int ccff=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			ccff=0;
		}
	}
	if(ccff==1)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if(j==i||a[j]!=a[j-1])
				{
					ans[a[j]]++;
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout<<ans[i]<<" ";
		}
   		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int l=0;
		for(int j=i;j<=n;j++)
		{
			int f=0;
			for(int q=1;q<=l;q++)
			{
				if(b[q]==a[j])
				{
					l=q;
					f=1;
					break;
				}
			}
			if(f==0)
			{
				b[++l]=a[j];
			}
		}
		for(int j=1;j<=l;j++)
		{
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}

