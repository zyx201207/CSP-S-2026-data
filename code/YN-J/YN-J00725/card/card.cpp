#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m, k = -1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = n; i >= 1; i--) {
		int h = a[i];
		for (int j = m - 1; j >= 1; j--) {
			h = (h & a[i - j]);
		}
		k = max(h, k);
	}
	cout << k;
	return 0;
}