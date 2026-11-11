#include<bits/stdc++.h>
using namespace std;
int a[500005],m,n,b[300005],d[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int t=0;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int e=1;e<=t;e++)
			{
				if(d[e]==a[j])
				{
					f=1;
				}
				if(f==1)
				{
					d[e]=0;
					t--;
				}
			}
			f=0;
			for(int e=1;e<=m;e++)
			{
				if(d[e]==0)
				{
					d[e]=a[j];
					break;
				}
			}
			t++;
		 } 
		for(int j=1;j<t;j++)
		{
			if(d[j]!=0)
			{
				b[d[j]]++;
				d[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	return 0;
}
