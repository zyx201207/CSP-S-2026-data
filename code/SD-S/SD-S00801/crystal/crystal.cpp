#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll INF2 = 0x3f3f3f3f3f3f3f3f;

ll n, m;
const int N = 5e5 + 10;
ll a[N];

ll check(ll mid) {
	ll cnt = 0;
	for (int i = mid; i >= 1; i--) {
		ll num = a[mid]-a[i];
		if (cnt + num <= m) {
			cnt += num;
		} else {
			return mid-i+1;
		}
	}
	return mid;
}
void solve1() {
	ll ret = 1;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, check(i));
	}
	
	cout << ret;
}

void solve2() {
	deque<int> q;
	ll sum = 0;
	ll ret = 0;
	for (int i = 1; i <= n; i++) {
		if (q.size()) sum += 1ll * q.size() * (a[i]-a[q.back()]);
		q.push_back(i);
		while (q.size() && sum > m) {
			sum -= a[i]-a[q.front()];
			q.pop_front(); 
		}
		
		ret = max(ret, (ll)q.size());
	}
	
	cout << ret;
}

signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(),cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	
//	if (n <= 5000) {
//		solve1();
//	} else {
		solve2();
//	}
	
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/
