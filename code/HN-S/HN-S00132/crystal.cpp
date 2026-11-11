#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 5e5 + 55;

int n;
ll m;
ll a[MAXN];
ll sum[MAXN];

bool check(int mid) {
	for(int i = mid; i <= n; i++) {
		if(a[i] * mid - (sum[i] - sum[i - mid]) <= m)return 1;
	}
	return 0;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
		cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
	    sum[i] = sum[i - 1] + a[i];
    }
    int ans = 0;
    for(int L = 1, R = n, mid; L <= R;) {
		mid = L + R >> 1;
		if(check(mid)) {
			L = mid + 1;
			ans = mid;
		} else{
			R = mid - 1;
		}
    }
    cout << ans;
    return 0;
}
