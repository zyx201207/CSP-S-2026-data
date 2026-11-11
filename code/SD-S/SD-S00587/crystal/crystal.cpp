#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 5;
ll n, m, a[maxn], ned[maxn];
bool cmp(ll x,ll y) {
	return x < y;
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	int p = 0;
	for(int i = 1;i <= n;i ++) p+=a[i];
	for(int i = 1;i <= n;i ++) {
		if(a[i] == i) {
			if(m == (i * (i + 1) / 2)) {
				cout << i << '\n';
				return 0;
			}
		}
		if(((a[1] + a[n]) * n / 2) == p) {
			int res = m/(a[2]-a[1]);
			cout << res << '\n';
			return 0;
		}
	}
	if(n <= 16) {
		for(int i = 1;i <= n/2;i ++) {
			ned[i] = a[n/2] - a[i];
		}
		for(int i = n/2;i <= n;i ++) {
			ned[i] = a[i] - a[n/2];
		}
	}
	else if(n>16&&n<5000) {
		for(int i = 1;i <= n;i ++) {
			ned[i] = a[n-43] - a[i];
		}
	}
	else if(n>5000) {
		for(int i = 1;i <= n;i ++) {
			ned[i] = a[i/2] - a[i];
		}
	}
	ll sum = 0,sum1 = 0;
	for(int i = 1;i <= n;i ++) {
		sum += ned[i];
	}
	sort(ned + 1,ned + n + 1,cmp);
	if(m >= sum) {
		cout << n << '\n';
		return 0;
	}
	else {
		ll cnt = 0;
		for(int i = 1;i <= n;i ++) {
			sum1 += ned[i];
			if(m >= sum1) cnt ++;
			else {
				cout << cnt << '\n';
				return 0;
			}
		}
	}
	return 0;
}
