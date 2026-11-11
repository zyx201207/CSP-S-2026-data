#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 10;
int a[N], ans, n, m, vis[N];

inline int get_sum(int x) {
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (vis[i]) continue;
		if (a[i] & (1 << x)) ++cnt;
	}
	return cnt;
}

inline void upd(int x) {
	for (int i = 1; i <= n; ++i) {
		if (!(a[i] & (1 << x))) {
			vis[i] = 1;
		}
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 30; i >= 0; --i) {
		int num = get_sum(i);
		if(num >= m) {
			upd(i);
			ans += (1 << i);
		}
	}
	cout << ans;
	return 0;
}
