#include <bits/stdc++.h>
#define int long long
using namespace std;
const int CN = 5e5+5;
int n,m,l = 1,ans,a[CN];
#undef int
int main()
#define int long long
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (int r = 1;r <= n;r++)
	{
		m -= (r-l)*(a[r]-a[r-1]);
		while (m < 0)
			m += (a[r]-a[l++]);
		ans = max(ans,r-l+1);
	}
	cout << ans;
	return 0;
}