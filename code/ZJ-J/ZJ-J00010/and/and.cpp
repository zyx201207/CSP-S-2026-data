#include <bits/stdc++.h>
using namespace std;
long long n, a[200005], m;
long long cnt[40];
set<long long> tj;
vector<long long> ers;
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i], tj.insert(i);
	for (long long i = 1; i <= n; i++) {
		for (long long j = 31; j >= 0; j--) {
			if ((a[i] >> j) & 1) cnt[j]++;
		}
	}
	long long ans = 0;
	for (long long i = 31; i >= 0; i--) {
		if (cnt[i] >= m) {
			ans |= (1ll << i);
			ers.clear();
			for (long long x : tj) {
				if (!(a[x] & (1 << i))) {
					ers.push_back(x);
					for (long long j = 31; j >= 0; j--) {
						if ((a[x] >> j) & 1) cnt[j]--;
					}
				}
			}
			for (long long v : ers) {
				tj.erase(tj.find(v));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
