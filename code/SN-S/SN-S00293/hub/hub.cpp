#include <bits/stdc++.h>
#define _eggy_ using
#define _party_ namespace
#define sf scanf
#define pf printf
_eggy_ _party_ std; _party_ llamn { _party_{

#define ll long long
numeric_limits<int> INT;
numeric_limits<ll> LL;

#if 0
#define for_nm(do_) for (signed kh = 0, yh = 0; kh || yh || (*i != ',' && *i != '\0'); i++) \
{switch(*i){case '(': case '[': case '{': kh++; break; case ')': case ']': case '}': kh--; break; case '\"': yh ^= 1;} do_;}
#define vtmp template<typename Th, typename... Ts>
#define varg Th&& arg, Ts&&... ars
#define putl(c) (isblank(c)?:putc(c,stderr))

void showf(char* i) {cerr << '\n';}
vtmp void showf(char* i, varg)
{
	for_nm(putl(*i)); cerr << " = " << arg << "   ";
	showf(i+1,ars...);
}

vtmp void gnxt(varg) {return arg;} void gnxt(){}
vtmp void Lnxt(char* i, varg);
void shoaf(char* i) {cerr << '\n';}
vtmp void shoaf(char* i, varg)
{
	for_nm(putl(*i)); cerr << ": ";
	signed j, len = gnxt(ars...);
	for (j = 0; j <= len; j++)
		cerr << arg[j] << ' ';
	cerr << '\n'; Lnxt(i+1,ars...);
}vtmp void Lnxt(char* i, varg) {for_nm(); shoaf(i+1,ars...);}

#define show(...) showf(const_cast<char*>(__VA_ARGS__), __VA_ARGS__);
#define shoa(...) shoaf(const_cast<char*>(__VA_ARGS__), __VA_ARGS__);
#else
#define show(...) void(0);
#define shoa(...) void(0);
#endif

int n,m,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

constexpr int N = 100100;
int c,$;

vector<int> e[N]; 
int dfx[N],wei[N],dx,dep[N],f[N];

void dfs(int d)
{
	dfx[++dx] = d, wei[d] = dx;
	for (int i : e[d])
	{
		if (f[d] == i) continue;
		dep[i] = dep[d] + 1, f[i] = d, dfs(i);
	}
}struct lca_t
{
	struct ST
	{
		#define pii pair<int,int>
		#define pl first
		#define pr second
		pii a[20][N];
		void bd()
		{
			for (i = 1; i <= n; i++) a[0][i] = {dep[dfx[i]], dfx[i]};
			for (i = 1; (1 << i) <= n; i++)
				for (j = 1; j <= n-(1<<i)+1; j++)
					a[i][j] = min(a[i-1][j],a[i-1][j+(1<<i>>1)]);
		}int ask(int l, int r)
		{
			int t3 = __lg(r-l+1);
			return min(a[t3][l],a[t3][r-(1<<t3)+1]).pr;
		}
	}st; int operator()(int t1, int t2)
	{
		if (t1 == t2) return t1;
		if (wei[t1] > wei[t2]) swap(t1,t2);
		t1 = wei[t1]+1, t2 = wei[t2];
		return f[st.ask(t1,t2)];
	}
}lca;

struct bcs
{
	int f[N];
	void init(int n) {iota(f+1,f+n+1,1);}
	int gf(int x) {return ((f[x] == x) ? x : (f[x] = gf(f[x])));}
	void mg(int a, int b)
	{
		if ((a = gf(a)) == (b = gf(b))) return;
		f[b] = a;
	}
}s;

int dis(int a, int b)
{
	int c = lca(a,b);
	return dep[a] + dep[b] - 2*dep[c];
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> c >> $; while ($--)
	{
		cin >> n >> k; dx = 0;
		for (i = 1; i <= n; i++) e[i].clear();
		for (i = 1; i < n; i++)
		{
			cin >> t1 >> t2;
			e[t1].push_back(t2);
			e[t2].push_back(t1);
		}dfs(1); lca.st.bd();
		
		#define get(i,j) (((i) >> (j))&1)
		if (c <= 3)
		{
			t10 = 11111;
			for (i = 0; i < (2 << n); i += 2)
			{
				if (__builtin_popcount(i) != k) continue;
				vector<int> ds;
				for (j = 1; j <= n; j++)
					if (get(i,j)) ds.push_back(j);
				s.init(n);
				for (int j : ds)
				{
					for (int k : e[j])
					{
						if (get(i,k)) s.mg(j,k);
					}
				}vector<int> ss;
				for (int j : ds)
				{
					ss.push_back(s.gf(j));
				}sort(ss.begin(),ss.end());
				if (unique(ss.begin(),ss.end()) - ss.begin() != 2) continue;
				
				t5 = 0;
				for (j = 1; j <= n; j++)
				{
					t6 = n;
					for (int k : ds)
					{
						t6 = min(t6,dis(j,k));
					}t5 = max(t5,t6);
				}t10 = min(t10,t5);
			}cout << t10 << '\n';
		}		
	}
	return 0;
}
}} signed main() {return llamn::main();}

/*
luogu 1038651 llamn

18:19 完成 c <= 3
18:20 通过两个小样例 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
 
 
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9

*/























