#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;
long long n, a, ans;
char c;
pair<long long, char> p[N];
signed main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a >> c;
		p[i] = {a, c};
	}
	int i = 1, j = n;
	while (i < j) {
		if (p[i].second == p[j].second) {
			if (p[i].first > p[j].first) {
				p[i].first -= p[j].first;
				j--;
			} else if (p[i].first < p[j].first){
				p[j].first -= p[i].first;
				i++;
			} else {
				i++;
				j--;
			}
		} else {
			if (p[i].first > p[j].first) {
				ans += p[j].first;
				p[i].first -= p[j].first;
				j--;
			} else if (p[i].first < p[j].first) {
				ans += p[i].first;
				p[j].first -= p[i].first;
				i++;
			} else {
				ans += p[i].first;
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}

