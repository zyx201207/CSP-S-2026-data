#include <bits/stdc++.h>
#define ll long long
#define Maxn 2000005

using namespace std;

ll SubID, T, n, d, res;
ll f[Maxn], num[Maxn];
ll a[Maxn], s[Maxn];
ll lst[Maxn];

void init() {
	for (ll i = 0; i <= n; i ++) {
		f[i] = num[i] = lst[i] = a[i] = s[i] = 0;
	} n = d = res = 0;
}

void billtun() {
	init(), cin >> n >> d;
	for (ll i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	res = 0;
	for (ll i = 1, it = 0; i <= n; i ++) {
		f[i] = 0, num[i] = 1, it = i;
		s[i] = 1, s[i - 1] = 0;
		lst[0] = i;
		
		for (ll j = i + 1; j <= n; j ++) {
			while (a[it] + d < a[j]) { it ++; }
			f[j] = f[it] + 1, num[j] = s[lst[f[it]]] - s[it - 1];
			lst[f[j]] = j, s[j] = s[j - 1] + num[j];
			if (num[j] == 2) {
				res ++;
			}
		}
	} cout << res << "\n";
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> SubID >> T;
	while (T --) { billtun(); }
	return 0;
}
