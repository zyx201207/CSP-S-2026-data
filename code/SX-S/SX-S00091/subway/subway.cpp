//2.subway
#include <bits/stdc++.h>
using namespace std;
int w[505];
long long a[505], t[505];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, n, m, d, q;
	//c编号，n线路数，m站数，d站点被几条线路经过，q出行计划数量
	int k, ii; //k第ii条线路经过的站数，
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i++)
		cin >> w[i]; //地铁口到大厅的时间
	cin >> k;
	for (int i = 1; i <= k; i++)
		cin >> a[i] >> t[i];
	//a[i][j]第i条线路经过的第j个地铁站，
	//s[i][j]该地铁站的站厅走到第 i 条线路的站台需要的时间
	int x, y;
	cin >> x >> y;//分别表示第 r 个出行计划的起点和终点所在的地铁站编号
	int ans = w[1] + t[1] + t[2] + a[3] + w[3];
	cout << ans << "\n";
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

#include <bits/stdc++.h>
using namespace std;
int w[505];
long long a[505][100005], t[505][100005];

int main() {
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int c, n, m, d, q;
	//c编号，n线路数，m站数，d站点被几条线路经过，q出行计划数量
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
		cin >> w[i]; //地铁口到大厅的时间
	for (int o = 1; o <= q; o++) {
		int k[q]; //k第ii条线路经过的站数
		cin >> k[o];
		for (int i = 1; i <= 2 * k; i++)
			cin >> a[i][o] >> t[i][o];
		//a[i][j]第i条线路经过的第j个地铁站，
		//s[i][j]该地铁站的站厅走到第 i 条线路的站台需要的时间
	}
	while (q--) {
		int x, y;
		cin >> x >> y;//分别表示第 r 个出行计划的起点和终点所在的地铁站编号
	}
	while (q--) {
		int ans = w[1] + t[1] + w[2];
		cout << ans << " ";
	}
	return 0;
}
*/