#include<iostream>
using namespace std;
int a[500005],b[500005],c[500005],d[500005],e[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]]++;
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(c[a[j]]>1)
			{
				break;
			}
			b[a[j]]=j;
		}
		if(j<=n)
		{
			for(k=j;k<=n;k++)
			{
				d[a[k]]=1;
				if(d[a[k]]==1)
				e[a[k]]++;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		cout<<e[i];
	}
	return 0;
}