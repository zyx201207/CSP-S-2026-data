#include <bits/stdc++.h>
using namespace std;
int a[500050];
int n, m;
int head, tail;
int o[500050];
int u[500050];

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
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	n = read(), m = read();
	bool b(0);
	for(int i = 1; i <= n; ++i){
		a[i] = read();
		if(a[i] < a[i-1]) b = 1;
		u[a[i]]++;
	}
	if(b == 0){
		for(int i = 1; i <= n; ++i){
			if(u[i] == 1){
				write(i);
			}
			else write(1);
			putchar(' ');
		}
	}
	for(int i = 1; i <= n; ++i){
		head = i; tail = n;
		while(head < tail){
			if(a[tail] == a[head]){
				head = tail;
				tail = n;
			}
			tail--;
			if(tail == head) o[a[head++]]++, tail = n;
		}
		for(int j = head; j <= n; ++j){
			o[a[j]]++;
		}
	}
	for(int i = 1; i <= m; ++i){
		write(o[i]);
		putchar(' ');
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
