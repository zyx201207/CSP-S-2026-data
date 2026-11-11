#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 10, INF = 0x3f3f3f3f;

int n, m, num[maxn], sum[maxn];
int ans = LLONG_MIN;

bool check(int cnt){
	for (int i = 1; i <= n - cnt + 1; i ++){
		int l = i, r = i + cnt - 1;
		int s1 = sum[r] - sum[l - 1];
		int s2 = num[r] * cnt;
		if (s2 - s1 <= m) return true;
	}
	return false;
}

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m; sum[0] = 0;
	for (int i = 1; i <= n; i ++) cin >> num[i];
	sort(num + 1, num + 1 + n);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + num[i];
	
	int l = 1, r = n;
	while (l <= r){
		int mid = (l + r) / 2;
		if (check(mid)) ans = max(ans, mid), l = mid + 1;
		else r = mid - 1;
	}
	
	cout << ans;
	return 0;
}