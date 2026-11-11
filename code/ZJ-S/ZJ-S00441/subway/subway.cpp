#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 505, M = 5e5 + 5;
const ll inf = 1ll << 60;
ll read(){
	ll x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f; 
}
int c, n, m, d, q;
ll w[M];
vector<pair<int, ll> >sub[M];
ll a[N][N];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for(int i = 1; i <= m; i++) w[i] = read();
	for(int i = 1; i <= n; i++){
		int k = read();
		for(int j = 1; j <= k; j++){
			int a = read();
			ll t = read();
			sub[a].push_back(make_pair(i, t));
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++) a[i][j] = inf;
	}
	for(int i = 1; i <= n; i++) a[i][i] = 0;
	for(int i = 1; i <= m; i++){
		int len = sub[i].size();
		for(int j = 0; j < len; j++){
			for(int k = j + 1; k < len; k++){
				pair<int, ll>s = sub[i][j], t = sub[i][k];
				int ids = s.first, idt = t.first;
				ll diss = s.second, dist = t.second;
				a[ids][idt] = min(a[ids][idt], diss + dist);
				a[idt][ids] = min(a[idt][ids], diss + dist);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++) a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
		}
	}
	while(q--){
		int x, y;
		ll mn = inf;
		x = read(), y = read();
		int lenx = sub[x].size(), leny = sub[y].size();
		for(int i = 0; i < lenx; i++){
			for(int j = 0; j < leny; j++){
				pair<int, ll>s = sub[x][i], t = sub[y][j];
				int ids = s.first, idt = t.first;
				ll diss = s.second, dist = t.second;
				mn = min(mn, a[ids][idt] + diss + dist + w[x] + w[y]);
			}
		}
		cout << mn << '\n';
	} 
	return 0;
}
