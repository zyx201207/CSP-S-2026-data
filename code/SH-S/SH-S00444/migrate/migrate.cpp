# include <iostream>
# include <algorithm>
# include <cstdio>
# include <queue>
# include <vector>
# include <map>
# include <cstring>

typedef long long LL;
const int NR = 2e6 + 10;
int N, C, T;
LL dmax, ans;
LL a[NR], dis[1010][1010];
int to[NR], cnt0[NR], cnt2[NR], cnt3[NR];

void init() {
	ans = 0;
	memset(a, 0, sizeof a);
	memset(to, 0, sizeof to);
	memset(cnt0, 0, sizeof cnt0);
	memset(cnt2, 0, sizeof cnt2);
	memset(cnt3, 0, sizeof cnt3);
	memset(dis, 0x3f, sizeof dis);
	if (N <= 1000) {
		for (int i = 1; i <= N; i++) dis[i][i] = 0;
	}
}

void solve1();
void solve2();

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%d%d", &C, &T);
	if (C == 11 || C == 12) {
		solve1();
		return 0;
	}
	solve2();
	return 0;
	while (T--) {
		scanf("%d%lld", &N, &dmax);
		init();
		for (int i = 1; i <= N; i++) {
			scanf("%lld", a + i);
		}
		for (int i = 1; i < N; i++) {
			to[i] = std::lower_bound(a + 1, a + 1 + N, a[i] + dmax) - a;
			if (to[i] > N) to[i] = N;
			while (a[to[i]] - a[i] > dmax) to[i]--;
			to[i] -= i;
		}
		
		
		
//		for (int i = 1; i <= N; i++) std::cout << to[i] << " ";
//		std::cout << std::endl;
		/*
		for (int i = 1; i <= N; i++) {
			cnt0[i] = cnt0[i - 1] + (to[i] == 0);
			cnt2[i] = cnt2[i - 1] + (to[i] == 2);
			cnt3[i] = cnt3[i - 1] + (to[i] >= 3);
		}
		for (int l = 1; l < N; l++) {
			for (int r = l + 1; r <= N; r++) {
				if (	cnt0[r - 1] == cnt0[l - 1] &&
					cnt2[r - 1] == cnt2[l - 1] + 2 &&
					cnt2[r - 2] == cnt2[r - 1] &&
			  		cnt3[r - 1] == cnt3[l - 1] ) {
//					std::cout << "l - r : " << l << " - "<< r << " "  << cnt0[r - 1] << " " << cnt2[r - 1] << std::endl;
					ans++;
				}
			}
		}
		printf("%lld\n", ans);
		*/
	}
	return 0;
}

void solve2() {
	while (T--) {
		scanf("%d%lld", &N, &dmax);
		init();
		for (int i = 1; i <= N; i++) {
			scanf("%lld", a + i);
		}
		for (int i = 1; i < N; i++) {
			to[i] = std::lower_bound(a + 1, a + 1 + N, a[i] + dmax) - a;
			if (to[i] > N) to[i] = N;
			while (a[to[i]] - a[i] > dmax) to[i]--;
			to[i] -= i;
		}
		for (int l = N; l >= 1; l--) {
			int cnt = 1, far = l + to[l];
			for (int r = l + 1; r <= N; r++) {
				if (r <= far) dis[l][r] = cnt;
				else {
					cnt++;
				
					if (to[far] == 0) break;
					dis[l][r] = cnt;
					far += to[far];
				}
//				std::cout << l << " " << r << " : " << dis[l][r] << std::endl;
			}
		}
		for (int l = 1; l < N; l++) {
			for (int r = l + 1; r <= N; r++) {
				int cnt = 0;
				for (int k = l + 1; k < r; k++) {
					if (dis[l][k] + dis[k][r] == dis[l][r]) cnt++;
				}
				if (cnt == 2) ans++;
			}
		}
		printf("%lld\n", ans);
	}
}

void solve1() {
	while (T--) {
		scanf("%d%lld", &N, &dmax);
		init();
		for (int i = 1; i <= N; i++) {
			scanf("%lld", a + i);
		}
		LL gap = dmax / ((LL)(a[2] - a[1]));
		if (gap == 0LL || gap == 1LL) puts("0");
		else {
			gap = gap * 2LL - 1LL;
			printf("%d\n", std::max(0, N - (int)(gap)));
		}
	}
}
