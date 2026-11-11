#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[700006],s[700006];
bool checkqw(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		if(a[i+x-1]*x-(s[i+x-1]-s[i-1])<=m)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r+1)/2;
		if(checkqw(mid))
		{
			l=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}