#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
const int MAXK = 5 * 1e5 + 5 - 10000;
const int MAXQ = 1e5 - 10000;
int w[MAXN];
int t[MAXN][MAXK];
int a[MAXN][MAXK];
int x[MAXQ];
int y[MAXQ];
int c, n, m, d, q, zong;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;// 测试点编号，地铁线路数，地铁站数、每个地铁站最多被几条线路经过 
	for(int i = 1;i <= m; ++i) {
		cin >> w[i];
	}	
	for(int i = 1;i <= n; ++i) {
		int ki;
		cin >> ki;
		for(int j = 1;j <= ki; ++j) {
			cin >> a[i][j] >> t[i][j + i - 1];
		}
	}
	for(int i = 1;i <= q; ++i) {
		cin >> x[i] >> y[i];	
	}
	for(int i = 1;i <= q; ++i) {
		zong = w[x[i]] + w[y[i]];
		for(int j = x[i];j <= y[i] - 1; ++j) {
			zong += t[j][j] + t[j][j + 1];
		}
		cout << zong << endl;
		zong = 0;
	} 
	return 0;
}