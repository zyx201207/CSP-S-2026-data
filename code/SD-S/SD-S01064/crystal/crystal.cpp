#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int n,m;
int a[N];
int s[N];
bool check(int k)
{
	for(int i=k;i<=n;i++)
	{
		if((a[i]*k-(s[i]-s[i-k]))<=m)return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	int ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
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

