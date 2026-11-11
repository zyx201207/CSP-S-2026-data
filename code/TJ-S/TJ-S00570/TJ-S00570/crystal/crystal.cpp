#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long

const int N = 5e5 + 5;
ll n, m, a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	ll nw = 0;
	int ans = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		nw += (i - j) * (a[i] - a[i - 1]);
		while (nw > m) nw -= a[i] - a[j], j++;
		ans = max(ans, i - j + 1);
	}
	cout << ans;
	return 0;
}
