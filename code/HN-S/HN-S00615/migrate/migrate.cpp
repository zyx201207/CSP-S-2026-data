#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e6 + 5 , inf = 0x3f3f3f3f;
#define in(a) a = read()
inline ll read() { 
	ll ch = getchar() , x = 0;
	bool f = 0;
	while('9' < ch || ch < '0') f |= ch == '-' , ch = getchar();
	while('0' <= ch && ch <= '9') x = x * 10 + ch - '0' , ch = getchar();
	return f ? -x : x;
}
int n , nx[N] , c;
ll a[N] , d;
int dis[N] , cnt[N] , vis[N] , vt;
queue<int>q;
void solve() {
	in(n) , in(d);
	for(int i = 1 ; i <= n ; i ++) in(a[i]);
	for(int i = 1 , j = 1 ; i <= n ; i ++) {
		while(j <= n && a[j] - a[i] <= d) j ++;
		nx[i] = j - 1;
	}
	if(c == 11 || c == 12) {
		if(nx[1] == 0) {
			cout << "0\n";
		} else cout << nx[1] - 1 << '\n';
		return;
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i ++) {
		vt ++;
		fill(dis + i + 1 , dis + n + 1 , inf);
		fill(cnt + i + 1 , cnt + n + 1 , 0);
		dis[i] = 0 , cnt[i] = 1;
		q.push(i);
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			if(cnt[u] == 2) ans ++;
			for(int v = nx[u] ; v > u ; v --) {
				if(dis[v] <= dis[u]) break;
				if(dis[v] == dis[u] + 1) cnt[v] += cnt[u];
				else {
					cnt[v] = cnt[u];
					dis[v] = dis[u] + 1;
					q.push(v);	
				}
			}
		}
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in" , "r" , stdin) , freopen("migrate.out" , "w" , stdout);
	int T;
	in(c) , in(T);
	while(T --) solve();
	return 0;
}

