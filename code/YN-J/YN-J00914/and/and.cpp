#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100005], last, ad, x;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (long long i = n; i >= 1; i--) {
		cin >> a[i];
	}
	for (long long i = n; i >= 1; i--) {
		for (long long j = i - 1; j >= i - m; j--) {
			x = i - 1;
			ad = a[i];
			while (x >= j) {
				ad = ad & a[x];
				x--;
			}
			last = max(last, ad);
		}
	}
	cout << last;
	return 0;
}