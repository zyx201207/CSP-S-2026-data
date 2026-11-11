#include <bits/stdc++.h>
#define File(x) (freopen(x".in", "r", stdin), freopen(x".out", "w", stdout))
#define N 1000006
#define ll long long
using namespace std;

int n;
ll d, a[N];

namespace bf {
	int dis[N], cnt[N];
	vector<int> qu[N]; int it[N], sum[N];
	void atri() {
		int ans = 0;
		for(int i=1 ; i<=n ; i++) {
			dis[i] = 0, cnt[i] = 1;
			for(int j=0 ; j<=n ; j++) qu[j] = {}, it[j] = 0, sum[j] = 0;
			qu[0].push_back(i), sum[0] = 1;
			for(int j=i+1,p=i ; j<=n ; j++) {
				while(a[p] + d < a[j]) p++;
				int q = dis[p];
				while(qu[q][it[q]] < p) sum[q] -= cnt[qu[q][it[q]++]];
				dis[j] = q + 1, cnt[j] = min(sum[q], 10);
				qu[q+1].push_back(j), sum[q+1] += cnt[j];
				if(cnt[j] == 2) ans++;
			}
		} printf("%d\n", ans);
	}
}

namespace subB {
	int dis[N], cnt[N];
	vector<int> qu[N]; int it[N], sum[N];
	void atri() {
		int ans = 0;
		for(int i=1 ; i<=n ; i++) {
			dis[i] = 0, cnt[i] = 1;
			for(int j=0 ; j<=2 ; j++) qu[j] = {}, it[j] = 0, sum[j] = 0;
			qu[0].push_back(i), sum[0] = 1;
			for(int j=i+1,p=i ; j<=n ; j++) {
				while(a[p] + d < a[j]) p++;
				int q = dis[p];
				while(qu[q][it[q]] < p) sum[q] -= cnt[qu[q][it[q]++]];
				dis[j] = q + 1, cnt[j] = min(sum[q], 10);
				qu[q+1].push_back(j), sum[q+1] += cnt[j];
				if(cnt[j] == 2) ans++;
				if(min({sum[0], sum[1], sum[2]}) > 10) break;
			}
		} printf("%d\n", ans);
	}
}

namespace subA {
	void atri() {
		if(n == 1) return void(puts("0"));
		ll cnt = d / (a[2]-a[1]);
		if(cnt <= 1) return void(puts("0"));
		printf("%lld\n", max(n-cnt*2+1, 0ll));
	}
}

int main() {
	File("migrate"), ios::sync_with_stdio(0), cin.tie(0);
	int TC, T; cin >> TC >> T;
	while(T--) {
		cin >> n >> d;
		for(int i=1 ; i<=n ; i++) cin >> a[i];
		if(TC == 11 || TC == 12) subA::atri();
		else if(TC == 13 || TC == 14) subB::atri();
		else bf::atri();
	}
	return 0;
}