#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],sum[500010];
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1;i <= n;i++)
	{
		int l = 1,r = i;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if((i - mid + 1) * a[i] - sum[i] + sum[mid - 1] <= m)
			{
				r = mid - 1;
				ans = max(ans,i - mid + 1);
			}
			else l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
