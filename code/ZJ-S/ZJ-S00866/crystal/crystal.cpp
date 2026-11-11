#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m;
ll a[500005],sum[500005];
bool check(int x)
{
	ll mn=3000000000000000000;
	for(int i=x;i<=n;i++)
		mn=min(mn,a[i]*x-sum[i]+sum[i-x]);
	if(mn<=m)
		return true;
	else
		return false;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=0,r=n,mx=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
			mx=max(mx,mid),l=mid+1;
		else
			r=mid-1;
	}
	cout<<mx;
}