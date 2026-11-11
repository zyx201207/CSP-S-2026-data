#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5 + 5;
ll n, m, a[N], ans = 1, duil[N], l = 1, r, now;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
    duil[++r] = a[1];
    for(ll i = 2; i <= n; i++) {
    	now += (a[i] - a[i-1]) * (r - l + 1);
    	duil[++r] = a[i];
    	while(now > m) {
    		now -= (a[i] - duil[l++]);
		}
		ans = max(ans, r - l + 1);
	}
	printf("%lld", ans);
	return 0;
}
