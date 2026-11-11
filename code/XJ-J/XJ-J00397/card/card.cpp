#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,a[N],c[N],d[N],f[N],v[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(1)
	{
		int x=1,y=1;
		for(int i=1;i<=n;i++)
		{
			f[x]=a[i];
			c[a[i]]++;
			x++;
			if(c[a[i]]==2)
			{
				for(int j=m;j>=1;j--)
				{
					if(c[a[j]]!=0)
					{
						v[y]=a[j];
						y++;
					}
					c[a[j]]=0;
					f[j]=0;
				}
				x=1;
				f[x]=a[i];
				c[a[i]]++;
				x++;
			}
		}
		n=x-1;
		for(int i=2;i<=n;i++)
		{
			v[y]=f[i];
			y++;
		}
		{
			d[f[i]]++;
		}
		for(int i=1;i<=y-1;i++)
		{
			a[i]=v[i];
		}
		if(x==2)
		{
			for(int i=1;i<=m;i++)
			{
				cout<<d[i]<<" ";
			}
			return 0;
		}
	}
	return 0;
}