#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll n, m, a[500005], q[2000005], h, t, ans = 1, cnt;

bool cmp(ll x, ll y){
	return x > y;
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n, cmp);
	h = 1, t = 1, cnt = m;
	q[1] = a[1];
	for(int i = 2;i <= n;i ++){
		q[++ t] = a[i];
		cnt -= (q[h] - a[i]);
		while(cnt < 0){
			cnt += (q[h] - q[h + 1]) * (t - h);
			h ++;
		}
		ans = max(ans, t - h + 1);
	}
	cout << ans;
	return 0;
}
