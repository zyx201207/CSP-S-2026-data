#include <bits/stdc++.h>
using namespace std;
int kou_zhanting [200100];
int passstation [20010][20010];
int zhanting_zhantai[20010][20010];
int tour[20010][20010];
int zhangshu[200100];
int thesamestation[200100];
int tongjithesamesation[200100];
int kaishizuobiao[20010][20010];

int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> kou_zhanting[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> zhangshu[i];
		for (int j = 1; j <= zhangshu[i]; i++) {
			cin >> passstation[i][j];
			cin >> zhanting_zhantai[i][j];
		}
	}
	for (int i = 1; i <= q; i++) {
		cin >> tour[i][1] >> tour[i][2];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= zhangshu[i]; j++) {
			tongjithesamesation[passstation[i][j]]++;
		}
	}
	int jishu = 1;
	for (int i = 1; i <= 200000; i++) {
		if (tongjithesamesation[i] >= 2) {
			thesamestation[jishu] = i;
			jishu++;
		}
	}
	int zuobiao = 1;
	for (int i = 1; i <= q; i++) {
		int kaishi = tour[i][1];
		for (int j = 1; j <= 200000; i++) {
			for (int k = 1; k <= 200000; k++) {
				if (passstation[j][k] == kaishi) {
					kaishizuobiao[zuobiao][1] = j, kaishizuobiao[zuobiao][2] = k;
					zuobiao++;
				}
			}
		}
	}
	return 0;
}
