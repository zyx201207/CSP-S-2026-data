#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 5e5 + 7;
int n,m,a[maxn],b[maxn],ans=1;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++) b[i] = b[i-1] + a[i];
	for(int i = 2;i<=n;i++)
	{
		int l = 1,r = i;
		while(l<r)
		{
			int mid = (l + r) >> 1;
			int c = a[i]*(i-mid+1) - (b[i] - b[mid-1]);
			if(c>m)
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		ans = max(ans,i-r+1);
	}
	printf("%lld",ans);
	return 0;
}
