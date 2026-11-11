#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	
	vector<int> cnt(m + 1, 0);
	for (int i = 0; i < n; i++) {
		deque<int> table;
		for (int j = i; j < n; j++) {
			if (find(table.begin(), table.end(), a[j]) != table.end()) {
				while(!table.empty() && table.back() != a[j]) table.pop_back();
			} 
			else table.push_back(a[j]);
		}
		for (int j = 0; j < table.size(); j++) {
			cnt[table[j]]++;
		}
	}
	
	for (int i = 1; i <= m; i++) {
		cout << cnt[i] << " ";
	}
	
	return 0;
}
