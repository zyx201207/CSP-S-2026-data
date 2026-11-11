#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define fir first
#define sec second
#define lowbit(x) (x & -x)

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar() ;  while(!isdigit(c)) {w |= (c == '-') ,c = getchar();} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;  } return w ? -x : x;}
inline void write(int x){if(x < 0) putchar('-') ,x = -x;if(x > 9) write(x / 10);putchar(x % 10 | 48);}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 5e5 + 10;
int n ,a[N] ;
char c[N] ; 

namespace lolcrying {
	
	signed main() {
		
		n = read() ; 
		int L = 0 ; 
		up(i ,1 ,n) {
			a[i] = read() ; 
			cin >> c[i] ;
			L += a[i] ;
		}
		
		int p1 = 1 ,p2 = n ,st = a[1] ,ed = a[n] ,ans = 0; 
		while(p1 < p2) {
			ans += min(st ,ed) * (c[p1] != c[p2]);
			if(st < ed) {
				ed -= st ,st = a[++ p1] ;
			} else if(ed < st) {
				st -= ed ,ed = a[-- p2] ;
			} else {
				st = a[++ p1] ,ed = a[-- p2];
			}
		} writeln(ans);
		
		return 0 ;
	}
} signed main() {
	
	freopen("string.in" ,"r" ,stdin);
	freopen("string.out" ,"w" ,stdout);
	
	int T = 1;
//	int T = read() ; 
	while(T --) lolcrying :: main();
	return 0 ;
	
}

