#include <bits/stdc++.h>
using namespace std;
#define int long long

struct sstr {
	bool f;
	int idx;
};
int n, m;
int a[1000001], cnt[1000001];
sstr vis[10000001];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		vector<int>d;
		int c = 0;
		for (int j = i; j <= n; i++) {
			if (!vis[a[j]].f) {
				c++;
				d.push_back(a[j]);
				vis[a[j]].f = 1;
				vis[a[j]].idx = c;
			} else {
				for (int k = vis[a[j]].idx; k <= c + 1; k++) {
					vis[d[k]].f = 0;
				}
				d.erase(d.begin() + vis[a[j]].idx, d.begin() + c + 1);
				c -= c - vis[a[j]].idx;
				d.push_back(a[j]);
				vis[a[j]].f = 1;
				vis[a[j]].idx = c;
			}
		}
		for (int x : d) {
			cnt[x]++;
		}
	}
	for (int i = 1; i <= m; i++)
		cout << cnt[i] << " ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


