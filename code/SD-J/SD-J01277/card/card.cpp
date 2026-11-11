#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005]={0},sum[300005];
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
		int j=i,j1=1;
		bool aa=0;
		while(j<=n)
		{
			for(int k=1;k<=j1;k++)
			{
				if(c[k]==a[j])
				{
					j1=k;
					aa=1;
					break;
				} 
			}
			if(!aa)
			{	
				c[j1]=a[j];
			}
			j1++;
			j++;
			aa=0;
		}
		for(int k=1;k<j1;k++)
		{
			sum[c[k]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;	
} 
