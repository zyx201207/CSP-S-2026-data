#include <iostream>
#include <algorithm>
#define NAME "crystal"

using namespace std;
typedef long long ll;

namespace mian {

int n;
ll m;
ll as[500008], as_pre[500008];

void main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> as[i];
	}
	sort(as, as + n);
	for (int i = 0; i < n; i++) {
		as_pre[i + 1] = as_pre[i] + as[i];
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = -1, r = i;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			ll sm = as_pre[i] - as_pre[mid];
			ll last = (i - mid) * as[i - 1] - sm;
			if (last > m) {
				l = mid;
			} else {
				r = mid;
			}
		}
		ans = max(ans, i - r);
//		last = l;
	}
	cout << ans << "\n";
}

}

int main() {
	freopen(NAME ".in", "r", stdin);
	freopen(NAME ".out", "w", stdout);

	mian::main();

	fclose(stdin);
	fclose(stdout);

	return 0;
}
