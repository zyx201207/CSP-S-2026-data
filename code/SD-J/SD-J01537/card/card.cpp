#include <bits/stdc++.h>
using namespace std;
int a [200010];
int b [100010];
int main () {
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	ios::sync_with_stdio (false);
	cin.tie (0);
	cout.tie (0);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) {
		cin >> a [i];
	}
	for (int i = 1;i <= m;i ++) {
		b [i] = i;
	}
	int d = 0;
	for (int i = 1;i <= n;i ++) {
		if (a [i] == a [i - 1]) {
			d ++;
			b [a [i]] ++;
		}
		else b [a [i]] += d;
	}
	for (int i = 1;i <= m;i ++) {
		cout << b [i] << " ";
	}
	return 0;
} 



















