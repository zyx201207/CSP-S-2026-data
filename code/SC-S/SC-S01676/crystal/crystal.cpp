#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,m;
int a[maxn],sum[maxn];
int calc(int l,int r)// 将[l,r]区间内的数都整成a[r]要多少费用
{return a[r] * (r - l + 1) - (sum[r] - sum[l - 1]);}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = 1,r = i,mid,res = i;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			if (calc(mid,i) > m)
				l = mid + 1;
			else
			{
				res = mid;
				r = mid - 1;
			}
		}
		ans = max(ans,i - res + 1);
	}
	cout << ans << '\n';
	return 0;
}