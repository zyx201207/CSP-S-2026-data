#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int NM = 1e5 + 10, MN = 1050;
ll c, n, m, d, q, w[NM], a[MN][MN],  t[MN][MN], xr, yr, k[NM];
/* 编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数,地铁站的地铁口走
到站厅需要的时间，ai,j 表示第 i 条线路经过的第 j 个地铁站，ti,j 表示从该地铁站的站厅走到第 i 条线
路的站台需要的时间。站厅到站台的时间*/
bool f = 0;
ll ans = 9223372036854775806;

void dfs(ll y, ll x, ll sum) { //当前站台数，起始线路数
	if (y == yr) {
		ans = min(ans, sum);
		f = 1;
		return ;
	}
	for (int i = 1; i <= n; i++) { //遍历所有地铁线路
		if (i == x)
			continue;
		for (int j = 1; j <= k[i]; j++) {
			dfs(a[i][j], i, sum = sum + t[i][j]);
		}
	}

}



//ll read(){
//	int ss=0,mm=1;
//	char cc=getchar();
//	while(cc<'0'||cc>'9'){
//		if(cc=='-'){
//			mm=-1;
//		}
//		cc=getchar();
//	}
//	while(cc>='0'&&cc<='9'){
//		ss=ss*10+(cc-'0');
//		cc=getchar();
//	}
//	return ss*mm;
//}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
		}

	}
	for (int i = 1; i <= q; i++) {
		cin >> xr >> yr;
		dfs(xr, 1, w[xr]);
	}
	cout << ans << '\n';
	return 0;
}