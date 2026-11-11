#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int b[501000];
int t[500005];
int ti = 0;
int ans[3000005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			if (a[j] == a[i]) {
				for (int k = j; k <= n; k++) {
					if (b[a[k]] == 0) {
						ans[a[k]]++;
						b[a[k]] = 1;
						t[++ti] = a[k];
					}
				}
				for (int k = 1; k <= ti; k++) {
					b[k] = 0;
				}
				break;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	//不想打部分分了
}