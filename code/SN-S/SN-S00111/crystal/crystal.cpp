#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010];
int as,ass,dy=1,fy=1;
long long v=1e20;
int cmp(int x,int y)
{
	return x<y;
}
int main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(m==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int z=a[i]; 
		for(int o=1;o<=n-1;o++)
		{
			int p=abs(z-a[o+1]);
			z+=p;	
		}
		ass++;
		if(z<v)
		{
			v=z;
			as=ass;
		}
		z=0;
	}
	int h=m;
	for(int i=1;i<=m/2;i++)
	{
		int xx=abs(a[as]-a[as-i]);
		int yy=abs(a[as]-a[as+i]);
		if(xx>yy)
		{
			h-=yy;
			if(h>=m)
			{
				cout<<fy;
				return 0;
			}	
			fy++;
			h-=xx;
			if(h>=m)
			{
				cout<<fy;
				return 0;
			}
			fy++;
		}
		else
		{
			h-=xx;
			if(h>=m)
			{
				cout<<fy;
				return 0;
			}
			fy++;
			h-=yy;
			if(h>=m)
			{
				cout<<fy;
				return 0;
			}
			fy++;	
		}
		}
	
	cout<<fy;


	return 0;
 } 
