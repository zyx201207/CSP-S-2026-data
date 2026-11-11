#include<bits/stdc++.h>
#define ll long long
const int N = 5e5 + 5;
using namespace std;
int n, ans, l, r;
ll a[N], m, sum[N];
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	r = 1;
	for(l = 1; l <= n; l++)
	{
		while(r <= n && a[r] * (r - l + 1) - (sum[r] - sum[l - 1]) <= m)
			r++;
		ans = max(ans, r - l);
	}
	cout << ans;
}
