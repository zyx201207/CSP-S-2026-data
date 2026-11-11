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
string IF = "migrate.in", OF = "migrate.out", IN = R"()";
//string IF, OF, IN = R"()"; 

int subtask; 

signed main()
{
	if(IF != "") freopen(IF.c_str(), "r", stdin);
	if(OF != "") freopen(OF.c_str(), "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	if(IN != "") cin.rdbuf((new istringstream(IN))->rdbuf());
	int T = 10; cin >> subtask >> T;
	while(T--) work();
}

int n, m;
const int maxn = 1e6+10; 
const int D = 22;
int L[D+1][maxn];
int R[D+1][maxn];
int Rsum[maxn];
int Lsum[maxn];
int a[maxn];

int calc(int a, int b) //计算a到b是不是双径对
{
	int cnt = 0;
	if(R[D][a] < b) return 0;
	int A = a; dep(j,D,0) if(R[j][A] < b) A = R[j][A];
	int B = b; dep(j,D,0) if(L[j][B] > a) B = L[j][B];
	cnt += Rsum[R[0][a]] - (R[0][A] == A ? 0 : Rsum[R[0][A]]);
	cnt -= Lsum[L[0][b]] - (L[0][B] == B ? 0 : Lsum[L[0][B]]);
//	for(int i = R[0][a]; i < b; i = R[0][i])
//	{
////		cout << i << " ";
//		cnt += i;
//	} 
//	for(int i = L[0][b]; i > a; i = L[0][i])
//	{
////		cout << -i << " ";
//		cnt -= i;
//	} 
//	cout << "|";
//	pr(a, b, cnt);
//	if(cnt == 1)
//	{
//		pr(a, b);
//	} 
	return cnt == 1;
} 

void work() 
{
//	static int T = 0;
//	T++;
//	pr("---------------------------", T); 
	cin >> n >> m;
	rep(i,1,n) cin >> a[i];
//	mt19937 mt(time(0) ^ clock());
//	m = mt();
//	n = 5000;
//	rep(i,1,n) a[i] = mt()%(100*m);
//	sort(a+1,a+1+n);
//	cout << " !"; outer(a+1, a+1+n);
	{
		int r = 1;
		rep(i,1,n)
		{
			MAX(r, i);
			while(r+1 <= n && a[r+1] <= a[i] + m) r++;
			R[0][i] = r;
		}
	}
	{
		int l = n;
		dep(i,n,1)
		{
			MIN(l, i);
			while(l-1 >= 1 && a[l-1] >= a[i] - m) l--;
			L[0][i] = l;
		}
	} 
//	outer(R[0] + 1, R[0] + 1 + n);
//	outer(L[0] + 1, L[0] + 1 + n);
	rep(j,1,D) rep(i,1,n) R[j][i] = R[j-1][R[j-1][i]];
	rep(j,1,D) rep(i,1,n) L[j][i] = L[j-1][L[j-1][i]];
	rep(i,1,n) Lsum[i] = Rsum[i] = 0;
	rep(i,1,n) Lsum[i] = i + Lsum[L[0][i]];
	dep(i,n,1) Rsum[i] = i + Rsum[R[0][i]];
//	return;
	int ans = 0;
	rep(i,1,n)
	{
		rep(j,i+1,n)
		{
			ans += calc(i, j);
		}
	} 
	pr(ans); 
}
/*
n座岛屿,坐标为xi 
(i, j)能直接到达当且仅当|xi - xj| <= d

令(i, j)为双径对当且仅当，i到j的最短路有两条
求 双径对 个数
首先我们要算s -> t的最短路径数该怎么算
最短路出所有点从起点出发的距离dis 
然后对于所有(i, j)满足dis[j] - dis[i] = 1的点进行转移dp[j] += dp[i]
那么dis数组一定递增
令L[i]表示从i出发，向左一步最远能走到哪 
令R[i]表示从i出发，向右一步最远能走到哪 
那么从S出发，一定有每次走R[i], 那么R[i]为dis[i]对应的连续段的末尾

那么什么时候只有一条最短路，那就是S向右走R数组，T向左走L数组，两路径相等
考虑证明：
考虑有一个点k不在集合里
那么一定会有S贪心跳到k，再从T贪心跳到k
设R跳到k前的一个点是l, L跳到k前的一个点是r
则k在[l, r]内，答案为(k-1) + 1 + 1 > k
证毕

进一步地，我们将R路径表示为r, L路径表示为l,
则对于所有的路径a: i~>j
一定有l[i] <= a[i] <= r[i]

考虑这样一件事情，对于任意的x in [l[i], r[i]] 一定能被访问到左边贪心走，右边贪心走即可

考虑一件特殊的样例
x[i] = i, 询问[l, r]满足长度为奇数
不对，那么就可以走122/212/221
他的L是{2} R是{1}满足条件

我们猜测[i, j]有两条路径的充要条件是sigmaR - sigmaL = 1
因为每根据性质73行每个点都会被访问那么若存在两个点
则会有如下状况
1 [2, 3] 4 [5, 6] 7
Path1: 1 2 4 5 7
Path2: 1 3 4 5 7
Path3: 1 3 4 5 7
Path4: 1 3 4 6 7
就会有多重情况，按照划分点p
1. p < mid
2. p in mid 
3. p > mid
而有至少三种情况
如果没有mid呢？ 
1 [2, 3] [5, 6] 7
case 1: 1 3 6 7
case 2: 1 2 5 7
case 3: 1 3 5 7
case 4: 1 3 5 7
实则还是三种情况
因为他的方案一定可以为LL, RR, RL 

Start Write at 16:08 
deadline 1: 16:20开始写代码 

记得算空间：
L: 2e6 * 23 * 8
R: 2e6 * 23 * 8 
由于四个数组为1.4G装不下，考虑优化Lsum, Rsum
我们记R 
 
9'223'372'036'854'775'807

样例：
1 1
6 2
-4 -3 -2 -1 3 6
 
*/
