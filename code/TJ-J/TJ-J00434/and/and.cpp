#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[200005],num;
int sq(int q)
{
	int an=1;
	for (int i=1;i<=q;i++)
	{
		an*=2;
	}
	return an;
}
int And(int x,int y)
{
	int z=0,u=0;
	while(true)
	{
		if ((x%2==1)&&(y%2==1))
		{
			z+=sq(u);
		}
		x/=2;
		y/=2;
		if ((x==0)||(y==0))
		{
			return z;
		}
		u+=1;
	}	
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x,y;
	for (int i=1;i<=m;i++)
	{ 
		x=-1;
		y=0;
		for(int j=1;j<=n;j++)
		{
			if (a[j]>=x)
			{
				x=a[j];
				y=j;
			}
		}
		ans[i]=x;
		a[y]=-1;
	}
	if (m==1)
	{
		cout<<ans[1];
	}
	for (int i=2;i<=m;i++)
	{
		if (i==2)
		{
			num=And(ans[i],ans[i-1]);
		}
		else
		{
			num=And(ans[i],num);
		}
	}
	cout<<num;
	return 0;
}
