#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 5;
int n,m,a[N],maxn,sum[N];
void solve(int rr,int val)
{
	int l = 1,ans = rr,r = rr;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (val * (rr - mid + 1) - (sum[rr] - sum[mid - 1]) <= m)
		{
			ans = mid;
			r = mid - 1;	
		}	
		else
		{
			l = mid + 1;
		}
	}
	maxn = max(maxn,rr - ans + 1);
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i ++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		solve(i,a[i]);	
	}
	cout << maxn;
	return 0;
}

