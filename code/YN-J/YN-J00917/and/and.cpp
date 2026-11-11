// Yang Mofei
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
vector<int> vec;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	vec.resize(n);
	for (auto &num : vec) {
		cin >> num;
	}

	vector<int> last = vec;
	vector<int> cur;

	int ans = 0;
	for (int bit = 30; bit >= 0; bit--) {
		for (auto num : last) {
			if ((num >> bit) & 1) {
				cur.push_back(num);
			}
		}
		if (cur.size() >= m) {
			ans *= 2;
			ans++;
			last = cur;
			cur.clear();
		} else {
			ans *= 2;
			cur.clear();
			// Nothing changes
		}
//		cout << endl;
//		cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}