#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int ans = 0;
struct node {
	int a;
	vector <int> e;
	friend bool operator <(node x, node y) {
		return x.a > y.a;
	}
} zc[maxn];
signed main () {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> zc[i].a;
	sort (zc + 1, zc + n + 1);
	for (int i = 1; i <= n; i ++) {
		int j = zc[i].a;
		while (j) {
			zc[i].e.push_back(j % 2);
			j /= 2;
		}
	}
//	for (int i = 1; i <= n; i ++) {
//		cout << i << " : " << a[i] << " " << e[i].size() << endl;
//	}
//cout << a[3] << " " << a[2] << " " << e[3].size() << " " << e[2].size() << endl;
	int t = zc[m].e.size();
	if (zc[m].e.size() == zc[1].e.size()) {
		ans = zc[1].a;
		for (int i = 2; i <= m; i ++) {
			ans &= zc[i].a;
		}
		cout << ans << endl;
		return 0;
	}
	while (t --) {
		for (int i = 1; i < m; i ++) {
			if (zc[i].e.size() > zc[m].e.size()) {
				for (int j = zc[i].e.size() - 1; j >= zc[m].e.size(); j --) {
					zc[i].a -= (zc[i].e[j] << j);
				}
				for (int j = 1; j <= zc[i].e.size() - zc[m].e.size() + 1; j ++) zc[i].e.pop_back(); 
			}
		}
		sort (zc + 1, zc + n + 1);
		if (zc[m].e.size() == zc[1].e.size()) {
			ans = zc[1].a;
			for (int i = 2; i <= m; i ++) {
				ans &= zc[i].a;
			}
			cout << ans << endl;
			return 0;
		}
	}
	ans = zc[1].a;
	for (int i = 2; i <= m; i ++) {
		ans &= zc[i].a;
	}
	cout << ans << endl;
	return 0;
}


