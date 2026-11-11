#include <bits/stdc++.h>
typedef unsigned long long ull ;
using namespace std;
int c, t;
long long x[2000005];//ÑÏ¸ñµÝÔö

void t_a(int n, ull d) {
	ull ans = 0;
	long long jc = x[1] - x[0];
	for (int i = 2; i < n - 2; i ++) {
		ull l = i * jc;
		if (l > d)
			break;
		for (int j = 1; j < n / 2; j++)
			for (int k = j + 1; j + k < n; k++)
				ans += n - j - k;
	}
	cout << ans;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		memset(x, 0, 2000004);
		int n;
		ull d;
		cin >> n >> d;
		for (int i = 0; i < n; i++)
			cin >> x[i];
		if ((c == 11) || (c == 12) ) {
			t_a(n, d);
		}
		cout << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
