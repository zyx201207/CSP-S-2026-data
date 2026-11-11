#include <bits/stdc++.h>
using namespace std;
long long a[200050];
int n, m;
//bool b[2050];
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
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	n = read(), m = read();
	bool o = 0;
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		if(a[i] != i-1) o = 1; 
	}
	sort(a+1, a+n+1, greater<int>());
	if(!o){
		long long e = 1;
		for(int i = 1; i <= m; ++i){
			e *= 2;
		}
		write(e);
	}
	else{
		write(a[m]);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
