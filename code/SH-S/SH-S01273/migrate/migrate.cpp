#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6;
int n, d, a[N], ct;
int read(){
	int x = 0, f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x * f;
}
void write(int x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}
void solve(){
	int q;
	n = read(), d = read();
	for(int i = 1;i <= n; i++)
		a[i] = read();
	q = a[2] - a[1];
	if(d < 2 * q || d >= a[n] - a[1]){
		puts("0");
		return ;
	}
	int maxx = d / q;
	for(int dis = d / q + 1;dis <= n; dis++)
		for(int start = 1;start + dis <= n; start++)
			if(dis % maxx != 0 && dis % 2 == 1)
				ct ++;
			else if(dis % 2 == 0 && dis % maxx != 0 && a[dis / 2] - a[start] > d)
				ct ++;
	write(ct);
	puts("");
	ct = 0;
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	c = read(), t = read();
	while(t --)
		solve();
	return 0;
}
