#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 5e3 + 10;
const int mod = 1e9 + 7;
const ll inf = 1e18;
ll c, n, d, a[N], rpos[N], dis[N][N], ans;
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
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
}
inline void solve(){
	n = read(), d = read(), ans = 0;
	for(int i = 1; i <= n; ++ i) a[i] = read();
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++ i){
		int l = i, r = n;
		rpos[i] = i;
		while(l <= r){
			int mid = (l + r) >> 1;
			if(a[mid] - a[i] <= d) rpos[i] = mid, l = mid + 1;
			else r = mid - 1;
		}
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = 1; j <= n; ++ j){
			dis[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; ++ i){
		int pos = i, cnt = 0;
		while(rpos[pos] != pos){
			pos = rpos[pos], ++ cnt;
			dis[i][pos] = cnt;
		}
		for(int j = n; j >= i + 1; -- j) if(!dis[i][j]) dis[i][j] = dis[i][j + 1];
	}
	for(int i = 1; i <= n; ++ i){
		for(int j = i + 1; j <= n; ++ j){
			int pos = i, flag = 1, now = 0;
			while(rpos[pos] != pos){
				int u = pos, v = rpos[pos];
				if(v >= j) {
					pos = v;
					break;
				}
				if(v - u >= 2){
					if(dis[v - 1][j] == dis[v][j]){
						if(v - 2 > u && dis[v - 2][j] == dis[v][j]) flag = 0;
						else ++ now;
					}
				}
				pos = v;
			}
			flag &= (now == 1) & (pos >= j);
			ans += flag;
		}
	}
	write(ans), putchar('\n');
}
signed main(){
	Freopen();
	c = read();
	int T = 1;
	T = read();
	while(T --) solve();
	return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/
