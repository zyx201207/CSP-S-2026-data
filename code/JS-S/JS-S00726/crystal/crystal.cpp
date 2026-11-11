#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i+1;
		while(l+1<r)
		{
			int mid=(l+r)/2;
			long long ned=(i-mid)*a[i]-(sum[i-1]-sum[mid-1]);
			if(ned<=m) r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}
