/*
第一题就读假题也是绝妙（refer to 联合猫国） 
就是求加了之后最多多少个数相同
那就枚举所有存在的值，然后算到它最多能合并多少个
二分边界操作代价，转化为值域和，注意最后一段等值操作的处理 
需要离散化一下emm，我不会离散化（bushi 
又读假题了，其实只能加
那不是黄题一样简单吗 
我在唐什么！！！！！ 
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
constexpr int N = 5e5 + 5;
int n, m;
ll a[N];
ll pfsum[N];
unordered_map<ll, ll> cnt;
inline int get(ll val) { // first >=
	return lower_bound(a, a + n + 1, val) - a;
}
inline int get2(ll val) { // last <=
	return upper_bound(a, a + n + 1, val) - a - 1;
}
inline ll cost(int pos, int i) {
	if (pos == i) return 0;
	else if (pos < i) return 1LL * (i - pos) * a[i] - (pfsum[i - 1] - pfsum[pos - 1]);
	else if (pos > i) return pfsum[pos] - pfsum[i] - 1LL * (pos - i) * a[i];
	else return 0;
}
signed main() {
	freopen("crystal.in", "r", stdin); 
	freopen("crystal.out", "w", stdout);
	cin.tie(0);
	ios::sync_with_stdio(false); 
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a + 1, a + n + 1);
	a[0] = pfsum[0] = -1e18 - 1;
	a[n + 1] = 1e18 + 1;
	for (int i = 1; i <= n + 1; ++i) pfsum[i] = pfsum[i - 1] + a[i], cnt[a[i]]++;
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		{
			int l = 1, r = i, lres = -1;
			while (l <= r) {
				const int lmid = (l + r) / 2;
				if (cost(lmid, i) <= m) r = lmid - 1, lres = lmid;
				else l = lmid + 1;
			}
			const ll minn = a[i] - a[get2(a[lres] - 1)];
			const ll ans1 = (i - lres + 1) + 
							min(
								cnt[a[i] - minn], 
								(minn == 0) ? (long long)1e18 : (1LL * (m - cost(lres, i)) / minn)
							);
			ans = max(ans, ans1);
		}
	}
	cout << ans << endl;
	return 0;
} 
