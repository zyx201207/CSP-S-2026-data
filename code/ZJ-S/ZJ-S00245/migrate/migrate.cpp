#include<bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 10;
long long a[N];
long long n, d;
long long minn, sum;
void dfs(long long l, long long r, long long step) {
	if(l == r) {
		if(step < minn) {
			minn = step;
			sum = 1;
		}
		else if(step == minn) sum++;
	}
	if(step > minn) return ;
	for(long long i = l + 1; i <= r; i++) {
		if(a[i] - a[l] <= d) {
			dfs(i, r, step + 1);
		}
	}
	return ;
}
void solve() {
	cin >> n >> d;
	bool f = 0;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		if(i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2]) f = 1;
	}
	if(n <= 9) {
		long long ans = 0;
		for(long long i = 1; i <= n; i++) {
			for(long long j = i + 1; j <= n; j++) {
				minn = LLONG_MAX;
				sum = 0;
				dfs(i, j, 0);
				if(sum == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c, T;
	cin >> c >> T;
	while(T--) solve();
	return 0;
}

