#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read() {
	char c = getchar();
	ll x = 0, f = 1;
	while(!isdigit(c)) {
		if(c == '-')
			f = -1;
		c = getchar();
	}
	while(isdigit(c)) {
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
const int N = 2e6 + 5;
const int NN = 5005;
int c, t, n, dis[NN][NN], flag[NN][NN];
ll x[N], d;
void solve() {
	n = read(), d = read();
	for(int i = 1; i <= n; ++i)
		x[i] = read();
	if(c <= 6) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j)
				flag[i][j] = dis[i][j] = 0;
			int lst = i, l = 1;
			for(int j = i + 1; j <= n; ++j) {
				int tmp = j;
				while(x[lst] + d >= x[j] && j <= n) {
					dis[i][j] = l;
					++j;
				}
				if(j == tmp)
					break;
				lst = (--j);
				flag[i][lst] = 1;
				++l;
			}
		}
		int res = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = i + 3; j <= n; ++j) {
				if(!dis[i][j]) continue;
				int cnt = 0;
				for(int k = i + 1; k < j; ++k) 
					if(dis[i][k] + dis[k][j] == dis[i][j] && !flag[i][k])
						++cnt; 
				if(cnt == 1) ++res;
			}
		}
		cout << res << '\n';
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), t = read();
	while(t--)
		solve();
	return 0;
}
