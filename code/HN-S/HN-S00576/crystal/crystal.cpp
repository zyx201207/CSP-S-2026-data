#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,a[N],sum[N],ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
		int l=0,r=i;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m)
				r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans<<endl;
	return 0;
}

