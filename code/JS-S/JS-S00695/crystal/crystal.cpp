#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500020],sum[500020];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,mid,res=1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		bool fl=false;
		for(int l=1,r=mid;r<=n;l++,r++) if(a[r]*(r-l+1)-sum[r]+sum[l-1]<=m) fl=true;
		if(fl) res=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<res;
}
