#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long ans=-1;	
int n,m;
void d(int k,int w,long long s)
{
	if(k==0)
	{
		ans=max(s,ans);
		return;
	}
	for(int i=w+1;i<=m-k;i++)
	{
		s&=a[i];
		d(k-1,i,s);
	}
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
	sort(a+1,a+n+1);
	if(m==n)
	{
		ans=a[1];
		for(int i=2;i<=n;i++)
		{
			ans&=a[i];
		}
	}
	else if(m==1)
	{
		ans=a[n];
	}
	else if(m==2)
	{
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				long long x=a[i];
				x&=a[j];
				ans=max(ans,x);
			}
		}
	}
	else if(m==3)
	{
		for(int i=1;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				for(int h=j+1;h<=n;h++)
				{
					long long x=a[i];
					x&=a[j];
					x&=a[h];
					ans=max(ans,x);
				}
			}
		}
	}
	else
	{
		d(m,0,1);
		
	}
	cout <<ans;
	return 0;
}
