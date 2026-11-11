#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500010], bk[300010], nxt[500010];
int cnt[300010];
pair<int, int> stk[500010]; int pos[300010], top = 0;
int ans[300010];
bool ddd[300010];
// time complex O(mn+m^2)
signed main() {
	//int st = clock();
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in", "r", stdin); freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i]; cnt[a[i]]++;
		if (!bk[a[i]]) bk[a[i]] = i;
		else nxt[bk[a[i]]] = i;
	}
	for (int i = 1;i <= n;i++) {
		if (ddd[a[i]]) continue; ddd[a[i]] = 1;
		for (int i = 1;i <= m;i++) pos[i] = 0;
		top = 0;
		for (int j = i;j <= n;j++) {
			if (!pos[a[j]]) {
				stk[++top] = {a[j], j};
				pos[a[j]]++;
			} else {
				while (stk[top].first != a[j]) {
					pos[stk[top].first]--;
					top--;
				}
			}
		}
		while (top) {
			ans[stk[top].first] += cnt[a[i]];
			top--;
		}
	}
	//cerr << clock() - st;
	for (int i = 1;i <= m;i++) cout << ans[i] << " ";
	return 0;
}
