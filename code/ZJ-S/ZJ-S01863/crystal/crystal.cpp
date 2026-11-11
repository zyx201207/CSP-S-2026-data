#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 10;
int n, ans;
ll a[N], s[N], m;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
	for (int r = 1, l = 0; r <= n; r++) {
		while (l < r - 1 && (r - l) * a[r] - (s[r] - s[l]) > m) l++;
		ans = max(ans, r - l);
	}
	cout << ans << endl;
	return 0;
}