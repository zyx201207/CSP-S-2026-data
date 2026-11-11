#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 5;
ll a[maxn];
ll cf[maxn];
int n;
ll m;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) {
		cf[i] = a[i + 1] - a[i];
	}
	ll hy = 0;
	ll sum = 0;
	ll cnt = 1;
	ll max_cnt = 0;
	for (int i = n; i >= 1; i--) {
		int I = i - 1;
		hy = 0;
		sum = 0;
		cnt = 1;
		while (sum + hy + cf[I] <= m && I) {
			hy += cf[I];
			sum += hy;
			cnt++;
			I--;
		}
		max_cnt = max(max_cnt, cnt);
	}
	cout << max_cnt;
	return 0;
}

