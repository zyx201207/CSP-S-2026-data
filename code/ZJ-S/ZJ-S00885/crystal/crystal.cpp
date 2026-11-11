#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const ll inf = 1e18;
ll n, m, a[N], b[N], ans;
inline ll read(){
	ll x = 0, m = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') m = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * m;
}
inline void write(ll x){
	if(x < 0){
		putchar('-');
		write(-x);
		return;
	}
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
inline void Freopen(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
}
inline void solve(){
	n = read(), m = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i) b[i] = b[i - 1] + a[i];
	for(int i = 1; i <= n; ++ i){
		ll  l = 1, r = i, pos = i;
		while(l <= r){
			ll mid = (l + r) >> 1;
			if(a[i] * (i - mid + 1) - (b[i] - b[mid - 1]) <= m) pos = mid, r = mid - 1;
			else l = mid + 1;
		}
		ans = max(ans, 1ll * (i - pos + 1));
	}
	write(ans);
}
signed main(){
	Freopen();
	int T = 1;
//	T = read();
	while(T --) solve();
	return 0;
}

