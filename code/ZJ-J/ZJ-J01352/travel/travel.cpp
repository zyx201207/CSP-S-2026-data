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

namespace lolcrying {
	
	signed main() {
		
		string c1 ,s1 ,c2 ,s2;
		cin >> c1 >> s1 >> c2 >> s2;
		
		string l1 = s1.substr(0 ,2) ,l2 = s2.substr(0 ,2) ;

		char col1 = s1[2] ,col2 = s2[2];
		
		if(c1 == c2) putchar('1');
		else putchar('0') ;
		
		if(c1 == c2 && l1 == l2) putchar('1');
		else putchar('0');
		
		if(c1 == c2 && l1 == l2 && ((col1 <= 'C' && col2 <= 'C') || (col1 >= 'D' && col2 >= 'D'))) putchar('1');
		else putchar('0');
		
		if(c1 == c2 && l1 == l2 && ((col1 <= 'C' && col2 <= 'C') || (col1 >= 'D' && col2 >= 'D')) && (abs(col1 - col2) <= 1 || (col1 == 'D' && col2 == 'F') || (col1 == 'F' && col2 == 'D'))) putchar('1');
		else putchar('0');	
			
		return 0 ;
	}
} signed main() {
	
	freopen("travel.in" ,"r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	
	int T = 1;
//	int T = read() ; 
	while(T --) lolcrying :: main();
	return 0 ;
	
}

