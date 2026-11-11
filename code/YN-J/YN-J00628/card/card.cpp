#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
int n, m;
int a[N], b[N];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i - 1; j > 1; j--) {
			if (a[i] == a[j]) {
				int l = i - 1, r = j;
				while (l <= r) {
					a[l] = 0;
					l++;
				}
				break;
			}
		}
		for (int j = 1; j <= i; j++) {
			b[a[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << b[i] << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}