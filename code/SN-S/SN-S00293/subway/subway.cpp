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

int c,d,$, w[500100];
#define pii pair<int,ll>
#define to first
#define t second
vector<pii> zs[500100];
ll dis[510][510],ans;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	cin >> c >> n >> m >> d >> $;
	for (i = 1; i <= m; i++) cin >> w[i];
	for (i = 1; i <= n; i++)
	{
		cin >> k; while (k--)
		{
			cin >> t1 >> t2;
			zs[t1].push_back({i,t2});
		}fill(dis[i]+1,dis[i]+n+1,LL.max() >> 2); dis[i][i] = 0;
	}
	for (i = 1; i <= m; i++)
	{
		for (pii j : zs[i])
		{
			for (pii k : zs[i])
			{
				if (j == k) break;
				dis[j.to][k.to] = min(dis[j.to][k.to], j.t + k.t);
				dis[k.to][j.to] = min(dis[k.to][j.to], j.t + k.t);
			}
		}
	}for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while ($--)
	{
		cin >> t1 >> t2; ans = LL.max();
		for (pii j : zs[t1])
		{
			for (pii k : zs[t2])
			{
				ans = min(ans, dis[j.to][k.to] + j.t + k.t);
			}
		}cout << (ans + w[t1] + w[t2]) << '\n';
	}
	return 0;
}
}} signed main() {return llamn::main();}

/*
luogu 1038651 llamn

CCF掌握了曲率引擎技术，可以瞬间在地铁内移动 
考虑在每个站点存储哪些地铁线路经过了站点
然后对于同一个站点内的d个线路，这些线路之间都连一条边，边权为对应的两个t之和
该操作复杂度为 sum k * d = 1e7
然后floyd求出线路之间两两最短路，n^3 = 1.25e8
（由于完全图，dij只会更慢，相信CCF神机） 
查询时d^2枚举两个站点的线路，qd^2 = 4e7
总复杂度 O(m + sumk*d + n^3 + qd^2) 
15:00
15min就想出来了，给到一个绿 
15:17 完成初稿

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2 

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

15:23 AC全部大洋里 

*/























