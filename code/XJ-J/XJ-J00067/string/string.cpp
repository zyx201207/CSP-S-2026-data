#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
char c[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int l = 1, r = n;
	char cl = c[1], cr = c[n];
	long long al = a[1], ar = a[n];
	long long ans = 0; 
	while (l < r) {
		int mn = min(al, ar);
		if (cl == cr) {
			al -= mn;
			ar -= mn;
		} else {
			ans += mn;
			al -= mn;
			ar -= mn;
		}
		if (al == 0) l++, al = a[l], cl = c[l];
		if (ar == 0) r--, ar = a[r], cr = c[r];
	}
	cout << ans << '\n';
	return 0;
} 
