#include <bits/stdc++.h>
#define pb emplace_back
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using i128 = __int128;
using u128 = unsigned __int128;
using namespace std;
bool ST;

const int N = 2e6 + 5;

int n,f[N],g[N],ext[N],cid;
int nxt[N],lst[N],pre[N],suf[N];
i64 D,a[N];

const int M = 5e3 + 5;
const int inf = 1e9;

struct info{i64 d,t;};

struct SGT{
	#define lc ((u) << 1)
	#define rc ((u) << 1 | 1)
	#define mid ((l + r) >> 1)
	info val[M << 2],tg[M << 2];
	void addtg(int u,info v){
		if (val[u].d > v.d) val[u] = tg[u] = v;
		else if (val[u].d == v.d) val[u].t += v.t,tg[u].d = v.d,tg[u].t += v.t;
	}void pushdown(int u){
		if (tg[u].d == inf) return;
		addtg(lc,tg[u]),addtg(rc,tg[u]),tg[u] = {(i64)inf,0ll};
	}void pushup(int u){
		if (val[lc].d < val[rc].d) val[u] = val[rc];
		else val[u] = val[lc];
	}void build(int u,int l,int r){
		val[u] = tg[u] = {(i64)inf,0ll};
		if (l == r) return;
		build(lc,l,mid),build(rc,mid + 1,r);
	}void m(int u,int l,int r,int L,int R,info v){
		if (L > R) return;
		if (L <= l && r <= R) return addtg(u,v);
		pushdown(u); 
		if (L <= mid) m(lc,l,mid,L,R,v);
		if (R > mid) m(rc,mid + 1,r,L,R,v);
		pushup(u);
	}info q(int u,int l,int r,int x){
		if (l == r) return val[u];
		pushdown(u);
		if (x <= mid) return q(lc,l,mid,x);
		return q(rc,mid + 1,r,x); 
	}
}T;

void solve(){
	cin >> n >> D;
	i64 ans = 0;
	for (int i = 1;i <= n;++i) cin >> a[i],ext[i] = 0;
	a[n + 1] = LLONG_MAX;
	for (int i = 1;i <= n;++i){
		lst[i] = lower_bound(a + 1,a + n + 2,a[i] - D) - a;
		nxt[i] = upper_bound(a + 1,a + n + 2,a[i] + D) - a - 1;
		lst[i] = min(i,lst[i]),nxt[i] = max(i,nxt[i]);
		ext[nxt[i]] = 1;
	}
	
	if (cid != 0 && cid <= 10){
		for (int s = 1;s <= n;++s){
			T.build(1,1,n);
			T.m(1,1,n,s,s,{0ll,1ll});
			for (int i = s;i <= n;++i){
				info nw = T.q(1,1,n,i);
//				cout << s << ' ' << i << ' ' << nw.d << ' ' << nw.t << '\n'; 
				if (nw.t == 2) ++ans;
				T.m(1,1,n,i + 1,nxt[i],{nw.d + 1,nw.t});
			}
		}cout << ans << '\n';
		return;
	}else if (cid != 0 && cid <= 12){
		if (n == 1) return cout << "0\n",void();
		i64 d = a[2] - a[1];
		if (D < d + d) return cout << "0\n",void();
		cout << max(n - D / d * 2ll + 1,0ll) << '\n';
		return;
	}else if (cid != 0 && cid <= 14){
		int cnt = 0;
		for (int i = 1;i <= n;++i){
			cnt += lst[i] == 1 && nxt[i] == n;
			ans += max(0,n - nxt[i]);
		}if (cnt == 2) cout << ans << '\n';
		else cout << "0\n";
		return;
	}
	
	
	for (int i = 1;i <= n;++i) f[i] = g[i] = 0;
//	for (int i = 1;i <= n;++i) cout << nxt[i] << ' ';cout << '\n';
//	for (int i = 1;i <= n;++i) cout << lst[i] << ' ';cout << '\n';
//	for (int i = 1;i <= n;++i) cout << ext[i] << ' ';cout << '\n';
//	cout << ans << '\n';
	for (int i = 2;i <= n;++i) if (ext[i]){
		int l = lower_bound(nxt + 1,nxt + n + 1,i) - nxt;
		int r = upper_bound(nxt + 1,nxt + n + 1,i) - nxt - 1;
		f[i] = f[l] + r - l + 1 - (nxt[i] == i);
		ext[i] = 0;
	}for (int i = 1;i <= n;++i) ext[lst[i]] = 1;
	for (int i = n - 1;i;--i) if (ext[i]){
		int l = lower_bound(lst + 1,lst + n + 1,i) - lst;
		int r = upper_bound(lst + 1,lst + n + 1,i) - lst - 1;
		g[i] = g[r] + r - l + 1 - (lst[i] == i);
	}suf[n + 1] = n + 1;
	for (int i = 1;i <= n;++i) pre[i] = max(pre[i - 1],nxt[i]);
	for (int i = n;i;--i) suf[i] = min(suf[i + 1],lst[i]);
	for (int i = 2;i < n - 1;++i){
		if (lst[i] != i && nxt[i + 1] != i + 1 && pre[i - 1] < nxt[i] && suf[i + 2] > lst[i + 1]){
			ans++;
			if (lst[i] == lst[i + 1]) ans += f[lst[i]];
			if (nxt[i] == nxt[i + 1]) ans += g[nxt[i]];
			if (lst[i] == lst[i + 1] && nxt[i] == nxt[i + 1]) ans += 1ll * f[lst[i]] * g[nxt[i]];
		}
	}
//	for (int i = 1;i <= n;++i) cout << f[i] << ' ';cout << '\n';
	cout << ans << '\n';
}

bool ED;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	mt19937 rnd(time(0));
	
	int T;cin >> cid >> T;
	while (T--) solve(); 
	
	cerr << "\ntime used: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000.0 << " ms";
	cerr << "\nmemory used: " << abs(&ST - &ED) / 1024.0 / 1024.0 << " MB";
	return 0; 
}/*
容斥一步，总-只有一条路径。注意到只有每一步
都跳极限才可达的点对符合要求（感性证明应该是对的） 
考虑从前往后扫。首先如果没有任何nxt=i，则i不可能成为
点对中的一个。且有直接连边的点对符合要求。 
考虑nxt=i的一段，由于可达是双向的，
i的lst一定是第一个nxt=i的位置，所以答案加等于f[lst]。
考虑更新dp。先猜一下继承自f[lst]并加上nxt=i的区间长度。
读错题了，这是至少有两条的思路QAQ
发现扰动点只可能有一个
考虑正着反着做一遍上面的东西然后枚举两边
发现中间的扰动点必须相邻，并且左区间不能到达r，右区间不能到达l 
16:40 
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
