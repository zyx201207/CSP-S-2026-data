#include<bits/stdc++.h>
using namespace std;
int n,m,a[550000],c[350000];
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
		int b[550000]={0},t=0;
		for(int j=i;j<=n;j++)
		{
			for(int h=i;h<j;h++)
			{
				if(b[h]==b[j]) t=1;
				if(t==1) b[h]=0;
			}
			for(int h=i;h<j;h++)
			{
				if(b[h]==0) 
				{
				    b[h]=a[j];
				    break;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			c[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i];
	}
	return 0;
}
