#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;
int T;
int w[500005];
vector <int> l[500005];
int mp[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 1; j <= x; j++) {
			int y, z;
			cin >> y >> z;
			T = z;
			l[i].push_back(y);
		}
	}
	for (int i = 1; i <= q; i++) {
		int mn = INT_MAX;
		int x, y;
		cin >> x >> y;
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < l[j].size(); k++) {
				if (l[j][k] == x) {
					for (int k1 = 0; k1 < l[j].size(); k1++) {
						if (l[j][k1] != x) {
							if (mp[l[j][k1]])
								mp[l[j][k1]] = min(mp[l[j][k1]], 2 * T + w[x] + w[l[j][k1]]);
							else
								mp[l[j][k1]] =  2 * T + w[x] + w[l[j][k1]];
						}
					}
				}
				if (mp[l[j][k]]) {
					for (int k1 = 0; k1 < l[j].size(); k1++) {
						if (l[j][k1] != l[j][k]) {
							if (mp[l[j][k1]])
								mp[l[j][k1]] = min(mp[l[j][k1]], 2 * T + w[l[j][k]] + w[l[j][k1]] + mp[l[j][k]]);
							else
								mp[l[j][k1]] =  2 * T + w[l[j][k]] + w[l[j][k1]] + mp[l[j][k]];
						}
					}
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			if (mp[j])
				mn = min(mn, mp[j]);
			mp[j] = 0;
		}
		cout << mn << endl;
	}
	return 0;
}

/* 做的稀烂啊

有所几千人的学校就一个人来比赛，你知道它是谁

63699

机灯叶刺刺(316)

瓜魅猫吸草(320)

牛肉脯好吃呢

初中要结束了，还是写不出第一个题QAQ

2023梦碎cspj初赛

2024梦碎cspj一等奖(205<210)

2025梦碎cspjAK

2025梦碎csps二等奖(j组330+ s组20的来了)

2026梦碎cspjAK(起码大概对三个，比2025两题骗130舒服)

2026? ? csps

成祝了，还以为6点结束（
*/