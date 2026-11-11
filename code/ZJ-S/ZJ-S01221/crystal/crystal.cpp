#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

namespace Yukari {

const int N = 5e5 + 10;
int n; ll m, A[N], sum[N];

bool check(int l, int r) {
	return m >= A[r] * (r - l + 1) - (sum[r] - sum[l - 1]);
}

void Main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> A[i];
	sort(A + 1, A + 1 + n);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + A[i];
	int ans = 0;
	for (int r = 1, l = 1; r <= n; r ++) {
		while (l < r && !check(l, r)) ++ l;
		ans = max(ans, r - l + 1);
	}
	cout << ans << "\n";
	return ;
}

}

int main() {
	freopen("crystal.in", "r", stdin); freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	Yukari::Main();
	return 0;
}