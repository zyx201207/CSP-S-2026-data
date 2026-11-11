#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;
int arr[MAXN]; stack<int> number;
bool have[MAXN]; int cnt[MAXN];

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> arr[i];
	
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j) {
			if (have[arr[j]]) 
				while (number.top() != arr[j]) {
					have[number.top()] = false;
					number.pop();
				}
			else {
				number.push(arr[j]);
				have[arr[j]] = true;
			}
		}
		while (!number.empty()) {
			cnt[number.top()]++;
			have[number.top()] = false;
			number.pop();
		}
	}
	for (int i = 1; i <= m; ++i) cout << cnt[i] << " ";
	return 0;
} 
