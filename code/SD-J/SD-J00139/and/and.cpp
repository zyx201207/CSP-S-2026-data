#include<bits/stdc++.h>
#include<algorithm>
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
const int N = 2e5 + 2 ;
int T = 1 ;
int n,m ;
int a[N],mx ;
ll ans ;
inline int ef (fi x,fi R) {
	re int l = 1,r = R,ans = 0,mid ;
	while (l <= r) {
		mid = (l + r) >> 1 ;
		if ((a[mid] >> x) & 1) ans = mid,l = mid + 1 ;
		else r = mid - 1 ;
	}
	return ans ;
}
inline void solve () {
	read(n,m),mx = n ;
	for (re int i = 1 ; i <= n ; ++i) read(a[i]) ;
	for (re int i = 30,pos ; i >= 0 ; --i) {
		sort(a + 1,a + 1 + mx,greater<int>()) ;
		pos = ef(i,mx) ;
		if (pos >= m) ans += (1 << i),mx = pos ;
		else {
			for (re int j = 1 ; j <= pos ; ++j) a[j] -= (1 << i) ;
		}
	}
	write(ans) ;
}
int main () {
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	while (T--) solve() ;
	return 0 ;
}
