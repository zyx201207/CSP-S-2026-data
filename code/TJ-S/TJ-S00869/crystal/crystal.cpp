#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
const int N = 5e5 + 5;
long long a[N];
long long sum[N], ans[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	long long cnt = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] - a[i - 1] == 1)
			cnt++;
	}
	if(cnt == n) {
		unsigned long long ss = 0;
		int sss = 0;
		for(int i = 1; i <= n; ++i) {
			ss += i;
			sss++;
			if(ss == m || (ss < m && ss + i + 1 > m)) {
				cout << sss + 1 << "\n";
				return 0;
			}
		}
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		if(a[i] == a[i - 1]) {
			sum[i] = sum[i - 1];
			ans[i] = ans[i - 1];
		}
		else {
			sum[i] = (a[i] - a[i - 1]) * (i - 1);
			ans[i] = ans[i - 1] + sum[i];
		}
	}
	long long l = 1, r = n;
	while(l <= r) {
		if(ans[r] - ans[l] <= m) {
			cout << r - l + 1 << "\n";
			return 0;
		}
		if(sum[r] >= sum[l])
			r--;
		else
			l++;
	}
	return 0;
}
