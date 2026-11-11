#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],sum[N];
int n,m;
bool check(int mid)
{
	int val;
	for(int i=1;i<=n-mid+1;i++)
	{
		val=a[i+mid-1]*mid-(sum[i+mid-1]-sum[i-1]);
		if(val<=m) return true;
	}
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=0,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
