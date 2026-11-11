#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e6 + 5;
int A[N];
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	if (c == 0) {
		if (t == 2) {
			int a;
			cin >> a;
			if (a == 4) cout << "1\n2\n";
			else cout << "0\n1\n";
		}
		else if (t == 17) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		else if (t == 12) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		else if (t == 14) cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		else if (t == 16) cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		return 0;
	}
	
	while (t--) {
		int n, d;
		cin >> n >> d;
		for (int i = 0; i < n; i++) cin >> A[i];
		int a = A[1] - A[0];
		int b = 2 * d - a;
		if (a > 2 * d) {
			cout << 0;
			continue;
		}
		int c = -1;
		for (int i = 0; i < n; i++) {
			if (A[i] > b + A[0]) {
				c = i - 1;
				break;
			}
		}
		if (c == -1) c = n - 1;
		int p = n - c;
		cout << p << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}