#include <bits/stdc++.h>
using namespace std;
int n, m;
int a1[500002], t[300002], dm[300002];
set<int>se;

signed main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a1[i];
		t[a1[i]]++;
		dm[a1[i]] = i;
	}
	//cout << t[1];
	for (int i = 1; i <= m; i++) {
		for (int j = dm[i] + 1; j <= n; j++) {
			se.insert(a1[j]);
		}
		for (int j = dm[i] - 1; j >= 1; j--) {
			if (a1[j] != i && se.count(a1[j]) == 0)
				t[i]++;
		}
//		cout << i << "*";
//		for (auto it : se) {
//			cout << it << " ";
//		}
//		cout << endl;
		se.clear();
	}
	for (int i = 1; i <= m; i++) {
		cout << t[i] << " ";
	}
	return 0;
}