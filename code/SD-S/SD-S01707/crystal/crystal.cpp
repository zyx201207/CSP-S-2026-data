#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5+10;
ll n , m;
ll a[N] , b[N];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + 1 + n);
	for(int i = 1 ; i <= n ; i++) {
		b[i] = b[i - 1] + a[i];
//		cout << b[i] << ' ';
	}
	ll ans = 0; 
	for(int i = 1 ; i <= n ; i++) {
//		ll cnt = 0;
//		ll x = a[i];
//		ll t = m;
//		for(int j = i ; j >= 1 ; j--) {
//			t -= (x - a[j]);
//			if(t < 0) break;
//			cnt++;
//		}
//		ans = max(ans , cnt);
		ll l = 1 , r = i;
		while(l < r) {
			ll mid = (l + r) >> 1;
//			cout << (i - mid) * a[i] - (b[i] - b[mid - 1]) << ' ';
			if(((i - mid) * a[i] - (b[i - 1] - b[mid - 1])) > m) {
				l = mid + 1;
			}
			else {
				r = mid;
			}
		}
		ans = max(ans , (i - l + 1));
	}
	cout << ans;
	return 0;
}

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

6 7
5 8 9 1 9 0
这是我的luogu UID 喵，欢迎关注 

14：58 AC T1 (?)
这是第一次这么快 AC T1.
感想很多，但是显然没时间写
打个对拍 
哎，空悲切...... 
*/
