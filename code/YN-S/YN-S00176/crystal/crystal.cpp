#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, m;
const ll N = 5e5 + 10;
ll a[N];
ll b[N];
ll top;
ll sum;
ll c[N];
ll x;
ll sum1;
ll b1[N];
ll top1;
ll maxx = -1e9;
ll y;
ll e;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (ll i = 1; i <= n; i++) {
		b[i] = a[i] + b[i - 1];
	}
	for (ll i = 1; i < n; i++) {
		b1[i] = b[i];
	}
	for (ll i = 0; i < n; i++) {
		c[++top1] = b1[i];
	}
	for (ll i = 1; i <= n; i++) {
		b[++top] = ((a[i] * (i - 1)) - c[i]);
	}
	for (ll i = 1; i <= top; i++) {
		if (b[i] <= m) {
			maxx = max(i, maxx);
		}
	}
	cout << maxx;


	return 0;
}
