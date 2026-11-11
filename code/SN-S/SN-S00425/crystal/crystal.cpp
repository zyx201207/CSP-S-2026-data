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
string IF = "crystal.in", OF = "crystal.out", IN = R"()";
//string IF = "", OF = "", IN = R"()";

signed main()
{
	if(IF != "") freopen(IF.c_str(), "r", stdin);
	if(OF != "") freopen(OF.c_str(), "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	if(IN != "") cin.rdbuf((new istringstream(IN))->rdbuf());
	int T = 1; //cin >> T;
	while(T--) work();
}

int n, m;
const int maxn = 5e5 + 10;
int a[maxn];
int sum[maxn];

void work()
{
	cin >> n >> m;
	inner(a+1, a+1+n);
	sort(a+1, a+1+n);
	rep(i,1,n) sum[i] = sum[i-1] + a[i];
//	outer(sum+1,sum+1+n);
	int r = 0, ans = 0;
	rep(i,1,n)
	{
		MAX(r, i);
		while(r+1 <= n && (r+1-i+1) * a[r+1] - (sum[r+1] - sum[i-1]) <= m) r++;
		MAX(ans, r-i+1);
//		pr(i, r, (r+1-i+1) * a[r+1] - (sum[r+1] - sum[i]));
	}
	pr(ans);
}

/*
Writen overed by 14:50
*/
