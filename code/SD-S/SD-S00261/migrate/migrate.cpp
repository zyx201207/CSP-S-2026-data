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

	inline void write(LL x , bool f = true) {
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

const int N = 2e6+10;
//const int N = 5010;

int n; LL d;
LL a[N];
LL dis[N];
LL c[N];

namespace BF {
	inline int lowbit(int x) {
		return x & (-x);
	}
	
	inline void add(int x , LL y) {
		while(x <= n) c[x] += y , x += lowbit(x);
	}
	
	inline LL query(int x) {
		LL res = 0;
		while(x) res += c[x] , x -= lowbit(x);
		return res;
	}
	inline void solve() {
		n = read(); d = read();
		for(int i = 1 ; i <= n ; i ++) a[i] = read();
		LL ans = 0;
		for(int i = 1 ; i <= n ; i ++) {
			memset(c , 0 , sizeof c);
			dis[i] = 0;
			add(i , 1);
			for(int j = i+1 ; j <= n ; j ++) {
				int l = i , r = j , mid;
				while(l < r) {
					mid = (l+r) >> 1;
					if(a[mid]+d >= a[j]) r = mid;
					else l = mid+1;
				}
				if(l == j) continue;
				dis[j] = dis[l]+1;
				LL cj = -query(l-1);
				r = j-1;
				while(l < r) {
					mid = (l+r+1) >> 1;
					if(dis[mid] == dis[j]-1) l = mid;
					else r = mid-1;
				}
				cj += query(l);
				add(j , cj);
				
				if(cj == 2) {
					ans ++;
	//				printf("! [%d,%d]\n" , i , j);
				}
			}
		}
		write(ans);
	}
}

inline void solve() {
	n = read(); d = read();
	for(int i = 1 ; i <= n ; i ++) a[i] = read();
	LL ans = 0;
	for(int i = 1 , pre = 0 , suf = 0 ; i+3 <= n ; i ++ , suf --) {
		if(i != 1 && a[i]-a[i-1] <= d && a[i+1]-a[i-1] > d) pre ++;
		else pre = 1;
		
		if(!suf) {
			int j = i+3;
			while(j < n && a[j+1]-a[j-1] > d && a[j+1]-a[j] <= d) j ++;
			suf = j-i-2;
		}
		
		if(a[i]+d < a[i+3] && a[i]+d >= a[i+2] && a[i+1]+d >= a[i+3]) {
			ans += 1ll * pre * suf;
		}
	}
	
	write(ans);
}

int main() {
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);
	int C = read() , T = read();
	while(T --) {
		if(C <= 10) BF::solve();
		else solve();
	}
	return 0;
}
/*
0 1
10 3
0 3 6 7 8 9 10 13 16 19
*/
