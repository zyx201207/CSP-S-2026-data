#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define fir first
#define sec second
#define lowbit(x) (x & -x)
#define inf 2e18

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar();while(!isdigit(c)) {w |= (c == '-') ,c = getchar() ;} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;} return w ? -x : x;}
inline void write(int x) { if(x < 0) x = -x ,putchar('-') ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48) ;}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 2e6 + 10;
int n ,c ,d ,x[N] ,dis[N] ,path[N]; 
mt19937_64 rnd(time(NULL)) ;

namespace lolcrying {

	signed main() {
		
		n = 5000 ,d = 1e18 ;
		cout << n << ' ' << d << endl;
		int prex = 0 ;
		up(i ,1 ,n) {
			int x = rnd() % 100 + 1;
			cout << prex + x << ' ';
			prex = x;
		}
		return 0 ;
	}
} signed main() {
	
	freopen("migrate.in" ,"w" ,stdout);
	
	cout << 0 << ' ' << 1 << endl;
	int T = 1;
	while(T --) lolcrying :: main();
	
	return 0 ;
}
