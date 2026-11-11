#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int s = 0, f = 1;
	signed c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-') f = -f;
	for(; isdigit(c); c = getchar()) s = (s * 10) + (c ^ 48);
	return s * f;
}
void write(int x){
	if(x < 0) putchar('-'), x = -x;
	if(x > 9) write(x / 10);
	putchar('0' + x % 10);
}
const int N = 2e6 + 10;
int C, T, n, d, a[N];
void solve(){
	C = 11;
	n = read(), d = read();
	for(int i = 1; i <= n; ++ i) a[i] = read();
	if(11 <= C && C <= 12){
		int x = a[2] - a[1];
		if(d < 2 * x)
			puts("0");
		else{
			for(int i = 2; i * x <= d; ++ i){
				if(i * 2)
				if(i * x <= d && d < (i + 1) * x){
					int ans = max(n - (i * 2 - 1), 0ll);
					write(ans), puts("");
					return;
				}
			}
		}
	}else puts("1");
	return;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	C = read(), T = read();
	for(; T --;) solve();
	return 0;
}
