#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,a[700005],b[500005],d[700005];
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
		memset(d,0,sizeof(d));
		int sum=1;
		for(int j=i;j<=n;j++)
		{
			int op=0;
			for(int x=1;x<=sum;x++)
			{
				if(op!=0) d[x]=0;
				if(d[x]==a[j])
				{
					op=x;
					sum=op-1;
					d[x]=0;
				}
			}
			d[sum]=a[j];
			sum++;
		}
		for(int j=0;j<sum;j++)
		{
			b[d[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
