#include <bits/stdc++.h>
using namespace std;

struct Point {
	int index, x;
	bool vis = false;
	vector<int> v;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mirgate.in", "r", stdin);
	freopen("mirgate.out", "w", stdout);
	int c, T;
	cin >> c >> T;

	while (T--) {
		int n, d;
		vector<Point> p;

		cin >> n >> d;
		for (int i = 0; i < n; i++) {
			Point t;
			t.index = i;
			cin >> t.x;
			p.push_back(t);
		}

		int ans = 0;
		for (auto &a : p) {
			vector<int> fir, sec;
			if (!a.vis) {
				int dx[100];
				int deltaX;
				for (int i = 0; i < 50; i++) {
					dx[50 + i] = i + 1;
					dx[i] = -i;
				}
				for (int i = 0; i < 100; i++) {
					if (a.index + dx[i] >= 0 && a.index + dx[i] <= (int)p.size()) {
						(p[a.index + dx[i]].x > a.x) ? deltaX = p[a.index + dx[i]].x - a.x
						                                        : deltaX = a.x - p[a.index + dx[i]].x;
						if (deltaX <= d) {
							a.v.push_back(a.index + dx[i]);
						}
					}
				}
				a.vis = true;
			}
			for (auto &tmp : a.v) {
				fir.push_back(tmp);
			}

			for (auto &t : fir) {
				if (!p[t].vis) {
					int dx[100];
					for (int i = 0; i < 50; i++) {
						dx[50 + i] = i + 1;
						dx[i] = -i;
					}
					int deltaX;
					for (int i = 0; i < 100; i++) {
						if (p[t].index + dx[i] >= 0 && p[t].index + dx[i] <= (int)p.size()) {
							(p[p[t].index + dx[i]].x > p[t].x) ? deltaX = p[p[t].index + dx[i]].x - p[t].x
							        : deltaX = p[t].x - p[p[t].index + dx[i]].x;
							if (deltaX <= d) {
								p[t].v.push_back(p[t].index + dx[i]);
							}
						}
					}
					p[t].vis = true;
				}
				for (auto &tmp : p[t].v) {
					bool tmpp = true;
					for (auto &tm : fir) {
						if (tm == tmp || tmp == a.index)
							tmpp = false;
					}
					if (tmpp) {
						sec.push_back(tmp);
					}
				}
			}
			sort(sec.begin(), sec.end());
			int last = -1;
			for (auto &t : sec) {
				if (last == t && a.index < t) {
					ans ++;
				}
				last = t;
			}
		}
		cout << ans << endl;
	}
	return 0;
}