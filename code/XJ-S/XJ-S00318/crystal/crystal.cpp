#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[1999999];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,g=0,maxx=0,mmx=0,jilu=0,ans=0,anquan=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		g++;
	}
	sort(a,a+n+1);
	for (int i=1;i<=g;i++)
	{
		b[a[i]]++;
	}
	for (int i=1;i<=1999999;i++)
	{
		if (b[i]>maxx)
		{
			maxx=b[i];
			jilu=i;
		}
	}
	ans+=maxx;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			if (a[j]==jilu-i)
			{
				m-=i;
				ans++;
			}
			if (m<=0)
			{
				break;
			}
		}
		if (m<=0)
		{
			break;
		}
	}
	cout<<ans;
	return 0;
} 
