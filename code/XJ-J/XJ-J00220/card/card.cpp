# include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x=0,y=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-x;j++)
		{
			b[i]=a[i];
		}
		x++;
		x=1;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		x=0;
		for(int j=1;j<=n-x;j++)
		{
			if(b[i]==b[i+1])
			{
				y=b[i];
			}
			x++;
			x=1;
		}
	}
	for(int i=n-x;i>=1;i--)
	{
		if(y==b[i])
		{
			for(int j=y;j<=n-x;j++)
			{
				c[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
}
