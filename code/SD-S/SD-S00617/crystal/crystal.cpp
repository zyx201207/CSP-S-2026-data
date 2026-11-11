#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp(Tx, Ty) make_pair(Tx, Ty)
#define For(Ti, Ta, Tb) for(auto Ti = (Ta); Ti <= (Tb); Ti++)
#define Dec(Ti, Ta, Tb) for(auto Ti = (Ta); Ti >= (Tb); Ti--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define range(Tx) begin(Tx),end(Tx)
typedef long long ll;
const int N = 5e5 + 5;
int n;
ll m, a[N], pre[N];
int main() {
	assert(freopen("crystal.in", "r", stdin));
	assert(freopen("crystal.out", "w", stdout));
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	For(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	For(i, 1, n) pre[i] = pre[i - 1] + a[i];
	int l = 1;
	int ans = 0;
	For(i, 1, n) {
		while (l <= i && 1ll * (i - l + 1) * a[i] - (pre[i] - pre[l - 1]) > m) l++;
		ans = max(ans, i - l + 1);
	}
	cout << ans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
