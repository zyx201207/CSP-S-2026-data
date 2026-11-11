#include<bits/stdc++.h>
using namespace std;
namespace zhr{
#define AK 0
#define int long long
#define ll long long
#define uint unsigned int
#define ull unsigned long long
#define i128 __int128
#define vi vector<int>
#define vp vector<pair<int,int> >
#define pii pair<int, int>
#define mkp make_pair
#define up(l,r,i) for(int i=l;i<=r;++i)
#define dn(r,l,i) for(int i=r;i>=l;--i)
#define ctn continue
#define brk break
#define mems(a,x) memset((a),(x),sizeof(a))
#define De(x) cout<<#x<<": "<<x<<' '
#define D(x) cout<<#x<<": "<<x<<'\n'
#define eb emplace_back
#define pb push_back
#define _all(x) x.begin(),x.end()
#define _sz(x) ((int)(x.size()))
const int inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
inline void ckmin(int &x, int y){x = x < y ? x : y;}
inline void ckmax(int &x, int y){x = x > y ? x : y;}
inline int read(){
	int x = 0;bool f = 0;char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = 1;c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10 + (c ^ 48);c = getchar();}
	return f ? -x : x;
}
}
using namespace zhr;
const int N = 2e6 + 7, mod = 1e9 + 7;
int Tc, n, d;
int a[N], jp[N];
//map<array<int, 4>, int> mp;
//inline int cal(array<int, 4> mx){
//	if(jp[mx[0]] == mx[0]) return 0ll;
//	if(mp.count(mx)) return mp[mx];
//	int& ans = mp[mx];
//	up(1, 3, j) if(~mx[j]) mx[j] = jp[mx[j]];
//	int qwq = max(mx[1] - max({mx[0], mx[2], mx[3]}), 0ll);
//	ans += max(mx[1] - max({mx[0], mx[2], mx[3]}), 0ll);
//	int to = jp[mx[0]] - 1;
//	if(to >= mx[1]) mx[2] = mx[1], mx[1] = to;
//	else if(to >= mx[2]) mx[2] = to;
//	if(jp[mx[0]] - mx[0] > 1) ckmax(mx[3], jp[mx[0]] - 2);
//	mx[0] = jp[mx[0]];
//	ans += cal(mx);
//	return ans;
//}
int sn = 0;
inline void solve(){
	n = read(), d = read();
	sn += n;
	up(1, n, i) a[i] = read();
	for(int i = 1, j = 1; i <= n; i++){
		while(j < n && a[j + 1] - a[i] <= d) j++;
		jp[i] = j;
	}
	unordered_map<int, int> mp;
//	map<array<int, 4>, int> mp;
	auto get = [&](array<int, 4> mx) ->int{
		return ((((((mx[0] + 1) << 24) | (mx[2] + 1)) << 3) | (mx[0] - mx[1])) << 3) | (mx[0] - mx[3]);
	};
	auto cal = [&](auto &&self, array<int, 4> mx) -> int{
		if(jp[mx[0]] == mx[0]) return 0ll;
		i128 hs = get(mx);
//		cerr << (int)hs << '\n';
//		D(hs);
		if(mp.count(hs)) return mp[hs];
		int& ans = mp[hs];
		up(1, 3, j) if(~mx[j]) mx[j] = jp[mx[j]];
		ans += max(mx[1] - max({mx[0], mx[2], mx[3]}), 0ll);
		int to = jp[mx[0]] - 1;
		if(to >= mx[1]) mx[2] = mx[1], mx[1] = to;
		else if(to >= mx[2]) mx[2] = to;
		if(jp[mx[0]] - mx[0] > 1) ckmax(mx[3], jp[mx[0]] - 2);
		mx[0] = jp[mx[0]];
		ans += self(self, mx);
		return ans;
	};
//	up(1, n, i) printf("%lld ", jp[i]);printf("\n");
	jp[n + 1] = n + 1;
	int res = 0;
	dn(n, 1, i){
		if(jp[i] == i) ctn;
		array<int, 4> mx = {i, -1, -1, -1};
		int ans = 0;
		int to = jp[mx[0]] - 1;
		if(to >= mx[1]) mx[2] = mx[1], mx[1] = to;
		else if(to >= mx[2]) mx[2] = to;
		if(jp[mx[0]] - mx[0] > 1) ckmax(mx[3], jp[mx[0]] - 2);
		mx[0] = jp[mx[0]];
		ans += cal(cal, mx);
//		De(i), D(ans);
		res += ans;
	}
	printf("%lld\n", res);
//	cerr << n << ' ' << _sz(mp) << '\n';
//	exit(0);
}
signed main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
//	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	Tc = read();int T = read();while(T--) solve();
//	cerr << sn << '\n';
	return AK;
}
/*

*/
