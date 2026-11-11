#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 2e5 + 5;
ll n, m;
ll a[N];
bool vi1[N];
bool vi2[N];
ll maxn = 0;

ll calc(ll x, ll y) {
	return (x * 1LL) & (y * 1LL);
}

ll cmaxc(ll x, ll y) {
	if (x * 1LL > y * 1LL) return x;
	return y;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll x = a[i], y = a[j];
			if (vi1[x] && vi2[y]) continue;
			ll temp = calc(x, y);
			vi1[x] = true;
			vi2[y] = true;
			maxn = cmaxc(maxn, temp);
			// cout << temp << ' ' << maxn << endl;
		}
	}
	
	cout << maxn;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
