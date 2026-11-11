#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll n, ans, a[MAXN], b[MAXN];
char c[MAXN], d[MAXN];
int main() {
	freopen("string.in", "r",stdin);
	freopen("string.out", "w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		b[n - i + 1] = a[i]; d[n - i + 1] = c[i];
	}
	int l = 1, r = 1;
	while (l <= n && r <= n) {
		if (a[l] > b[r]) {
			if (c[l] != d[r]) ans += b[r];
			a[l]-=b[r];
			r++; 
		}
		else {
			if (c[l] != d[r]) ans += a[l];
			b[r]-=a[l];
			l++;
		}
	}
	cout << ans / 2;
	return 0;
}
