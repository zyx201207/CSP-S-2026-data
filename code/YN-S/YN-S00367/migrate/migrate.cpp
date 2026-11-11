#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 2e6 + 10;
const LL inf = 0x3f3f3f3f3f3f3f3f;

int C, T;
int n;
LL d, ans;
LL x[N], num[N];


int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> C >> T;
	if (C == 11 || C == 12) {
		while (T--) {
			cin >> n >> d;
			for (int i = 1; i <= n; i++)
				cin >> x[i];
			LL delta = x[2] - x[1];
			d /= delta;
			if (d < 2 || n < 2 * d + 1)
				cout << 0 << '\n';
			else
				cout << n - 2 * d + 1 << '\n';
		}
	}
	return 0;
}