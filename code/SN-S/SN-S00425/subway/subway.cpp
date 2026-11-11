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
string IF = "subway.in", OF = "subway.out", IN = R"()";
//string IF, OF, IN = R"()";

signed main()
{
	if(IF != "") freopen(IF.c_str(), "r", stdin);
	if(OF != "") freopen(OF.c_str(), "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	if(IN != "") cin.rdbuf((new istringstream(IN))->rdbuf());
	int T = 1; //cin >> T;
	while(T--) work();
}

int T, n, m, d, q;
int dis[510][510];  
int w[500010];
vector<pii> v[500010];//fir: 线路 sec: 站台距离 

int calc(int a, int b) // 站台a到站台b的最小距离 
{
	int ans = 1e18; 
	for(auto A : v[a]) 
	{
		int j = A.first;
		int tj = A.second;
		for(auto B : v[b]) 
		{
			int k = B.first;
			int tk = B.second;
			MIN(ans, dis[j][k] + tj + tk);
		}
	}
	return ans;
}

void work()
{
	cin >> T >> n >> m >> d >> q;
	rep(i,1,m)
	{
		cin >> w[i];
	}
	rep(i,1,n)
	{
		int k; cin >> k;
		rep(j,1,k)
		{
			int a, t; cin >> a >> t;
			v[a] += pii{i, t};
		}
	}
	mem(dis, 0x3f);
	rep(i,1,n) dis[i][i] = 0; 
	rep(i,1,m) for(auto j : v[i]) for(auto k : v[i]) MIN(dis[j.first][k.first], j.second+k.second);
	rep(i,1,n) rep(j,1,n) rep(k,1,n) MIN(dis[j][k], dis[j][i] + dis[i][k]);
	rep(i,1,q)
	{
		int a, b; cin >> a >> b;
		cout << w[a] + w[b] + calc(a, b) << "\n";
//		pr(w[a] + w[b] + calc(a, b));
	}
	cout << flush;
}

/*
m个站台，n条线路
每个地铁口i到站台的时间是wi
每个站台i到地铁口j的时间是a[i][j]
每个站台最多只会链接20个线路
线路上的任意点的时间为0 
求站点i到站点j的最小时间是多少

站台i到站台j的最小距离 等价于 线路i到线路j的最小距离
直接最短路
dis[i][j]表示线路i到线路j的距离
初始值枚举站台i 
线路j和线路k的边权是min(a[i][j] + a[i][k]) 

Writen overed by 15:21
*/
