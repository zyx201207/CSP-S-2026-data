#include <bits/stdc++.h>

#define int long long
#define up(i ,x ,y) for(int i = x ; i <= y ; i ++)
#define dn(i ,x ,y) for(int i = x ; i >= y ; i --)
#define Mp make_pair
#define fir first
#define sec second
#define lowbit(x) (x & -x)

using namespace std ;

inline int read() {int x = 0 ; bool w = 0 ; char c = getchar();while(!isdigit(c)) {w |= (c == '-') ,c = getchar() ;} while(isdigit(c)) {x = (x << 1) + (x << 3) + (c ^ 48) ,c = getchar() ;} return w ? -x : x;}
inline void write(int x) { if(x < 0) x = -x ,putchar('-') ; if(x > 9) write(x / 10) ; putchar(x % 10 | 48) ;}
inline void writesp(int x) { write(x) ,putchar(' ') ;}
inline void writeln(int x) { write(x) ,putchar('\n') ;}

const int N = 5e5 + 10;
int n ,m ,a[N] ,pre[N] ,ans;

namespace lolcrying {

	signed main() {
		
		n = read() ,m = read();
		up(i ,1 ,n) a[i] = read() ; 
		
		sort(a + 1 ,a + 1 + n) ;
		
		up(i ,1 ,n) pre[i] = pre[i - 1] + a[i];
		
		up(i ,1 ,n) {
			int l = 1 ,r = i ,res = i;
			while(l <= r) {
				int mid = ((l + r) >> 1);
				if((i - mid + 1) * a[i] - (pre[i] - pre[mid - 1]) <= m) r = mid - 1 ,res = mid ;
				else l = mid + 1;
			} ans = max(ans ,i - res + 1);
		} writeln(ans);
		
		
		return 0 ;
	}
} signed main() {
	
	freopen("crystal.in" ,"r" ,stdin);
	freopen("crystal.out" ,"w" ,stdout);
	
	int T = 1 ; 
//	int T ; cin >> T;
	while(T --) lolcrying :: main();
	
	return 0 ;
}
