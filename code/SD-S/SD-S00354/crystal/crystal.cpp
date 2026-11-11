#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10,M=1e1+10;
int n,m,a[N],c[N],s[N],l=1,r,ans;
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		int y=c[i]-(a[i]*(i-x)-s[i-x]);
		if(y<=m)
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
	r=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
		s[i]=s[i-1]+a[i];
	}
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

