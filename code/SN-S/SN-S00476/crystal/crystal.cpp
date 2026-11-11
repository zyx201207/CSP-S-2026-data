#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,a[500005],sum[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];
	int ans = 0,l = 1;
	for (int i = 1;i <= n;i++)
	{
		while (a[i]*(i-l+1)-sum[i]+sum[l-1] > m) l++;
		ans = max(ans,i-l+1);
	}
	cout << ans;
	return 0;
}
