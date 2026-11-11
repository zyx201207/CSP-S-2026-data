#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, ans;
priority_queue<int> table;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	ans.assign(m + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < 3; j++) {
			table.push(j);
		}
		for (int j = 0; j < table.size(); j++) {
			ans[table.top() - 1]++;
			table.pop();
		}
	}
	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}