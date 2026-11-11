#include<bits/stdc++.h>
using namespace std;
long long a[500050];
long long n;
inline long long read(){
	long long x(0);
	int f(1);
	char c(getchar());
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}
inline void write(long long x){
	if(x < 0){
		putchar('-');
		x = -x;
	}
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	n = read();
	long long m(read());
	//long long sum(0);
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		//sum += a[i];
	}
	long long q(0);
	long long u(0);
	long long ans(0);
	sort(a+1, a+n+1);
	for(int i = 1; i <= n; ++i){
		q = m;
		u = 0;
		long long p = i;
		while(a[p+1] == a[i])p++;
		//mid = p;
		while(p > 0 && q > 0 && a[p] + q >= a[i]){
			u++, q -= (a[i] - a[p]), p--;
		}
		if(ans < u){
			ans = u;
		}

	}write(ans);
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

