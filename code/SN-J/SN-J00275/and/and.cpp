#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],ans[500100],num,ggg;
struct node
{
	long long a,id;
}but[500100];
bool cmp(node a,node b)
{
	return a.a<b.a;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		long long g=a[i],ret=0;
		while(g>0)
		{
			if(g%2==1)
			{	
				ans[ret]+=pow(2,ret);
				ret++;
			}
			g/=2;
		}
	} 
	for(int i=1;i<=n;i++)
	{
		long long g=a[i],ret=0;
		while(g>0)
		{
			if(g%2==1)
			{	
				but[i].a+=ans[ret];
				but[i].id=i;
				ret++;
			}
			g/=2;
		}
	}
	sort(but+1,but+1+n,cmp);
	num=a[but[n].id],ggg=a[but[n-1].id];
	for(int i=n-1;i>=n-m+1;i--)
	{
		num=num&a[but[i].id];
	}
	for(int i=n-2;i>=n-m;i--)
	{
		ggg=ggg&a[but[i].id];
	}
	cout<<max(num,ggg);
	return 0;
}

