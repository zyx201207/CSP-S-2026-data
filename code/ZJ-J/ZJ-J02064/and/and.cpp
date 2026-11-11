#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e3 + 5;
int n, m;
int a[N];
int cnt = -2e9;
void js(int i, int j, int ans) {
	if(i == n) {
		if(j != m) {
			return ;
		}
	}
	if(j == m) {
		cnt = max(cnt, ans);
		return ;
	}
	if(j == 0) {
		js(i + 1, j + 1, a[i]);
		js(i + 1, j, 0);
	} else {
		js(i + 1, j + 1, (ans & a[i]));
		js(i + 1, j, ans);
	}
}
signed main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	if(m == 1) {
		cout << a[1];
		return 0;
	}
	if(m == 2) {
		int maxx = -2e9;
		for(int i = 1; i <= n; i ++) {
			for(int j = i + 1; j <= n; j ++) {
				maxx = max(maxx, (a[i] & a[j]));
			}
		}
		cout << maxx;
		return 0;
	}
	if(m == n) {
		int ans = (a[1] & a[2]);
		for(int i = 3; i <= n; i ++) {
			ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	if(m == n - 1) {
		int ans = a[1];
		for(int i = 2; i < n; i ++) {
			ans = (ans & a[i]);
		}
		cout << ans;
		return 0;
	}
	js(1, 0, 0);
	cout << cnt;
}
