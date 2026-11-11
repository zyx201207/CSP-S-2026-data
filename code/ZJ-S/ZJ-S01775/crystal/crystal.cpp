#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],l,r,d[500010],maxx;
bool check()
{
	int c=a[2]-a[1];
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i-1]+c)return 0;
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(check())
	{
		long long sum=0,c=a[2]-a[1],k=c,l=0;
		while(sum<a[n])
		{
			sum+=k;k+=c;l++;
		}
		if(sum>a[n])cout<<l-1;
		else cout<<l;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			int k=a[i]-a[j-1];
			if(k<=m&&i-j+1>maxx)
			{
				maxx=i-j+1;
			}
		}
	}
	cout<<maxx;
	return 0;
}