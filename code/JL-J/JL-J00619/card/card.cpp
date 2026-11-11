#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],d[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int f=1;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			c[j]=0;
			d[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			c[j-i+1]=b[j];
		}
		f=1;
		for(int j=1;j<=n-i+1;j++)
		{
			int p=0;
			for(int k=1;k<f;k++)
			{
				if(d[k]==c[j])
				{
					for(int o=k+1;o<f;o++)
					{
						d[o]=0;
						p=1;
					}
					f=k+1;
				}
			}
			if(p==0)
			{
				d[f]=c[j];
				f++;
			}
			
		}
		for(int j=1;j<f;j++)
		{
			a[d[j]]++;
		}
	}
	for(int j=1;j<=m;j++)
	{
		cout<<a[j]<<" ";
	}
}
