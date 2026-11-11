#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void FileIO(const char * inf, const char * ouf) {
	freopen(inf, "r", stdin);
	freopen(ouf, "w", stdout);
}

constexpr int MAXN = 500010;

int n;
ll m;
ll a[MAXN];
ll s[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	FileIO("crystal.in", "crystal.out");
	cin >> n >> m;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for (int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	ll ans = 0;
	for (int R = 1; R <= n; R ++) {
		// 求最小的 L 使得 (R-L+1)*a[R] - sum[L...R] <= m
		int l = 0, r = R+1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if ((R-mid+1ll)*a[R] - (s[R] - s[mid-1]) <= m) r = mid;
			else l = mid;
		}
		// cout<<R<<": "<<l<<" "<<r<<endl;
		ans = max(ans, R-r+1ll);
	}
	cout<<ans<<endl;
}
