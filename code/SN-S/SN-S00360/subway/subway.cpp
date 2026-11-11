// 张睿航 SN-S00360 西安市第六中学 
#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
int zhc;
int zhn, zhm;
int zhd, zhq;
//vector<pii> zhe[500005];
vector<pii> zhnode[500005];
int zhdis[505][500005];
int zha[500005];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(zhdis, 0x3f3f3f3f, sizeof(zhdis));
	cin >> zhc;
	cin >> zhn >> zhm >> zhd >> zhq;
	for(int i = 1; i <= zhm; i ++) {
		cin >> zha[i];
		zhdis[i][i] = 0;
	}
	for(int i = 1; i <= zhn; i ++) {
		int len;
		cin >> len;
		int lv, lw;
		for(int j = 1; j <= len; j ++) {
			int v, w;
			cin >> v >> w;
			for(pii vv : zhnode[v]) {
				int u = vv.first, ww = vv.second;
//				zhe[v].push_back(make_pair(u, ww + w));
//				zhe[u].push_back(make_pair(v, ww + w));
				zhdis[u][v] = zhdis[v][u] = ww + w;
			}
			zhnode[v].push_back(make_pair(i, w));
			if(j > 1) {
//				zhe[lv].push_back(make_pair(v, 0));
//				zhe[v].push_back(make_pair(lv, 0));
				zhdis[v][lv] = zhdis[lv][v] = 0;
			}
			lv = v;
			lw = w;
		}
	}
	for(int k = 1; k <= zhm; k ++) {
		for(int i = 1; i <= zhm; i ++) {
			for(int j = 1; j <= zhm; j ++) {
				zhdis[i][j] = min(zhdis[i][j], zhdis[i][k] + zhdis[k][j]);
			}
		}
	}
	while(zhq --) {
		int u, v;
		cin >> u >> v;
		cout << zhdis[u][v] + zha[u] + zha[v] << '\n';
	}
	return 0;
}
