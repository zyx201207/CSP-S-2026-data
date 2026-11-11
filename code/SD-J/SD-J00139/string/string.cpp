#include<bits/stdc++.h>
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
int T = 1 ;
const int N  = 2e5 + 2 ;
int n ;
struct node {
	ll l,r ;
	char c ;
}a[N] ;
ll len,mid ;
ll ans ;
inline void solve () {
	read(n) ;
	for (re int i = 1,sum ; i <= n ; ++i) {
		read(sum),len += sum ;
		a[i].l = a[i - 1].r + 1,a[i].r = a[i - 1].r + sum ;
		cin >> a[i].c ;
	}
	if (len & 1) mid = len / 2 + 1 ;
	else mid = len / 2 ;
	re ll iid = 1,j = len,jid = n ;
	while (a[iid].l <= mid) {
		re ll R = len - a[iid].l + 1,L = len - min(a[iid].r,mid) + 1 ;
		while (j >= L) {
			if (a[jid].c != a[iid].c) ans += j - max(L,a[jid].l) + 1 ;
			j = max(L,a[jid].l) - 1 ;
			if (j < a[jid].l) --jid ;
		}
		++iid ;
	}
	write(ans) ;
}
int main () {
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	while (T--) solve() ;
	return 0 ;
}
