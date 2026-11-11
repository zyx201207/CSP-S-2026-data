#include <bits/stdc++.h>
using namespace std;

typedef struct _PAIR_LONGLONG_CHAR{
	long long ilen;
	char c;
}PLC;
PLC a[200050];
int n, head, tail;
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
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	n = read();
	head = 1;
	tail = n;
	long long ans(0);
	for(int i = 1; i <= n; ++i){
		a[i].ilen = read(), a[i].c = getchar();
	}
	int len1, len2, c1, c2; 
	while(head < tail){
		len1 = a[head].ilen , c1 = a[head].c;
		len2 = a[tail].ilen , c2 = a[tail].c;
		if(len1 == len2){
			if(c1 == c2){
				head++, tail--;
				continue;
			}
			if(c1 != c2){
				head++, tail--;
				ans += len1;
				continue;
			}
		}
		if(len1 != len2){
			if(c1 == c2){
				if(len1 < len2){
					head++;
					a[tail].ilen -= len1;
					continue;
				}
				else{
					tail--;
					a[head].ilen -= len2;
					continue;
				}
			}
			if(c1 != c2){
				if(len1 < len2){
					head++;
					ans += len1;
					a[tail].ilen -= len1;
					continue;
				}
				else{
					tail--;
					ans += len2;
					a[head].ilen -= len2;
					continue;
				}
			}
		}
	}
	write(ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
