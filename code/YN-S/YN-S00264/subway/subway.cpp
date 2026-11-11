/*
t2 subway
 m 个地铁站，编号为 1 到 m。
每个地铁站都有一个站厅，
地铁口与站厅之间有一条通道往返耗时相同。
第 v (1 ≤ v ≤ m) 个地铁站的地铁口走到站厅需要wv 的时间。
 n 条地铁线路
第 i (1 ≤ i ≤ n) 条线路经过 ki 个地铁站
依次为 ai,1, ai,2, . . . , ai,ki。
第 ai,j (1 ≤ j ≤ ki) 个地铁站处，
从站厅走到第 i条线路的站台需要 ti,j 的时间，往返耗时相同
即 ai,1, ai,2, . . . , ai,ki 两两不同。
每个地铁站最多有 d 条线路经过。
任意两个地铁站都可以通过若干条线路互相到达。
 q 个出行计划。
 第 r (1 ≤ r ≤ q) 个出行计划，
 从第 xr 个地铁站的地铁口出发
 到达第 yr 个地铁站的地铁口
 途中可能进行若干次站内换乘
 每次站内换乘都需要从一条线路的站台先走到站厅
 再从站厅走到另一条线路的站台
 每个出行计划的总步行时间为进出站和换乘的步行时间之和
 Q:最小总步行时间。
 n<=500 m<=5e5,d<=20
 16:27 exc AC
 Debug for 40min for 下标越界 beng dezhu ma ?
*/
#include <bits/stdc++.h>
using namespace std;
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
#define _rfo(i, a, b) for(int i = (a); i >= (b); --i)
using LL = long long;
using VI = vector<int>;
const int NN = 505, MM = 5E5 + 5;
LL W[MM], D[NN][NN], T[MM][22];
int P[MM][22], Cnt[MM];
const LL INF = 1e18;
bool F[MM];

void solve() {
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	_for(i, 1, m) cin >> W[i];
	memset(D, 0X3F, sizeof(D)), memset(Cnt, 0, sizeof(Cnt));
	_for(i, 1, n) {
		int k;
		cin >> k;
		_for(j, 1, k) {
			LL a, t;
			cin >> a >> t;
			if (!F[a]) {
				F[a] = 1, assert(Cnt[a] == 0);

			}
			int id = ++Cnt[a];
			P[a][id] = i, T[a][id] = t;
			/*if (id > d) {
				cout << Cnt[a] << "\n";
				_for(j, 1, id) cout << P[a][j] << " ";
			}
			assert(id <= d);*/
//			assert(T[a][Cnt[a]] == Lst);
		}/*
		_for(i, 1, m) _for(j, 1, Cnt[i]) {
			if (T[i][j] != Lst)
				cout << Lst << " " << T[i][j] << " " << j << " " << Cnt[i] << "\n";
//			assert(Lst == T[i][j]);

	}*/
	}
	_for(i, 1, n) D[i][i] = 0;

	_for(i, 1, m) {
		auto &p = P[i];
		auto &t = T[i];
		int cn = Cnt[i];
		/*		cout << "P" << i << "\n";
				_for(j, 1, Cnt[i]) cout << p[j] << " " << t[j] << "-";
				cout << "\n";*/
		_for(j, 1, cn) _for(k, j + 1, cn)
		D[p[k]][p[j]] = D[p[j]][p[k]] = min(D[p[k]][p[j]], t[k] + t[j]);
	}
	/*	_for(i, 1, n) {
			_for(j, 1, n) cout << D[i][j] << " ";
			cout << "\n";
		}*/
	_for(k, 1, n) _for(i, 1, n) _for(j, i + 1, n)
	D[i][j] = D[j][i] = min(D[i][k] + D[k][j], D[i][j]);

	while (q--) {
		int x, y;
		cin >> x >> y;
		LL ans = INF;
		_for(i, 1, Cnt[x]) _for(j, 1, Cnt[y])
		ans = min(ans, T[x][i] + T[y][j] + D[P[x][i]][P[y][j]]);
		cout << ans + W[x] + W[y] << "\n";
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while (T--)
		solve();
	return 0;
}