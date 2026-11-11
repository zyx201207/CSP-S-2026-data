#include<bits/stdc++.h>
#define int long long
#define N 500010
using namespace std;
int n,ans,m;
int a[N],pre[N];
bool check(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(((a[i]*x-(pre[i]-pre[i-x])))<=m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i];
	}
	int l=1,r=n,mid=(l+r+1)/2;
	while(l<=r)
	{
		mid=(l+r+1)/2;
		if(check(mid))
		{
			l=mid+1;
			ans=mid;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
