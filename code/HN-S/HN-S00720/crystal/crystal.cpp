#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long
using namespace std;
const int N = 5e5 + 5;
int n, ans;
ll sum, m, a[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int l = 1, r = 1;
	while(r + 1 <= n)
	{
		ll tsum = (a[r + 1] - a[r]) * (r - l + 1);
		if(sum + tsum <= m)
		{
			sum += tsum;
			r++;
		}
		else
		{
			sum -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << '\n';
	return 0;
}
