#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r,ans,Max=1,a[500005],s[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++)
	{
		l=0,r=i-1,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if((mid*a[i]-(s[i-1]-s[i-mid-1]))<=m) ans=mid,l=mid+1;
			else r=mid-1;
		}
		Max=max(Max,ans+1);
	}
	cout<<Max;
	return 0;
}
