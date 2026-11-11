#include <bits/stdc++.h>
using namespace std;
int n, m, t, ques;
long long x[2000005];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> ques >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> x[i];
		bool flag = true;
		for (int i = 2; i < n; i++) {
			flag = flag && (x[i] - x[i - 1] == x[i + 1] - x[i]);
		}
		cout << rand() << endl;
	}
	return 0;
}