#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N];
long long sum[N]; 
int n;
long long m;
bool check(long long x, long long y) {
	long long ans = (y - x + 1) * a[y];
	ans -= (sum[y] - sum[x - 1]);
	return ans <= m; 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	bool f = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
		if(a[i - 1] > a[i]) f = 1;
	}
	if(f) sort(a + 1, a + 1 + n);
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		int l = 1, r = i;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(mid, i)) {
				long long lp = i - mid + 1;
				ans = max(ans, lp);
				r = mid - 1;
			}
			else l = mid + 1;
		}
	}
	cout << ans << '\n';
	return 0;
} 
