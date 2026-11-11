#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[31];
long long ans = 0;
bool double1 = 0;

void dfs(vector<int> lol, int begin) {
	for (int t = begin; t >= 0; t--) {
		if (a[t].size() >= m) {
			int cnt = 0;
			vector<int> ol;
			for (int i = 0; i < a[t].size(); i++) {
				for (int j = 0; j < lol.size(); j++) {
					if (a[t][i] == lol[j]) {
						cnt++;
						ol.push_back(lol[j]);
						break;
					}
				}
			}
			if (cnt >= m) {
				if (t == 0) {
					double1++;
				}
				ans += pow(2, t);
				dfs(ol, t - 1);
			}
		}
	}
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int max1 = -1;
	cin >> n >> m;
	int list[n];
	for (int i = 0; i < n; i++) {
		cin >> list[i];
		max1 = max(max1, list[i]);
	}
	int p;
	for (int i = 0; pow(2, i) <= max1; i++) {
		p = i;
	}
	bitset<31> l;
	for (int i = 0; i < n; i++) {
		l = list[i];
		for (int j = p + 1; j >= 0; j--) {
			if (l[j] == 1) {
				a[j].push_back(list[i]);
			}
		}
	}
	long long ans = 0;
	for (int j = p + 1; j >= 0; j--) {
		if (a[j].size() >= m) {
			dfs(a[j], j - 1);
			if (double1) {
				ans--;
			}
			cout << ans + pow(2, j) << endl;
			break;
		}
	}
	return 0;
}