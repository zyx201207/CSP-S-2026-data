#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 5e5 + 10;
int n;
ll m, a[N], pre[N];

bool check(int x) {
	ll best = 2e18;
	for (int i = x; i <= n; i++) best = min(best, x * a[i] - (pre[i] - pre[i - x]));
	return best <= m;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	
	int l = 0, r = n + 1;
	while (l != r) {
		int mid = (l + r) / 2;
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l - 1;
	
	return 0;
}
