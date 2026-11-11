#include <bits/stdc++.h>
using namespace std;
deque<int>q;
int ans[300005];
int a[500005];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) { //yxjs
		for (int j = i; j <= n; j++) { //djqk
			q.push_back(a[j]);
			for (int k = 1; k < q.size(); k++) { //czcf
				if (q.back() == q[k]) {
					for (int l = k; l <= q.size(); l++) {
						q.pop_back();
					}
					break;
				}
			}
		}
		for (int j = 0; j < q.size();) { //tj
			ans[q.back()]++;
			q.pop_back();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}