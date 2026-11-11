#include <bits/stdc++.h>
using namespace std;
int c, t, n, d;
long long ans[2000005], ct, cnt[2000005];
map<long long, bool> ma;
vector<long long> a;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--) {
		ct = 0;
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			int t;
			scanf("%lld", &t);
			a.push_back(t);
			ma[a[i - 1]] = 1;
			ans[i] = cnt[i] = 0;
		}

//		if(c==11 || c==12){
//
//		}
//		if(c==13 || c==14){
//
//		}
		ans[1] = 1;
		for (int i : a) {
			for (int j = 1; j <= d && j + i <= n && ma[i + j]; j++) {
				if (ans[i + j]) {
					if (ans[i + j] > ans[i] + 1) {
						ans[i + j] = ans[i] + 1;
						cnt[i + j] = 0;
					} else if (ans[i + j] == ans[i] + 1) {
						cnt[i + j]++;
					}
				} else {
					ans[i + j] = ans[i] + 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (cnt[i])
				ct++;
		}
		printf("%lld\n", ct);
	}
	return 0;
}
