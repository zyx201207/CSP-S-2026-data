#include <bits/stdc++.h>
using namespace std;

int c;//测试点编号
int n;//地铁线路数
int m;//地铁站数
int d;//最多经过的路线
int p;//出行计划数

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> p;
	vector<int>w(m);//口到站厅

	for (int i = 0; i < m; i++) {

		cin >> w[i];
	}

	int num = 0;

	while (n--) {
		int money = 0;
		int k;//i路地铁站数
		cin >> k;
		vector<int>a(2 * k);

		for (int i = 0; i < 2 * k; i++) {

			cin >> a[i];

			num += a[i];
		}

		int x, y;
		cin >> x >> y;

	}

	cout << num;
	return 0;
}
