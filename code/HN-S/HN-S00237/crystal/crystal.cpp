#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5+5;
int n,m,a[N],sum[N],ans;

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	ans = 1;
	for(int i = 1;i <= n;i++)
	{
		sum[i] = sum[i-1]+a[i];
		int l = 0,r = i+1;
		while(l+1 < r)
		{
			int mid = (l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1]) <= m) r = mid;
			else l = mid;
		}
		ans = max(ans,i-r+1);
	}
	cout << ans;
	return 0;
}
