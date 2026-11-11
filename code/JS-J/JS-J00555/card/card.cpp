#include<bits/stdc++.h>
using namespace std;
long long n,m,num,a[500010],b[300010],c[300010],v[300010],t,u;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<u)
			t=1;
		u=a[i];
	}
	if(t==0)
	{
		for(int i=1;i<=n;i++)
		{
			u=1;
			for(int j=i+1;j<=n+1;j++)
			{
				if(a[j]==a[j-1])
					u++;
				else
				{
					if(u%2==1)
						c[a[j-1]]++;
					u=1;
				}
			}
		}
	}
	else
	for(int i=1;i<=n;i++)
	{
		num=0;
		for(int j=i;j<=n;j++)
		{	
			if(v[a[j]]==0)
			{
				num++;
				b[num]=a[j];
				v[a[j]]=num;
			}
			else
			{
				for(int k=v[a[j]]+1;k<=num;k++)
					v[b[k]]=0;
				num=v[a[j]];
			}
		}
		for(int j=1;j<=num;j++)
		{
			c[b[j]]++;
			v[b[j]]=0;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}