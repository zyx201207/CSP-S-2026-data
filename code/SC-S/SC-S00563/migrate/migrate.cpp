#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while('0' <= ch && ch <= '9'){
		x = (x * 10) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
void write(int x){
	if(x < 0){putchar('-');x = -x;}
	if(x > 9)write(x / 10);
	putchar(x % 10 + '0');
}

const int N = 2e6 + 5;
int c, t, n, d, x[N], l[N], r[N], ans;

signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out","w",stdout);
	c = read(); t = read();
	if(c == 11 || c == 12){
		while(t --){
			n = read(); d = read();
			for(int i = 1;i <= n;i ++)
				x[i] = read();
			int k = d / (x[n] - x[n - 1]);
			if(2 * k > n || k <= 1) write(0);
			else write(n - 2 * k + 1);
			putchar('\n');
		}
		return 0;
	}
	
	while(t --){
		n = read(); d = read();
		for(int i = 1;i <= n;i ++)
			x[i] = read();
		
		ans = 0;
		
		x[0] = l[0] = 0;
		r[n + 1] = n + 1, x[n + 1] = x[n] + 1;
		
		for(int i = 1;i <= n;i ++){
			if(x[r[i - 1]] < x[i]) r[i] = i;
			else r[i] = r[i - 1];
			while(x[r[i] + 1] - x[i] <= d && r[i] < n) ++r[i];
		}
		for(int i = n;i >= 1;i --){
			if(x[l[i + 1]] > x[i]) l[i] = i;
			else l[i] = l[i + 1];
			while(x[i] - x[l[i] - 1] <= d && l[i] > 1) --l[i];
		}
		
		write(n - d / (x[n] - x[n-1]));
	}
	return 0;
}