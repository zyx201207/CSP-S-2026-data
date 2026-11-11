#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sum[500005];
bool check(int len)
{
	for(int i=len;i<=n;i++)
	{
		if(a[i]*len-(sum[i]-sum[i-len])<=m)
			return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	int l=0,r=n+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid;
	}
	cout<<l<<endl;
}