#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m,a[maxn],q[maxn],l=1,r,k,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	q[++r]=a[1];
	for(int i=2;i<=n;i++)
	{
		k+=(r-l+1)*(a[i]-q[r]);
		while(k>m)k-=(a[i]-q[l++]);
		q[++r]=a[i];
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
