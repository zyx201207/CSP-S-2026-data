#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll M = 2e5 + 5;
ll n, maxn = 0;
ll cnt = 1; 
string s[M];
bool vis[M];

ll cmaxc(ll x, ll y) {
	if (x * 1LL > y * 1LL) return x;
	return y;
}

ll getValue(string x) {
	ll l = 0, r = x.length()-1;
	ll res = 0;
	while (l <= r) {
		if (x[l] != x[r]) res += 1; 
		l += 1;
		r -= 1;
	}
	return res;
}

void dfs(ll sum, string temp) {
	if (sum >= n) {
		// cout << temp << endl;
		maxn = cmaxc(maxn, getValue(temp));
		return;
	}
	for (ll i = 0; i < n; i++) {
		if (!vis[i]) {
			vis[i] = true;
			dfs(sum + 1, temp + s[i]);
			vis[i] = false;
		}
	}
} 

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll len;
		char ch;
		cin >> len >> ch;
		while (len--) {
			s[i] += ch; 
		}
		// cout << s[i] << endl;
	}
	
	dfs(0, "");
	cout << maxn;
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
} 
