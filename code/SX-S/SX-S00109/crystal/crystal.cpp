#include <bits/stdc++.h>
#define ll long long;
using namespace std;
string x, n, m;

int main() {
//  freopen("crystal.in","r",stdin);
//  freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; i++) {
		bool f = 0;
		ll x = a[i] - a[i - 1];
		for (int j = i - 1; j >= 1; j--) {
			if (m < x) {
				f = 1;
				break;
			}
			a[j] += x;
			m -= x;
		}
	}
	cout << m << " ";
	return 0;
}
