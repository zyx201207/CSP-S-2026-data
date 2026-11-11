#include <bits/stdc++.h>
#define ll long long
#define PLI pair<ll, int>

using namespace std;

const int KmaxN = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int ct, _;
int n; ll d;
ll a[KmaxN];
bool vis[KmaxN];
int cnt[KmaxN];
ll f[KmaxN];

void solve() {
	scanf("%d%lld", &n, &d);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		priority_queue<PLI, vector<PLI>, greater<PLI> > q;
		q.emplace(a[i], i);
		for (int j = i + 1; j <= n; j++) f[j] = inf, cnt[i] = 0, vis[i] = false;
		f[i] = 0;
		for (; !q.empty();) {
			int x = q.top().second; q.pop();
			for (int j = x + 1; j <= n; j++) {
				if (a[j] - a[x] > d) break;
				if (f[j] > f[x] + 1) {
					f[j] = f[x] + 1;
					cnt[j] = 1;
					q.emplace(a[j], j);
				}
				else if (f[j] == f[x] + 1) cnt[j]++;
			}
		}
		for (int j = i + 1; j <= n; j++) {
			if (cnt[j] == 2) ans++;
		}
	}
	printf("%lld\n", ans);
	return ;
}

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d", &ct, &_);
	for (; _--; solve());
	return 0;
}
/*
migrate
*/
