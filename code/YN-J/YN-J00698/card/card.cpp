#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m, t = 0;
	cin >> n >> m;
	int a[1005];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k <= n; k++) {
				if (a[k] == a[j]) {
					a[j] = a[k];
				}
			}
		}
		if (a[i] == i) {
			cout << i << " ";
		}
	}


	return 0;
}