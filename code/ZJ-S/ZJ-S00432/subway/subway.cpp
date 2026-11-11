#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, k, a, qua, qub; // c 25 n 500 m 500010 d 20 q 100010
//what? Zhe ge C shi yong lai pian fen de?
long long ans;
//int tm;
//tm not tama but time
//what do you mean?
//[Error] reference to 'tm' is ambiguous
// shen le
int pa, pb;
int tmd; // time to do
int ds[500010][25], t[500010][25];
long long gtin[500010]; // getin, not GTI
long long mp[510][510];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1;i <= m;i ++){
		scanf("%lld", &gtin[i]);
	}
	for (int i = 1;i <= n;i ++){
		scanf("%d", &k);
		for (int j = 1;j <= k;j ++){
			scanf("%d%d", &a, &tmd);
			ds[a][0] ++;
			ds[a][ds[a][0]] = i;
			t[a][ds[a][0]] = tmd;
		}
	}
	memset(mp, 0x3f, sizeof(mp));
	for (int i = 1;i <= m;i ++){
		if (ds[i][0] <= 1) continue;
		for (int ja = 1;ja <= ds[i][0];ja ++){
			pa = ds[i][ja];
			for (int jb = 1;jb < ja;jb ++){
				pb = ds[i][jb];
				mp[pb][pa] = mp[pa][pb] = min(1LL * (t[i][ja] + t[i][jb]), mp[pa][pb]);
			}
		}
	}
	for (int i = 1;i <= n;i ++){
		mp[i][i] = 0;
	}
	for (int _ = 1; _ <= n; _ ++){
		for (int i = 1; i <= n; i ++){
			for (int j = 1;j <= n; j ++){
				mp[i][j] = min(mp[i][j], mp[i][_] + mp[_][j]);
			}
		}
	}
	for (int i = 1;i <= q;i ++){
		scanf("%d%d", &qua, &qub);
		ans = mp[ds[qua][1]][ds[qub][1]] + 1LL * (t[qua][1] + t[qub][1]);
		for (int j = 1;j <= ds[qua][0];j ++){
			pa = ds[qua][j];
			if (t[qua][j] > ans) continue;
			for (int jd = 1;jd <= ds[qub][0]; jd ++){
				pb = ds[qub][jd];
				ans = min(ans, mp[pa][pb] + 1LL * (t[qua][j] + t[qub][jd]));
			}
		}
		ans += gtin[qua] + gtin[qub];
		printf("%lld\n", ans);
	}
	return 0;
}
// no shit
// how to even you hua this?
// isn't every caculation necessary?
// WHY???
