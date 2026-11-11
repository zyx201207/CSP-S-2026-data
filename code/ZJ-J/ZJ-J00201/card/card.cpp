#include<bits/stdc++.h>
using namespace std;
int n, m, a[500010], la, ans[300010];
bool ss[300010];
stack<int> s;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	if (m == 1) {
		cout << (n + 1) / 2;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if(ss[a[j]]) {
				ss[a[j]] = false;
				while(!s.empty()) {
					if(s.top() == a[j]) {
						s.pop();
						break;
					}
					ss[s.top()] = false;
					s.pop();
				}
			}
			s.push(a[j]);
			ss[a[j]] = true;
		}
		for (int j = 1; j <= m; j++) {
			if (ss[j]) {
				ss[j] = false;
				ans[j]++;
			}
		}
		while(!s.empty()) s.pop();
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
