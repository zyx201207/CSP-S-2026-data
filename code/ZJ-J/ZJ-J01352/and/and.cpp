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
int n ,m ,a[N] ;

namespace lolcrying {
	
	signed main() {
		
		n = read() ,m = read() ;
		up(i ,1 ,n) a[i] = read();
		
		int ans = 0;
		
		dn(i ,31 ,0) {
			int ok = (ans | (1ll  << i)) ,sum = 0 ;
			up(j ,1 ,n) sum += ((ok & a[j]) == ok);
			if(sum >= m) ans = ok ;
		} writeln(ans);
		
		return 0 ;
	}
} signed main() {
	
	freopen("and.in" ,"r" ,stdin);
	freopen("and.out" ,"w" ,stdout);
	
	int T = 1;
//	int T = read() ; 
	while(T --) lolcrying :: main();
	return 0 ;
	
}

