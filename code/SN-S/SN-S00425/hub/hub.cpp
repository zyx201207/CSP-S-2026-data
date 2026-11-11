
#include<windows.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
using ll = long long;
const int mod = 998244353;
const int mod2 = 1'000'000'007;
using pii = pair<int, int>;
#define elif else if
#define rep(i,a,n) for(int i = a, i ## end = n; i <= i ## end; i++)
#define dep(i,a,n) for(int i = a, i ## end = n; i >= i ## end; i--)
#define mem(a, x) memset(a, x, sizeof(a))
#define ar(x) (x).begin(), (x).end()
void pr(){cout << flush;}
template<typename T1, typename... T2>void pr(const T1& a, T2&&... b) {cout << a << (sizeof...(b) ? " " : "\n");pr(b...);}
template<typename T1, typename T2> void MAX(T1& a, T2 b) {if(a < b) a = b;}
template<typename T1, typename T2> void MIN(T1& a, T2 b) {if(b < a) a = b;}
template<typename T1, typename T2> void ADD(T1& a, T2 b) {a = ((a + b) % mod + mod) % mod;}
template<typename T> void outer(T a, T b) {for(;a != b;++a) cout << *a << " \n"[next(a) == b];}
template<typename T> void inner(T a, T b) {for(;a != b;++a) cin >> *a;}
template<typename T> void outer(T v) {outer(ar(v));}
template<typename T> void operator += (vector<T>& v, const T& b) {v.push_back(b);}
template<class T1, class T2, typename cmp = less<T1>>
using PBDS_map = tree<T1, T2, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template<class T1, typename cmp = less<T1>>  using PBDS_set = PBDS_map<T1, null_type, cmp>;

void work();
string IF, OF, INN = R"()";
int subtask = 0;

signed main()
{
	if(IF != "") freopen(IF.c_str(), "r", stdin);
	if(OF != "") freopen(OF.c_str(), "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	if(INN != "") cin.rdbuf((new istringstream(INN))->rdbuf());
	int T = 1; cin >> subtask >> T;
	while(T--) work();
}

int n, k; 
const int maxn = 1000010;
vector<int> v[maxn];
int ans = 1e18;
int fa[maxn];

void dfs(int x,int f)
{
	fa[x] = f;
	for(auto i : v[x])
	{
		if(i == f)continue;
		dfs(i, x);
	}
}

int du[maxn];
int candel[maxn];
int deled[maxn];
int deledsiz = 0;
int A, B;
queue<int> q, check;

void del(int x) 
{
	//pr("del", x);
	if(deled[x]) return;
	deled[x] = 1; deledsiz++ ; //cout << "!!d" << x; 
	for(auto i : v[x])
	{
		if((i == A && x == B) || (i == B && x == A)) continue;
		if(deled[i]) continue; 
		du[i]--;
		if(candel[i]&&du[i]==0)
		{
			candel[i] = 0;
			del(i);
		}
		else
		{
			check.push(i);
		}
	}
}


void work()
{
	cin >> n >> k;
	if(k >= n-1) return pr(0); 
	rep(i,1,n) v[i].clear();
	rep(i,2,n)
	{
		int a, b;cin >> a >> b;
		v[a] += b;
		v[b] += a;
	}
	dfs(1, 0); 
	rep(x,2,n) //减掉i和父亲的边，计算剩下两颗树距离的最小值 
	{
		rep(i,1,n) candel[i] = deled[i] = 0;
		rep(i,1,n) du[i] = v[i].size();
		du[x]--;
		du[fa[x]]--;
		A = x, B = fa[x];
		deledsiz = 0;
		while(!q.empty())q.pop();
		queue<int>q;
		rep(i,1,n)
		{ 
			if(du[i] == 1)
			{
				q.push(i);
			}
			if(du[i] == 0)
			{
				q.push(i);
			}
		}
	//	pr("X", x);
		int DP = 0;
		while(true)
		{
//			int a; cin >> a;
//			Sleep(1000);
			DP++; 
		//	pr("DP", DP, deledsiz, q.size());
			while(!q.empty())
			{
				auto x = q.front();  q.pop();
				//pr("xxx", x);
				if(deled[x]) continue;
				if(du[x] == 0)
				{
					deled[x] = 1;
					continue;
				}
				du[x]--;
				del(x);
			}
			while(!check.empty())
			{
				int x = check.front(); check.pop();
				if(deled[x]) continue;
				if(du[x] == 0)
				{
					q.push(x);
				}
				elif(du[x] == 1)
				{
					q.push(x);
				}
				else
				{
					candel[x] = 1;
				}
			}
			
			if(deledsiz + k >= n)
			{
			//	pr(deledsiz, n, DP);
				MIN(ans, DP);
				break;
			}
		}
	}
	pr(ans);
}

/*
首先两个点时一定可以
从叶子向上bfs
直到剩两个点

多个点可以每次剪掉一条边，两边做bfs，取最大值 
X 2
DP 1 0
del 1
del 4
del 5
del 2
del 6
del 8
del 10
X 3
DP 1 0
del 1
del 4
del 5
del 2
del 6
del 8
del 10
X 4
DP 1 1
del 5
del 6
del 8
del 10
DP 2 5
DP 3 5
DP 4 5
DP 5 5
DP 6 5
DP 7 5
D
*/
