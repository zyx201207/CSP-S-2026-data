#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int MAXN = 5e5 + 5;
int n,m,a[MAXN],sum[MAXN];
inline int cost(int l,int r)
{return (r - l + 1) * a[r] - sum[r] + sum[l - 1];}
signed main()
{
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
		sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for(int l = 1,r = 0;r < n;)
	{
		++r;
		while(cost(l,r) > m)
			++l;
		ans = max(ans,r - l + 1);
	}
	cout << ans;
}