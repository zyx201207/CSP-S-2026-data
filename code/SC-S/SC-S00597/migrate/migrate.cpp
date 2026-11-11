#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
	T s = 0; int st = 1; char c = getchar();
	while(c < '0' || c > '9') (c == '-') && (st = -1), c = getchar();
	while(c >= '0' && c <= '9') s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
	x = s * st;
}
template<typename T, typename... Args> inline void read(T &x, Args &...args){
	read(x), read(args...);
}
template<typename T> inline void write(T x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
#define LL long long
#define PII pair<int, int>
#define ull unsigned long long
const int N = 2e6 + 5;
LL s[N], sum[N];
int dis[N], f[N];
inline void run(int c){
	int n; LL d;
	read(n, d);
	for(int i = 1; i <= n; ++i){
		read(s[i]);
	}
	if(c >= 11){
		int L = 0, R = 0, cnt = 0;
		for(int i = 1; i <= n; ++i){
			if(s[i] - s[1] <= d && s[n] - s[i] <= d){
				++cnt;
				if(L == 0) L = i;
				R = max(R, i);
			}
		}
		if(cnt == 2){
			write((LL)(L - 1) * (n - R)), putchar('\n');
		}
		else puts("0");
		return;
	}
	LL ans = 0;
	for(int i = 1, las, ras; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			dis[j] = sum[j] = f[j] = 0;
		}
		las = ras = i;
		f[i] = sum[i] = 1;
		for(int j = i + 1; j <= n; ++j){
			while(las < j && s[j] - s[las] > d) ++las;
			if(las == j) break;
			dis[j] = dis[las] + 1;
			ras = max(ras, las);
			while(ras < j - 1 && dis[ras + 1] == dis[las]) ++ras;
			f[j] = sum[ras] - sum[las - 1];
			sum[j] = sum[j - 1] + f[j];
			if(f[j] == 2) ++ans;
//			cerr << i << ' ' << j << ' ' << f[j] << ' ' << dis[j] << ' ' << las << ' ' << ras << '\n';
		}
	}
	write(ans), putchar('\n');
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	freopen("migrate3.in", "r", stdin);
//	freopen("mine.out", "w", stdout);
	int c, T;
	read(c, T);
	while(T--) run(c);
	return 0;
}
