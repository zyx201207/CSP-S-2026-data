#include<bits/stdc++.h>
using namespace std;
int a[500100];
int ans[300100];
int b[500100];
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
		int tap=1;
		for(int j=i;j<=n;j++)
		{
			int x=0;
			for(int k=1;k<tap;k++)
			{
				if(b[k]==a[j])
				{
					x=1;
					tap=k+1;
					break;
				}
			}
			if(x==0)
			{
				b[tap]=a[j];
				tap++;
			}
		}
		for(int j=1;j<tap;j++)
		{
			ans[b[j]]++;
		}
		for(int j=1;j<=n;j++)
		{
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
