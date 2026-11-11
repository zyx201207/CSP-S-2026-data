#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N], b[N], sum[M];
bool bl[M];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = i - 1; j < n; j++) {
			if (bl[a[j]] == 1) {
				for (int cnt; cnt >= i - 1; cnt--) {
					if (b[cnt] != a[j]) {
						b[cnt] = 0;
					} else if (b[cnt] == a[j]) {
						b[cnt] = 0;
						bl[a[j]] = 0;
						cnt--;
						break;
					}
				}
			} else {
				bl[a[j]] = 1;
				b[cnt] = a[j];
			}
			cnt++;
		}
		for (int r = 0; r < cnt; r++) {
			sum[b[r]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << sum[i] << " ";
	}
	return 0;
}