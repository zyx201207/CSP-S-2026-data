#include <bits/stdc++.h>
#define N 500010
using namespace std;
typedef long long ll;

ll n, m, a[N], pS[N];
inline ll read() {
	ll x = 0, f = 1;
	char ch = getchar();
	while (!isdigit(ch) && ch != '-') ch = getchar();
	if (ch == '-') f = -1;
	else x = ch - '0';
	ch = getchar();
	while (isdigit(ch)) {
		x = (x << 1) + (x << 3) + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline bool check(ll x, ll i) {
	//cout << x << " " << i << " " << (i - x + 1) * a[i] - (pS[i] - pS[x - 1]) << "\n";
	return (i - x + 1) * a[i] - (pS[i] - pS[x - 1]) <= m;
}

int main() {
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w" ,stdout);
	n = read(); m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) pS[i] = pS[i - 1] + a[i];
	//for (int i = 1; i <= n; ++i) cout << pS[i] << " ";
	ll Ans = 0;
	for (int i = 1; i <= n; ++i) {
		ll L = 1, R = i;
		while (L + 3 <= R) {
			ll mid = (L + R) / 2;
			if (check(mid, i)) R = mid;
			else L = mid;
		} 
		ll j;
		for (j = L; j <= R; ++j)
			if (check(j, i)) break;
		Ans = max(Ans, i - j + 1);
	}
	cout << Ans;
	return 0;
}
