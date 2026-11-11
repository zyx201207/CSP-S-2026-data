#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N = 500005;

int n;
ll m, ans, a[N], sum[N]; 


ll calc(int pos, ll x) {
	int l = 0, r = pos + 1;
	while(l + 1 < r) {
		int mid = (l + r) / 2;
		if(x * (pos - mid + 1) - (sum[pos] - sum[mid - 1]) <= m) r = mid;
		else l = mid;
	}
	return pos - r + 1;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for(int i = 2; i <= n; i++) {
		ll cur = calc(i - 1, a[i]) + 1;
		ans = max(ans, cur);
//		cout << cur << endl;
	}
	cout << ans;
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
