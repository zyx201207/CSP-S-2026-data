#include <bits/stdc++.h>
using namespace std;
const int NM = 2e5 + 5;
typedef long long ll;

struct Node {
	ll num;
	char c;
} a[NM];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ll n, ans = 0;
	cin >> n;
	int j = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].num;
		cin >> a[i].c;
	}
	ll i = 1;
	while (i < j) {
		if (a[i].c != a[j].c) {
			if (a[i].num == a[j].num) {
				ans += a[i].num;
				i++;
				j--;
			} else if (a[i].num > a[j].num) {
				ans += a[j].num;
				a[i].num -= a[j].num;
				j--;
			} else {
				ans += a[i].num;
				a[j].num -= a[i].num;
				i++;
			}
		} else {
			if (a[i].num == a[j].num) {
				j--;
				i++;
				continue;
			} else {
				if (a[i].num > a[j].num) {
					a[i].num -= a[j].num;
					j--;
				} else {
					a[j].num -= a[i].num;
					i++;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}