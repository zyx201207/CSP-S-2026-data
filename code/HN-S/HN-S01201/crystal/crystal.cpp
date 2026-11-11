#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, res;
ll m, mx;
ll a[N];
ll sum[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1, greater<int>());
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; ++i) {
		int l = i, r = n;
		int mid = 0, ans = 0;
		while(l <= r) {
			mid = (l + r) >> 1;
			if((mid - i) * a[i] - sum[mid] + sum[i] <= m) {
				l = mid + 1;
				ans = max(ans, mid - i + 1);
			}
			else
				r = mid - 1;
		}
		res = max(res, ans);
	}
	cout << res;
	return 0;
}
