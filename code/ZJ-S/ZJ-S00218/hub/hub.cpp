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
const int N = 1e6 + 7, mod = 1e9 + 7;
int Tc, n, K;
int rt = 0;
vi G[N];
int d[N], dd[N];
int son[N];
int vis[N];
inline void fdrt(int u, int f){
//	D(u);
	son[u] = 0;
	if(d[u] > d[rt]) rt = u;
	for(int v : G[u])if(v ^ f){d[v] = d[u] + 1, fdrt(v, u);if(dd[v] > dd[son[u]]) son[u] = v;}
	dd[u] = dd[son[u]] + 1;
}
int sp[N], now;
int md[N], sum;
int pre[N], suf[N];
int ps[N], ss[N];
inline void dfs(int u, int f){
	md[u] = 0;
	for(int v : G[u]) if(v ^ f && !vis[v]) dfs(v, u), ckmax(md[u], md[v] + 1);
	if(md[u] >= now && !vis[u]) sum++;
}
inline void solve(){
	n = read(), K = read();
//	D(n);
	up(1, n, i) G[i].clear(), vis[i] = 0;
	up(1, n - 1, i){
		int u = read(), v = read();
		G[u].eb(v);
		G[v].eb(u);
//		De(u), D(v);
	}
	rt = 0;
	d[1] = 0;
	fdrt(1, 0);
	int A = rt, B, len;
	rt = 0;
	d[A] = 0;
	fdrt(A, 0);
	len = d[rt] + 1;
//	D(len);
	B = rt;
//	De(A), D(B);
	{
		int tot = 0, x = A;
		while(x){sp[++tot] = x;x = son[x];}
	}
	if(K == 1){
		printf("%lld\n", len / 2);
		return;
	}
	int m = len / 2;
	up(1, len, i) vis[sp[i]] = 1 + (i > m);
//	up(1, n, i) De(i), D(vis[i]);
//	up(1, len, i) De(i), D(sp[i]);
	auto check = [&](int mid) -> int {
		now = mid;sum = 0;
		up(1, len, i) dfs(sp[i], 0);
//		D(sum);
		up(1, m, i){
			pre[i] = max(i ? pre[i - 1] + 1 : 0, md[sp[i]]);
			ps[i] = (i ? ps[i - 1] : 0) + (pre[i] >= now);
		}
		dn(m, 1, i){
			suf[i] = max(i < m ? suf[i + 1] + 1 : 0, md[sp[i]]);
			ss[i] = (i < m ? ss[i + 1] : 0) + (suf[i] >= now);
		}
		int res = infll;
		up(1, m, i) ckmin(res, ps[i] + ss[i] - (max(pre[i], suf[i]) >= now));
		sum += res;
		up(m + 1, len, i){
			pre[i] = max(i > m + 1 ? pre[i - 1] + 1 : 0, md[sp[i]]);
			ps[i] = (i > m + 1 ? ps[i - 1] : 0) + (pre[i] >= now);
		}
		dn(len, m + 1, i){
			suf[i] = max(i < len ? suf[i + 1] + 1 : 0, md[sp[i]]);
			ss[i] = (i < len ? ss[i + 1] : 0) + (suf[i] >= now);
		}
		res = infll;
		up(m + 1, len, i) ckmin(res, ps[i] + ss[i] - (max(pre[i], suf[i]) >= now));
		sum += res;
		return sum;
	};
	int l = 0, r = len / 2;
	while(l <= r){
		int mid = l + r >> 1;
		int x = check(mid);
//		De(mid), D(x);
		if(x <= K) r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", r + 1);
//	exit(0);
}
signed main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	Tc = read();int T = read();while(T--) solve();
	return AK;
}
/*

*/
