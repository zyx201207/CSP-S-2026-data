//SN-S00347 王欣甜 西安市铁一中学 
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3fLL
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
int n, num, cnt[maxn], sid[maxn];
ll m, a[maxn], b[maxn], sum[maxn];
int check(int x) {
	ll res = inf;
	for(int i = 1; i <= num; i++)if(sid[i] >= x) {
		int xx = x - cnt[i];
		if(xx > 0)res = min(res, a[i] * xx - (sum[sid[i - 1]] - sum[sid[i - 1] - xx]));
	}
	if(res <= m)return 1;
	return 0;
}
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + n);
	for(int i = 1; i <= n; i++) {
		if(i == 1 || b[i] != b[i - 1]) {
			num++;
			a[num] = b[i];
			cnt[num] = 1;
		}else {
			cnt[num]++;
		}
	}
	for(int i = 1; i <= num; i++) {
		sid[i] = sid[i - 1] + cnt[i];
	}
	for(int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + b[i];
	}
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			l = mid + 1;
		}else {
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
