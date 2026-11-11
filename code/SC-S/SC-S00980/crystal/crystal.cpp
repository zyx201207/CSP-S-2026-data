#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 5;

int n, m, res = 1;
ll a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);  
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1, [](int x, int y){return x > y;});
	
	ll now = m, h = 0;
	int ans = 1;
	a[0] = a[1];
	for (int i = 1; i <= n; i++) {
		now = now - h + (ans - i + 1) * (a[i - 1] - a[i]);
		int j = ans + 1;
		h = 0;
		while (j <= n && h + a[i] - a[j] <= now) h += a[i] - a[j], j++;
		ans = j - 1;
		res = max(res, ans - i + 1);
		if (j > n) break;
	}
	
	cout << res << '\n';
	
	return 0;
}