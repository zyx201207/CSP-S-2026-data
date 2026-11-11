#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
const int MAXM = 3e5 + 5;
int n, m;
int a[MAXN];
int t[MAXM];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if (m == 1) {
		cout << n;
		return 0;
	}
	int i = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		for (int j = i; j <= n; j++) {
			t[a[j]]++;
			if (a[j] == a[j + 1])
				j++;
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}