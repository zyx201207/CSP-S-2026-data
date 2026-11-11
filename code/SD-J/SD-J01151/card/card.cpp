#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],tmp,b[200010],x=1,c[200010],d[200010];
bool ss(int z)
{
	for(int i=1;i<=x;i++)
	{
		d[i]=b[i];
	}
	sort(d+1,d+x+1);
	int l=1,r=x;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(d[mid]==z)
		{
			tmp=mid;
			return 1;
		}
		else if(d[mid]>z)
		{
			l=mid+1;
		}
		else r=mid-1;
	}
	return 0;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(ss(a[j]))
			{
				for(int k=x;k>=tmp;k--)
				{
					b[k]=0;
				}
				x=tmp;
			}
			else b[x++]=a[j];
		}
		for(int j=1;j<=x;j++)
		{
			c[b[j]]++;
			b[j]=0;
		}
		x=1;
		tmp=0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<' ';
	}
	return 0;
}
