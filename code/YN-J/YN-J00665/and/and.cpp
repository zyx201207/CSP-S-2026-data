#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxa = -1;

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (m == 1)
		for (int i = 1; i <= n; i++)
			maxa = max(maxa, a[i]);
	else if (m == 2)
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++)
				maxa = max(maxa, a[i] & a[j]);
	else if (m == n) {
		maxa = a[1];
		for (int i = 2; i <= n; i++)
			maxa &= a[i];
	} else if (m == n - 1) {
		for (int i = 1; i <= n; i++) {
			int ans = (i == 1 ? a[2] : a[1]);
			for (int j = 1; j <= n; j++)
				if (j != i)
					ans &= a[j];
			maxa = max(maxa, ans);
		}
	} else {
		int b[4] = {};
		for (int i = 1; i <= n; i++)
			b[a[i]]++;
		if (b[1] && !b[2] && !b[3])
			maxa = 1;
		else if ((b[1] && b[2] && !b[3]) || (!b[1] && b[2] && b[3]) || (b[1] && b[2] && b[3]) || (!b[1] && b[2] && !b[3]))
			maxa = 2;
		else if ((!b[1] && !b[2] && b[3]) || (b[1] && !b[2] && b[3]))
			maxa = 3;
		else
			maxa = 0;
	}
	cout << maxa << endl;
	return 0;
}