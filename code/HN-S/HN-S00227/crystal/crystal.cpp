#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n, m, a[500005], b[500005], t[500005];
int maxn, f;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		t[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i < n; i++) {
		b[i] = a[i + 1] - a[i];
		if(i != 1 && b[i] != b[i - 1]) f = 1;
	}
	if(a[1] == a[n]) {
		cout << n;
		return 0;
	}
	if(f != 1) {
		int x = 1, cnt = 0;
		while(m > 0) {
			m -= x * b[1];
			x++;
			cnt++;
		}
		if(m != 0) cnt--;
		cout << min(cnt + 1, n);
		return 0;
	}
	int ans = 0, sum = 0, x = m;
	for(int i = 1; i <= n; i++) {
		ans = 1, sum = 0, x = m;
		for(int j = i; j > 1; j--) {
			sum += b[i - 1];
			if(x - sum <= 0) {
				if(x - sum == 0) ans++;
				maxn = max(maxn, min(n, ans));
				break;
			}
			x -= sum;
			ans++;
		}
		maxn = max(maxn, min(n, ans));
	}
	cout << maxn;
	return 0;
}
