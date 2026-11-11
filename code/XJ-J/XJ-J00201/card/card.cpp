#include <bits/stdc++.h> 
using namespace std;
long long n,a[50005],b[30005],e[50005],m;
long long c(int f,int d)
{
	if(d>n)
	{
		for(int i=f;i<=n;i++)
		{
			b[e[i]]++;
		}
		return 0;
	}
	for(int j=f;j<d;j++)
	{
		if(e[d]==e[j])
		{
			for(int t=j;t<d;t++)
			{				
				e[t]=0;	
			}
			break;
		}
	}
	c(f,d+1);
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		e[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		c(i,2);
		for(int j=i;j<=n;j++)
		{
			e[j]=a[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
}
