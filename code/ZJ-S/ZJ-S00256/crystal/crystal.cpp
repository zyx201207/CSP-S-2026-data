#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
int t[500005];
bool check(int x)
{
	int cnt=m+1;
	for(int i=x;i<=n;i++)
	{
		cnt=min(cnt,a[i]*x-(s[i]-s[i-x]));
	}
	return cnt<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]+a[i];
	}
	int l=1,r=n,mid,ans=1;
	while(l<=r)
	{
		mid=(l+r)/2;
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
