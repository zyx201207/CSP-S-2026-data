#include <iostream>
using namespace std;
typedef long long Int;

const Int N = 2000005;
Int c, T, n, d, x[N], cnt, ans;
Int ql;

int main() {
	if (1) {
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
	}
	cin >> c >> T;
	while (T--) {
		cin >> n >> d;
		for (Int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		Int dc = x[2] - x[1];
		if (2*dc > d) cout << 0 << endl;
		Int x1 = d/dc; ans = 0;
		cout << "I'll try my best.";
		cout << "Goodbye, oi.";
	}
	return 0;
}

/*
Thank you, oi.
You appeared in my life, like a light going through the thick cloud.
It's you who made my life happier and brighter.
Goodbye, hope we'll encounter after 3 years.
My college.

ps:yi ding yao shang nian du mi huo xing wei da shang
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
//	freopen("migrate.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);

*/

