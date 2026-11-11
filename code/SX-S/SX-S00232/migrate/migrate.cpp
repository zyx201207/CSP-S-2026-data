#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int maxn = 5e3 + 1;
const lint inf = 1e18;
template <typename T>
inline void fastread(T& x){
	x = 0; char ch = getchar(), f = 1;
	while(!isdigit(ch)){
		if(ch == '-') f = -f;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	x *= f;
}
template <typename T>
inline void fastprint(T x){
	if(x > 9) fastprint(x / 10);
	putchar(x % 10 + 48);
}
int c = 0, t = 0, n = 0;
lint d = 0, a[maxn], dist[maxn][maxn], cnt[maxn][maxn];

inline lint floyd(){
	lint ans = 0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dist[i][j] = inf, cnt[i][j] = 0;
	for(int i = 1; i <= n; ++i)
		dist[i][i] = 0;
	for(int i = 1; i < n; ++i)
		for(int j = i + 1; j <= n; ++j)
			if(abs(a[i] - a[j]) <= d) dist[i][j] = dist[j][i] = 1;
	for(int i = 1; i <= n - 3; ++i)
		for(int j = i + 3; j <= n; ++j){
			for(int k = i + 1; k < j; ++k){
				if(dist[i][k] + dist[k][j] > dist[i][j]) continue;
				dist[i][j] = dist[i][k] + dist[k][j];
				++cnt[i][j];
			}
			if(cnt[i][j] == 2) ++ans;
		}
	return ans;
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	fastread(c); fastread(t);
	while(t--){
		fastread(n); fastread(d);
		for(int i = 1; i <= n; ++i)
			fastread(a[i]);
		fastprint(floyd());
		putchar('\n');
	}
	return 0;
}
