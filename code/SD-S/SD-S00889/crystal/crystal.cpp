#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 5e5 + 10;
ll a[N], seg[2*N];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	ll m;
	scanf("%d%lld", &n, &m);
	bool flag = true;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != i) {
			flag = false;
		}
	}
	if (flag) {
		int x = 1;
		for (int i = 1; i <= 2*n; i += 2) {
			seg[i] = (x + 1) * x / 2;
			seg[i-1] = seg[i] - 1;
			x++;
		}
		if (m >= seg[2*n-1]) {
			printf("%d\n", n);
			return 0;
		}
		for (int i = 1; i <= 2*n-1; i++) {
			if (m >= seg[i] && m <= seg[i+1]) {
				printf("%d\n", (i+1)/2+1);
				return 0;
			}
		}
	}
	sort(a+1, a+n+1, cmp);
	ll sum = 0, cnt = 1;
	ll mx = 0;
	for (int i = 1; i <= n; i++) {
		sum = 0, cnt = 1;
		for (int j = i+1; j <= n; j++) {
			if (sum + a[i] - a[j] <= m) {
				sum += (a[i] - a[j]);
				cnt++;
				mx = max(mx, cnt);
			}
		}
	}
	printf("%lld\n", mx);
	
	return 0;
}
