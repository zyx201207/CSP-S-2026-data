#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=5e5+114;
int n,m,a[mxn],sum[mxn];
#define Q(l,r) (sum[r]-sum[l-1])
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m; for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int ans=1;
	for (int i=1;i<=n;i++)
	{
		int des=a[i];
		int L=1,R=i,mid;
		while (L<=R)
		{
			mid=(L+R)/2;
			if (des*(i-mid+1)-Q(mid,i)<=m) R=mid-1,ans=max(i-mid+1,ans);
			else L=mid+1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
//14:42 过样例
//14:44 过大样例
//AC100pts