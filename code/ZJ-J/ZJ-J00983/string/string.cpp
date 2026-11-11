#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5 + 10;

ll n, ans, sum;
ll a[N];
char c[N];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%lld", &n);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
		cin >> c[i];
	}
	ll l = 1, r = n;
	ll len = 0, sl = a[l], sr = a[r];
	while (len * 2 < sum) {
		if (c[l] != c[r]) {
			if (sl > sr) {
				len += sr;
				ans += sr;
				sl -= sr;
				sr = a[--r];
			}
			else if (sl < sr) {
				len += sl;
				ans += sl;
				sr -= sl;
				sl = a[++l];
			}
			else {
				len += sl;
				ans += sl;
				sl = a[++l];
				sr = a[--r];
			}
		}
		else {
			if (sl >= sr) {
				len += sr;
				sl -= sr;
				sr = a[--r];
			}
			else if (sl < sr) {
				len += sl;
				sr -= sl;
				sl = a[++l];
			}
			else {
				len += sl;
				sl = a[++l];
				sr = a[--r];
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
