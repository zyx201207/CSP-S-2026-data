#include <bits/stdc++.h>
using namespace std;
int n, m, sum;
long long a[500006];
long long t[500006];
long long ans[500007];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		for (int i = 1; i <= n; i++) t[i] = 0;
		for (int j = i; j <= n; j++) {
			if (t[a[j]]) {
				while (1) {
					int cnt = q.back();
					q.pop_back();
					t[cnt]--;
					if (cnt == a[j]) break;
				}
				
			}
			q.push_back(a[j]);
			t[a[j]]++;
		}
		while (!q.empty()) {
			ans[q.front()]++;
			q.pop_front();
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
} 
