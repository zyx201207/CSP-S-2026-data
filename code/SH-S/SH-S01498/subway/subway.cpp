#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[600005], a[605][25];
vector<int> station[600005];
vector<int> line[605];
bool ifline[605];
long long ans;

void dfs(long long nowsta, long long tme, long long yr) {
	if (nowsta == yr) {
		ans = min(ans, tme + w[yr]);
		return;
	}
	for (int i = 0; i < station[nowsta].size(); i++) {
		int nowlne = station[nowsta][i]; // 在当前站选择乘坐的线路
		if (ifline[nowlne]) {
			continue; //到该站台已经坐过该线路 
		} 
		int changetme = a[nowlne][nowsta]; //当前站厅到该线时间 
		for (int j = 0; j < line[nowlne].size(); j++) {//该线路能到达的站 
			if (station[line[nowlne][j]].size() == 1 && line[nowlne][j] != yr) {
				continue;// 若遍历线路中的某一站线路为1且不为终点站，则不必要进行dfs 
			} 
			else {
				ifline[nowlne] = 1;
				dfs(line[nowlne][j], tme + a[nowlne][line[nowlne][j]] + changetme, yr);
				ifline[nowlne] = 0;
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) { //i = 线路 
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int sta, tme;
			cin >> sta >> tme; 
			a[i][sta] = tme;
			station[sta].push_back(i);
			line[i].push_back(sta);
		}
	}
	for (int i = 1; i <= q; i++) {
		ans = LONG_LONG_MAX;
		int xr, yr;
		cin >> xr >> yr;
		dfs(xr, w[xr], yr);
		cout << ans << endl;
	}
	
}
