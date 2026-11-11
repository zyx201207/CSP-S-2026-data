#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
int n;
ll a[N], m, p[N], ans;

bool check(int x) {
	for(int i = x; i <= n; i ++) {
		if(a[i] * x - (p[i] - p[i - x]) <= m) return 1;
	}
	return 0;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i ++) p[i] = p[i - 1] + a[i];
	int l = 1, r = n;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout << l - 1;
	return 0;
}

