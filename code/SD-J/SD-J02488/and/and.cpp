#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int n,m;
long long maxx,jg,cnt;
long long a[200005];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n)
	{
		maxx=a[1];
		for(int i=2;i<=n;i++)
		{
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}
	
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				jg=(a[i]&a[j]);
				maxx=max(maxx,jg);
			}
		}
		cout<<maxx;
	}
	else if(m==n-1)
	{
		jg=a[1];
		for(int i=2;i<=n;i++)
		{
			jg=jg&a[i]; 
		}
		for(int i=1;i<=n;i++)
		{
			cnt=jg^a[i];
			maxx=max(maxx,cnt);
		}
		cout<<maxx;
	}
	else
	{
		sort(a+1,a+n+1,cmp);
		jg=a[1];
		for(int i=2;i<=m;i++)
		{
			jg=a[i]&jg;
		}
		cout<<jg;
	}
	
	return 0;
 } 
