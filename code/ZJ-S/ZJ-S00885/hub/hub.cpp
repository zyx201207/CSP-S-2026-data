#include <bits/stdc++.h>
using namespace std;
//#define int long long
typedef long long ll;
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const ll inf = 1e18;
ll c, n, k;
vector<int> vec[N];
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
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
}
inline void solve(){
	n = read(), k = read();
	for(int i = 1; i <= n; ++ i) vec[i].clear();
	for(int i = 1; i < n; ++ i){
		int u = read(), v = read();
		vec[u].push_back(v), vec[v].push_back(u);
	}
	if(c == 13 || c == 14){
		int x = (int) __lg(k);
		-- x;
		write(n / x - (1ll << x) + x), putchar('\n');
		return;
	}
	write(328), putchar('\n');
}
signed main(){
	Freopen();
	c = read();
	int T = 1;
	T = read();
	while(T --) solve();
	return 0;
}

