#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],sum[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		int l=1,r=i,tmp=i;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(sum[i]-sum[mid-1]+m>=a[i]*(i-mid+1))tmp=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,i-tmp+1);
	}
	cout<<ans<<'\n';
	return 0;
}

