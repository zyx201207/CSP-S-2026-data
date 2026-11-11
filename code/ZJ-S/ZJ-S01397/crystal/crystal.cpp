#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,mid,m,a[600005],s[600005],sum[600005],ans;
bool ch(long long x)
{
	long long p=m+1;
	for(long long i=1;i<=n-x+1;i++)
	{
	   	long long j=i+x-1;
	    p=min(p,(sum[j]-sum[i-1]));
    }
	return p<=m;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++) s[i]=s[i-1]+a[i]-a[i-1];
	for(long long i=1;i<=n;i++) sum[i]=sum[i-1]+s[i];
	r=n;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(ch(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}