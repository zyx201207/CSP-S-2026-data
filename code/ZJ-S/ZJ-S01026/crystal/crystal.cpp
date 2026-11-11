#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
#define pii pair< int, int >
#define pll pair< ll, ll >

const int N = 5e5 + 10;

int n;
ll m;
ll a[N], sum[N];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1, greater< ll >());
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	int res = 0;
	for (int i = 1, j = 1; i <= n; i ++) {
		while (j <= n && (j - i + 1) * a[i] - (sum[j] - sum[i - 1]) <= m) j ++;
		res = max(res, j - i);
	}
	cout << res << '\n';
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	clock_t st = clock();
	
	int T = 1;
//	cin >> T;
	while (T --) solve();
	
	clock_t ed = clock();
	cerr << "time:" << (ed - st) / CLOCKS_PER_SEC << "s" << '\n';
	return 0;
}