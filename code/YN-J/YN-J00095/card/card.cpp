#include <bits/stdc++.h>
using namespace std;
int a[500001];
deque<int>q;
int ans[300001];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!q.empty()) {
				deque<int>tmp = q;
				int aa;
				int as = 1;
				int b = q.back();
				while (b != a[j] && !q.empty()) {
					q.pop_back();
					as++;
					if (!q.empty()) {
						b = q.back();
					}
				}
				if (q.empty()) {
					aa = -1;
				} else {
					aa = as;
				}
				q = tmp;
				if (aa != -1) {
					while (aa--) {
						q.pop_back();
					}
				}
			}
			q.push_back(a[j]);
		}
		while (!q.empty()) {
			ans[q.front()]++;
			q.pop_front();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
