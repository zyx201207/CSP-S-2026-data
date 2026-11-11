#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],sum[500005],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(a[mid]*(mid-i+1)-sum[mid]+sum[i-1]>m) r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,l-i);
	}
	cout<<ans<<"\n";
	return 0;
}