#include<bits/stdc++.h>
using namespace std;
int a[500005],b[100005],m1[500005];
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
		for(int j=i;j<=n;j++)
		{
			 	for(int p=i;p<=j;p++)
			 	{
			 		if(b[p]==a[j])
			 		{
			 			for(int u=p;u<=j;u++)
			 			{
			 				b[u]=0;
						 }
					 }
					 
				 }
			b[j]=a[j];	 
		}
		for(int j=1;j<=n;j++)
		{
			m1[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<m1[i]<<" ";
	}
	return 0;
}