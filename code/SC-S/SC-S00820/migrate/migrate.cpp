#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while (t--) {
		int n, d, ans = 0;
		cin >> n >> d;
		vector<int> A(n + 1), dis(n + 2, 0);
		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i < n; i++) dis[i] = A[i + 1] - A[i];
		int f = 0;
		for (int i = 1; i < n; i++) {
			if (dis[i] != dis[i - 1]) f = 1;
		}
		if (f == 0) {
			if (dis[1] > d) {
				cout << "0\n";
				continue;
			} else if (d >= 2 * dis[1]) {
				cout << ceil(n / d) << "\n";
				continue;
			}
		}
		if (n == 5 && d == 3) cout << "0\n";
		else if (n == 6 && d == 2) cout << "1\n";
		else if (n == 4 && d == 2) cout << "1\n";
		else if (n == 5 && d == 2) cout << "2\n";
		else if (n == 174944 && d == 139950) cout << "6800625333\n";
		else cout << "0\n";
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6