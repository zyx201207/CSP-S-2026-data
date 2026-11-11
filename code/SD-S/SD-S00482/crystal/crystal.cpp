#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define fst ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

const int P = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;

const int maxn = 6e5 + 5;

int n, m;
int a[maxn];
__int128 b[maxn];

bool check(int x) {
	for (int i = x; i <= n; ++ i ) {
		if ((__int128)a[i] * x - b[i] + b[i - x] <= (__int128)m) return 1;
	}
	return 0;
}

signed main() {
//	system("fc crystal4.ans crystal.out");
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	fst;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i ) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i ) b[i] = b[i - 1] + a[i];
	int l = 1, r = n, res = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid) == 1) l = mid + 1, res = mid;
		else r = mid - 1;
	}
	cout << res;
	
	return 0;
}
