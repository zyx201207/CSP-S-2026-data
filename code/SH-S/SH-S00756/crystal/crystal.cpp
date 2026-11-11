#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5;
int n,m,a[M],pre[M];
bool check(int x)
{
	bool res=false;
	for(int i=x;i<=n;i++)
		if(x*a[i]-pre[i]+pre[i-x]<=m)
			res=true;
	return res;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
