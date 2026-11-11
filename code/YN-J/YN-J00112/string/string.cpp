#include <bits/stdc++.h>
using namespace std;
int n;
int  x;
char y;

struct node {
	int  a;
	char c;
};
vector<node> v;
vector<node> v2;
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> x >> y;
		v.push_back({x, y});
	}

	while (v.size() != 1 && v.size() != 0) {
		int g = min(v.front().a, v.back().a);

		if (v.front().c != v.back().c) {
			ans += g;
		}

		v.front().a -= g, v.back().a -= g;

		for (int i = 0; i < v.size(); i++) {

			if (v[i].a != 0) {
				v2.push_back(v[i]);
			}
		}

		v.clear();

		for (auto u : v2) {
			v.push_back(u);
		}

		v2.clear();
	}

	cout << ans;
	return 0;
}