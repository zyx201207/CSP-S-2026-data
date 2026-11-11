#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int z[500010],t=0;
int ans[500010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ti=1;
	for(int k=1;k<=n;k++)
	{
		t=0;
		for(int i=1;i<=n;i++)
		{
			z[i]=0;
		}
		for(int i=k;i<=n;i++)
		{
			int tx=t;
			while(z[tx]>=a[i])
			{
				if(z[tx]==a[i])
				{
					t=tx-1;
				}
				tx--;
			}
			z[++t]=a[i];
			if(z[t]==z[t-1])
			{
				t--;
			}
		}
		cout<<endl;
		for(int i=1;i<=t;i++)
		{
			cout<<z[i]<<" ";
			ans[z[i]]++;
		}
	}
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}



