#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int n, m;
int a[N]; 
signed main()
{
	cin.tie(0), cout.tie(0) -> sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n, greater<int>());
	int sum = 0, ans = 1;
	for (int l = 1, r = 1; l <= n && r <= n; l++)
	{
		if(l != 1) sum -= (a[l - 1] - a[l]) * (r - l + 1);
		while(sum + a[l] - a[r + 1] <= m && r + 1 <= n) {
			sum += a[l] - a[r + 1];
			r++;
		}
		ans = max(r - l + 1, ans);
		if(r == n) break;
	}
	cout << ans << '\n';
	return 0;	
} 
