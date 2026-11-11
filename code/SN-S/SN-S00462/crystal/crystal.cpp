// SN-00462 µ­³şÜ² ¸¨ÂÖÖĞÑ§ 
#include <bits/stdc++.h>
#define il inline
#define int long long
#define vc vector
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int N = 5e5 + 5;
int TTT = 1, n, m, k, a[N], s[N];

il int get(int l, int r)
{
	return s[r] - s[l - 1];
}

void mian()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		s[i] = s[i - 1] + a[i];
		int	l = 1, r = i - 1;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if((i - mid + 1) * a[i] - get(mid, i) <= m) r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, i - l + 1);
	}
	cout << ans;
}


signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
//	cin >> TTT;
	while(TTT--) mian();
	return 0;
}
