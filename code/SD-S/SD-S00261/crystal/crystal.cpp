#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

//#define LOCAL
namespace IO {
	#ifndef LOCAL
		#define SIZE (1<<20)
		char in[SIZE] , *p1=in , *p2=in , out[SIZE] , *p3 = out;
		#define getchar() (p1==p2 && (p2=(p1=in)+fread(in,1,SIZE,stdin)) , p1==p2 ? EOF : *p1 ++)
		#define flush() (fwrite(out,1,p3-out,stdout),p3=out)
		#define putchar(c) (p3==out+SIZE && flush() , *p3 ++ = c)
		class Flush{ public: ~Flush() {flush();} } ___;
	#endif

	inline LL read() {
		LL x = 0; int f = 1;
		int c = getchar();
		while(c < '0' || '9' < c) {
			if(c == '-') f = -1;
			c = getchar();
		}
		while('0' <= c && c <= '9') {
			x = (x<<3) + (x<<1) + c - '0';
			c = getchar();
		}
		return x * f;
	}

	inline void write(int x , bool f = true) {
		if(x < 0) x = -x , putchar('-');
		static short stk[80]; int top = 0;
		do stk[++ top] = x%10 , x /= 10; while(x);
		while(top) putchar(stk[top --] | '0');
		if(f) putchar('\n'); else putchar(' ');
	}

	#ifndef LOCAL
		#undef SIZE
		#undef getchar
		#undef flush
		#undef putchar
	#endif
} using IO::read; using IO::write;

const int N = 5e5+10;

int n; LL m;
LL a[N];

bool check(int x) {
	for(int i = x ; i <= n ; i ++) {
		if((a[i]-a[i-1])*x - (a[i]-a[i-x]) <= m) return true;
	}
	return false;
}

int main() {
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	n = read(); m = read();
	for(int i = 1 ; i <= n ; i ++) a[i] = read();
	sort(a+1 , a+n+1);
	for(int i = 2 ; i <= n ; i ++) a[i] += a[i-1];
	
	int l = 1 , r = n , mid , ans = 0;
	while(l <= r) {
		mid = (l+r) >> 1;
		if(check(mid)) {
			ans = mid;
			l = mid+1;
		} else {
			r = mid-1;
		}
	}
	write(ans);
	return 0;
}

