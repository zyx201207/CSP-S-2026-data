#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int KmaxN = 5e5 + 5;

int ct, _;
int n, k;
bool in[KmaxN];
int dist[KmaxN];
vector<int> v[KmaxN];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) v[i].clear();
	for (int i = 1, a, b; i < n; i++) {
		scanf("%d%d", &a, &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	if (n == k) {
		printf("0\n");
		return ;
	}
	if (ct == 13 || ct == 14) {
		int ans = n;
		int zh = (n + 1) / 2;
		if (k == 1) {
			printf("%d\n", n / 2);
			return ;
		}
		
		int l = 1, r = n / 2;
		for (int mid; l <= r; ) {
			mid = (l + r) >> 1;
			int ma = mid - 1 + k + mid * 2 + mid - 1;
			if (ma >= n) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%d\n", ans);
		return ;
	}
	int up = (1 << n);
	int ans = n;
	for (int i = 1; i < up; i++) {
		if (__builtin_popcount(i) != k) continue;
		int x = i;
		for (int j = 1; j <= n; j++, x >>= 1) {
			if (x & 1) in[j] = true;
			else in[j] = false;
		}
		int maa = 0;
		for (int j = 1; j <= n; j++) {
			if (in[j]) continue;
			for (int l = 1; l <= n; l++) dist[l] = 0;
			dist[j] = 1;
			queue<int> q;
			q.emplace(j);
			for (; !q.empty();) {
				int x = q.front(); q.pop();
				for (int y : v[x]) {
					if (dist[y]) continue;
					dist[y] = dist[x] + 1;
					q.emplace(y);
				}
			}
			int ma = n;
			for (int l = 1; l <= n; l++) {
				if (in[l]) ma = min(ma, dist[l] - 1);
			}
			maa = max(maa, ma);
		}
		ans = min(ans, maa);
	}
	printf("%d\n", ans);
}

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d", &ct, &_);
	for (; _--; solve());
	return 0;
}
/*
hub
*/
