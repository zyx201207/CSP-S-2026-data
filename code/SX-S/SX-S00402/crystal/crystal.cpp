#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;

using LL = long long;

const int N = 5e5 + 5;

int n;
LL m, a[N], pre[N];

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i ++) cin>>a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) pre[i] = pre[i - 1] + a[i];
	int ans = 0;
	for(int i = 1, j = 1; i <= n; i ++) {
		while(pre[i] - pre[j - 1] + m < 1ll * (i - j + 1) * a[i]) j ++;
		ans = max(ans, i - j + 1); 
	}
	cout<<ans<<'\n';
	return 0;
}
