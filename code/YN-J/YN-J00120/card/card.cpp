#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[300001];
int n, m;
vector<int>b;
set<int>s;
map<int, int>mp;

signed main() {
	freopen("card.in", "r", "stdin");
	freopen("card.out", "w", "stdout");
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int p = 0; p < n; ++p) {
		b.clear();
		s.clear();
		for (int i = p; i < n; ++i) {
			if (s.count(a[i + 1]) == 0) {
				s.insert(a[i + 1]);
				b.push_back(a[i + 1]);
			} else {
				int wz = 0;
				int pp = 0;
				for (auto k : s) {
					if (b[pp] == k) {
						wz = pp;
						break;
					} else {
						pp++;
					}
				}
				for (int j = wz; j < b.size(); j++) {
					s.erase(b[j]);
					b[j] = 0;
				}
				b.push_back(a[i + 1]);
			}
		}
		for (auto i : b) {
			if (i == 0) {
				continue;
			}
			mp[i]++;
		}
	}
	for (auto i : mp) {
		cout << i.second << " ";
	}
	return 0;
}