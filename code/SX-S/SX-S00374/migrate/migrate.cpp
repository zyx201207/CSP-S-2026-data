#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
int a[1000005];
bool b[2000005];
int sum;
int record[2000005];
int maxStep;

void dfs(int st, int step) {
	if (step > maxStep)
		return;
	for (int i = st + 1 + n; i <= min(i + d, a[n] + n); i++) {
		if (b[i]) {
			record[i]++;
			dfs(i, step + 1);
		}
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c == 11 || c == 12) {
		while (t--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> a[i];
			cout << n - int(double(d) / double(a[n]) - 0.5) + 1 << endl;
		}
	} else if (c == 13 || c == 14) {
		while (t--) {
			sum = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				b[a[i] + n] = 1;
				int farthest = 0, nearest = 0;
				for (int j = i; j >= max(i - d, 0); j--) {
					if (b[j] == 1) {
						farthest = j;
						if (nearest == 0)
							nearest = j;
					}
				}
				for (int j = min(farthest, nearest - d); j >= max(farthest - d, 0); j--) {
					if (b[j])
						sum++;
				}
			}
			cout << sum << endl;
		}
	} else {
		while (t--) {
			sum = 0;
			cin >> n >> d;
			for (int i = 1; i <= n; i++) {
				cin >> a[i];
				b[a[i] + n] = 1;
			}
			maxStep = int(double(a[n] - a[1]) / double(d) + 0.5);
			for (int i = 1; i <= n - 2; i++) {
				dfs(a[i] + n, 0);
				for (int i = a[1] + n; i <= a[n] + n; i++) {
					if (record[i] == 2)
						sum++;
					record[i] = 0;
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}