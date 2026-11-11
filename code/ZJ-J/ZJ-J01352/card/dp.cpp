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
int n ,m;
mt19937_64 rnd(time(NULL)) ;

namespace lolcrying {

	signed main() {
		
		while(1) {
			
			system("gen > test.in") ;
			system("card.cpp < test.in > card.out") ;
			system("bl.cpp < test.in > bl.out");
			system("pause") ;
			
			if(system("fc card.out bl.out")) {
				system("pause");
				return 0 ;
			}
			
		}
		
		return 0 ;
	}
} signed main() {
	
	freopen("card.in" ,"w" ,stdout);
//	freopen("card.out" ,"w" ,stdout);
	
	int T = 1;
//	int T = read() ; 
	while(T --) lolcrying :: main();
	return 0 ;
	
}

