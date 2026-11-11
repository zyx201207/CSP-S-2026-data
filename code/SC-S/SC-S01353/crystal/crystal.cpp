#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define V vector
#define pb push_back
#define INF (int)1e18
using namespace std;

const int maxn = 5e5;

int n, m;
int a[maxn+5];
int f[maxn+5];

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i)
		f[i] = f[i-1] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; ++i)
	{
		int l = 1, r = i;
		while(l <= r)
		{
			int mid = l + r >> 1;
//			printf("chk ")
			if((a[i]*(i-mid+1)) - (f[i]-f[mid-1]) <= m)
				r = mid - 1;
			else l = mid + 1;
		}
//		cout << ' ' << i << ' ' << l << '\n';
		ans = max(ans, i-l+1);
	}
	cout << ans << '\n';
	
	return 0;
}
/*

*/