#include<bits/stdc++.h>

using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[200005],ans=1,b[300005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(a[j]==0)
			{
				ans++;
				continue;
			}
			if(a[j]==a[j-ans])
			{
				a[j-ans]=0;
			}
			ans=1;
		}
		for(int j=i;j<=n;j++)
		{
			if(a[j]!=0)
			{
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
