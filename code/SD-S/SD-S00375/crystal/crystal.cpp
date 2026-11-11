#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 5e5 + 5;

int n;
ll m;
ll a[N];
ll b[N];
ll w[N], s1[N], s2[N];
ll wwz[N];
int ans;

bool check(int x, int len) {
	int y = x + len - 1;
	if (y >= n) return false;
	return (wwz[y] + len * s2[y] - wwz[x - 1] <= m);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++) w[i] = a[i + 1] - a[i];
	for (int i = 1; i < n; i++) b[i] = w[i] * i;
	for (int i = 1; i < n; i++) s1[i] = s1[i - 1] + b[i];
	for (int i = 1; i < n; i++) s2[i] = s2[i - 1] + w[i];
	for (int i = 1; i < n; i++) wwz[i] = s1[i] - i * s2[i];
//	for (int i = 1; i <= n; i++) cout << s2[i] << ' ';
//	cout << '\n';
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(i, mid)) {
				l = mid;
			}
			else r = mid - 1;
		}
		ans = max(l + 1, ans);
	}
	cout << ans;
	
	return 0;
} 


