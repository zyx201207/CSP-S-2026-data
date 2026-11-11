#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
short c;
int T;
long long n, d, x[N], sum;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--) {
		sum = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (x[j] - x[i] <= T)
					continue;
				else if (x[i + 1] - x[i] > d)
					continue;
				if (j - i == 3 && x[j] - x[i] <= 2 * d && x[j] - x[i] > d) {
					sum++;
				}
			}
		}
		cout << sum << "\n";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}