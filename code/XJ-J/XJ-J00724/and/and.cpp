#include<bits/stdc++.h>
using namespace std;
const int N=1e7+12;
long long n,m,cnt,ans,a[N],anss[N],ansss;
int main()
{
	freopen("and,in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i<2)
		{
			ansss=a[1];
		}
		if(i>=2)
		{
			ansss=ansss&a[i];
		}
	}
	if(m==1)
	{
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	if(m==n)
	{
		cout<<ansss;
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				anss[++cnt]=a[i]&a[j];
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			ans=max(ans,anss[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1)
			{
				anss[++cnt]=a[2];
			}
			else
			{
				anss[++cnt]=a[1];
			}
			for(int j=1;j<=n;j++)
			{
				if(i==j)
				{
					continue;
				}
				anss[cnt]=anss[cnt]&a[j];
			} 
		}
		for(int i=1;i<=cnt;i++)
		{
			ans=max(ans,anss[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
