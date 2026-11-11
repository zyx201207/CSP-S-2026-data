#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N];
int ans[M];
int d[N], top;

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		top = 0;
		map<int, int>m_ap, ap;
		m_ap.clear();
		ap.clear();
		for (int j = i; j <= n; j++) {
			int num = a[j];
			if (!m_ap[num]) {
				m_ap[num] = true;
				ap[num] = top + 1;
				d[++top] = num;
				continue;
			}
			int len = top;
			for (int k = len; k > m_ap[num]; k--) {
				m_ap[d[k]] = 0;
				ap[d[k]] = 0;
				top--;
			}
			top--;
			d[++top] = num;
		}
		cout << top << '\n';
		for (int i = 1; i <= top; i++)
			ans[d[i]]++, cout << d[i] << " ";
		cout << '\n';
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}