#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

int n;
const int N = 2e5 + 10;
ll a[N];
char c[N];

signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(), cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	
	int l = 1, r = n;
	ll cnt = 0;
	while (r > l) {
		ll ca = min(a[l], a[r]);
		if (c[l] != c[r]) {
			cnt += ca;
		}
		a[l] -= ca,a[r] -= ca;
		if (a[l] == 0) l++;
		if (a[r] == 0) r--;
	}
	cout << cnt;

	return 0;
}
/*
3
2 a
2 b
1 c

*/
