#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5 , inf = 0x3f3f3f3f;
int n;
ll m , a[N] , b[N] , pre[N];
bool check(int x) {
	ll now = 1e18;
	for(int i = 1 ; i + x - 1 <= n ; i ++) {
		int j = i + x - 1;
		now = min(now , x * a[j] - (pre[j] - pre[i - 1]));
	}
	return now <= m;
}
int main() {
	freopen("crystal.in" , "r" , stdin) , freopen("crystal.out" , "w" , stdout);
	ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++) cin >> a[i];
	sort(a + 1 , a + n + 1);
	for(int i = 1 ; i <= n ; i ++) pre[i] = pre[i - 1] + a[i];
	int l = 1 , r = n , ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid , l = mid + 1;
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}

