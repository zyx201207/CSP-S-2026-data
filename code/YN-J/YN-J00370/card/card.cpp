#include <bits/stdc++.h>
using namespace std;
long long n, m, ans[300005], a[1000005], r[10000005], num[100005];
vector<long long> vt;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int it = 0; it < n; it++) {
		vt.clear();
		memset(a, 0, sizeof a);
		for (int i = 1 + it; i <= n; i++) {
			a[num[i]]++;
			if (a[num[i]] > 1) {
				memset(a, 0, sizeof a);
				int k = 0;
				for (int j = 0; vt[j] != num[i]; j++) {
					r[j] = vt[j];
					a[vt[j]]++;
					k++;
				}
				a[num[i]]++;
				vt.clear();
				for (int j = 0; j < k ; j++)
					vt[j] = r[j];
				memset(r, 0, sizeof r);
			}
			vt.push_back(num[i]);
		}
		for (int i = 0; i < vt.size(); i++) {
			ans[vt[i]]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << ' ';
	return 0;
}