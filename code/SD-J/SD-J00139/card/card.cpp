#include<bits/stdc++.h>
#include<vector>
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
int T = 1 ;
const int N = 5e5 + 2,M = 3e5 + 2 ;
int n,m,a[N] ;
int cnt[M] ;
int ans[M] ;
bool vis[M] ;
vector<int> v ;
inline void solve () {
	read(n,m) ;
	for (re int i = 1 ; i <= n ; ++i) read(a[i]) ;
	for (re int i = n ; i >= 1 ; --i) {
		if (!vis[a[i]]) {
			++ans[a[i]] ;
			for (re int j = i - 1 ; j >= 1 ; --j) {
				bool f = 1 ;
				++cnt[a[j]] ;
				for (re int x : v) {
					if (cnt[x] & 1) {
						f = 0 ;
						break ;
					}
				}
				if (f) ++ans[a[i]] ;
			}
			vis[a[i]] = 1,v.push_back(a[i]) ;
			fill(cnt + 1,cnt + 1 + n,0) ;
		}
	}
	for (re int i = 1 ; i <= m ; ++i) write(ans[i],' ') ;
}
int main () {
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	while (T--) solve() ;
	return 0 ;
}
/*
性质：
 
1. 每种数只有最后出现的一个可能会活下来
2. 对于i最后一次出现的位置pos，考虑后面有啥数
	对于某一轮，i能活，当仅后前配对没有杀掉i
	
	能活：偶奇、偶偶->和后面出现次数没有关系 
	
欸暴力怎么似了

最区之人 
*/

