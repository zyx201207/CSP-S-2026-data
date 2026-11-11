#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> vec(n);
	vector<int> ans(m + 1);
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	for (int i = 0; i < n; i++) {
		string p;
		for (int j = i; j < n; j++) {
			if (p.find(vec[j]) != -1)
				p.erase(p.begin() + p.find(vec[j]), p.end());
			p.push_back(vec[j]);
		}
		for (int i = 0; i < p.size(); i++)
			ans[p[i]] += 1;
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}