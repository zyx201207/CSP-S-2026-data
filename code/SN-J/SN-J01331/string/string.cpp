#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;

int p, n, a[N];
ll lt, rt, ans, res, len = 0, L[N], R[N];
char c[N]; 
int main() {
	freopen("string.in", "r", stdin); freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n; p = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		L[i] = len + 1;
		len += a[i];
		R[i] = len;
	}
	ll mid = len >> 1;
	for (int i = 1; i <= n; i++) {
		if (L[i] > mid) break;
		
		if (R[i] <= mid) lt = len + 1 - R[i];
		else lt = mid + 1;
		rt = len + 1 - L[i];
		res = 0;
		while (true) {
			if (c[p] != c[i]) {
				if (R[p] > rt && L[p] >= lt) res += rt - L[p] + 1;
				else if (lt <= L[p] && R[p] <= rt) res += R[p] - L[p] + 1;
				else if (L[p] < lt && R[p] <= rt) res += R[p] - lt + 1;
				else if (L[p] < lt && R[p] > rt) res += rt - lt + 1;
			}
			if (L[p] < lt) break;
			p--;
		}
		ans += res;
	}
	cout << ans;
	return 0;
}

