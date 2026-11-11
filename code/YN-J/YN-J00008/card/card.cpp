#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pir;
const int maxn = 5e5 + 10;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>a(n + 1, 0);
	vector<int>g(m + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int cnt = 1; cnt <= n; cnt ++) {
		vector<int>kind(m + 1, 0);
		vector<int>temp;
		for (int i = cnt; i <= n; i++) {
			if (kind[a[i]] && !temp.empty()) {
				while (temp.back() != a[i]) {
					kind[temp.back()]--;
					temp.pop_back();
				}
				kind[temp.back()]--;
				temp.pop_back();
			}
			temp.push_back(a[i]);
			kind[temp.back()]++;
		}
		for (int i = 1; i <= m; i++) {
			if (kind[i]) {
				g[i]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << g[i] << ' ';
	}
	cout << '\n';
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	solve();
	return 0;
}