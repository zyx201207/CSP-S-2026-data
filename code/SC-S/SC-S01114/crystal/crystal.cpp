#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5+5;
int a[maxn];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,cnt = 0,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int l = 1,r = 1;
	while (r <= n)
	{
		r++;
		cnt += (r-l)*(a[r]-a[r-1]);
		while (cnt > m && l < r)
		{
			cnt -= a[r]-a[l];
			l++;
		}
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}