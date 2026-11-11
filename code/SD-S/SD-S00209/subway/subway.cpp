#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;

const int M = 5e5 + 10;
int w[M], _t[M];
std::vector<std::pair<int, int> > vec[505];
std::vector<int> _1_2_, _2_3_, _1_3_; 
std::vector<int> lne[M];

int main() {
	std::cin.tie(0) -> sync_with_stdio(false);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	std::cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		std::cin >> w[M];
	}
	
	for (int i = 1; i <= n; i++) {
		int k;
		std::cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			std::cin >> a >> t;
			vec[i].emplace_back(a, t);
			_t[a] = t;
			lne[a].push_back(i);
		}
	}
	
	for (int i = 1; i <= m; i++) {
		std::sort(lne[i].begin(), lne[i].end());
	}
	
	if (n >= 2) {
		for (int i = 1; i <= m; i++) {
			if (lne[i].size() >= 2 && lne[i][0] == 1 && lne[i][0] == 2) {
				_1_2_.push_back(i);
			}
		}
		if (n >= 3) {
			for (int i = 1; i <= m; i++) {
				if (lne[i].size() == 2 && lne[i][0] == 1 && lne[i][1] == 3 ||
					lne[i].size() == 3 && lne[i][0] == 1 && lne[i][2] == 3) {
					_1_3_.push_back(i);
				}
			}
			
			for (int i = 1; i <= m; i++) {
				if (lne[i].size() == 2 && lne[i][0] == 2 && lne[i][1] == 3 ||
					lne[i].size() == 3 && lne[i][1] == 2 && lne[i][2] == 3) {
					_2_3_.push_back(i);
				}
			}
		}
	}
	
	if (n == 1) {
		for (int i = 1; i <= q; i++) {
			int x, y;
			std::cin >> x >> y;
			std::cout << w[x] + w[y] +  _t[x] + _t[y] << endl;
		}
	}
	return 0;
}
