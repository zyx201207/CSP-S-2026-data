#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<cmath>
#define re register
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lll __int128
#define db double
#define fi const int&
#define fl const ll&
#define ful const ull&
#define fll const lll&
#define fc const char&
#define fs const string&
#define debug() puts("Running Successfully!")
using namespace std ;
/*---------------------------*/
#if defined(HINA) && defined(_WIN32)
#include<io.h>
struct _Clip {
	FILE *f = _popen("powershell -NoP -c Get-Clipboard 2>nul","r") ;
	_Clip () {if (f) _dup2(_fileno(f),0) ;}
	~_Clip () {if (f) _pclose(f) ;}
}_clip ;
#endif
namespace IO {
	template<class T>inline void read (T &x) {x = 0 ;char c = getchar(),f = 0 ;while (c < 48 || c > 57) {f |= (c == 45),c = getchar() ;}while (c >= 48 && c <= 57) {x = (x << 1) + (x << 3) + (c ^ 48),c = getchar() ;}if (f) {x = ~x + 1 ;}}
	template<class T,class ...Arg>inline void read (T &x,Arg &...arg) {read(x),read(arg...) ;}
	template<class T>inline void write (T x) {if (x < 0) {putchar(45),x = ~x + 1 ;}if (x > 9) {write(x / 10) ;}putchar(x % 10 | 48) ;}
	template<class T>inline void write (T x,fc c) {write(x),putchar(c) ;}
}using namespace IO ;
int T ;
string c1,s1,c2,s2 ;
inline void solve () {
	cin >> c1 >> s1 >> c2 >> s2 ;
	if (c1 == c2)  {
		printf("1") ;
		if (s1.substr(0,2) == s2.substr(0,2)) {
			printf("1") ;
			char cc1 = s1[2],cc2 = s2[2] ;
			if (('A' <= cc1 && cc1 <= 'C' && 'A' <= cc2 && cc2 <= 'C')
			||('D' <= cc1 && cc1 <= 'E' && 'D' <= cc2 && cc2 <= 'E')) {
				printf("1") ;
				if ((int)abs((int)cc1 - (int)cc2) == 1) printf("1") ;
				else printf("0") ;
			}
			else printf("00") ;
		}
		else printf("000") ;
	}
	else printf("0000") ;
}
int main () {
	freopen("travel.in","r",stdin) ;
	freopen("travel.out","w",stdout) ;
	T = 1 ;
	while (T--) solve() ;
	return 0 ;
}

