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

vtmp Th gnxt(varg) {return arg;} void gnxt(){}
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

#define show(...) showf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#define shoa(...) shoaf(const_cast<char*>(#__VA_ARGS__), __VA_ARGS__);
#else
#define show(...) void(0);
#define shoa(...) void(0);
#endif

int n,m,i,j,k,t0,t1,t2,t3,t4,t5,t6,t7,t8,t9,t10,t11,t12,t13,t14,t15,t16,t17,t18,t19,t20,t21,t22,t23,t24,t25,t26,t27,t28,t29,t30;

int C,$;
ll a[2000100], d;

int dis[2000100], cnt[2000100], c[2000100], nc, l; // l表示最左边的、dis[l] = dis[j] + 1 
void lim(int& x) {x = min(x,3);}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0); 
	cin >> C >> $; while ($--)
	{
		cin >> n >> d;
		for (i = 1; i <= n; i++) cin >> a[i];
		if (n <= 3) {cout << "0\n"; continue;}
		if (C == 11 || C == 12)
		{
			for (i = 2; i <= n && a[i] - a[1] <= d; i++); t1 = i-2;// show(n,i,d)
			if (t1 <= 1) cout << "0\n";
			else cout << max(0,n-(2*t1-1)) << '\n'; continue;
		}if (C == 13 || C == 14) // B性质没有样例，格外凶险 
		{
			int li = 1, ri = 1, lj = 1, rj = 1; t10 = 0;
			for (i = 1, j = 1; i <= n; i++)
			{
				for (; li <= n && a[i] - a[li] > d; li++);
				for (; ri <= n && a[ri] - a[i] <= d; ri++);
				while (lj < ri + 1)
				{
					if (j > n) break; j++; 
					for (; lj <= n && a[j] - a[lj] > d; lj++);
					for (; rj <= n && a[rj] - a[j] <= d; rj++);
				}t10 += (lj == ri+1);				
			}cout << t10 << '\n'; continue;
		}if (C <= 25) // 反正没写出正解 
		{
			t10 = 0;
			for (i = 1; i <= n; i++)
			{
				fill(dis+i+1,dis+n+1,n+1);
				fill(cnt+i+1,cnt+n+1,0);
				fill(c+i,c+n+1,0); nc = 0;
				dis[i] = 0, dis[i-1] = -1, cnt[i] = 1;
				for (j = k = l = i; j <= n; j++)
				{
					for (t1 = k; k <= n && a[k] - a[j] <= d; k++); //show(j,k)
					for (; dis[l] != dis[j]+1 && l < t1; l++);
					c[l] += cnt[j], c[t1] -= cnt[j];// < t1意味着它的dis已经求出，而 >= l说明它仍可被j更新cnt 
					nc += c[j], cnt[j] += nc; // 这里的cnt不用套lim，因为它们已被限制在3以内 
					for (; t1 < k; t1++)
					{
						if (dis[t1] > dis[j] + 1)
							dis[t1] = dis[j] + 1, lim(cnt[t1] = cnt[j]);
						else if (dis[t1] == dis[j] + 1) lim(cnt[t1] += cnt[j]);
					}//show(j,l)
				}for (j = i+1; j <= n; j++) t10 += (cnt[j] == 2);
				//show(i) shoa(dis,n,cnt,n)
			}cout << t10 << '\n'; continue;
		}
	}
	return 0;
}
}} signed main() {return llamn::main();}

/*
luogu 1038651 llamn
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

0 1
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

0 1
10 3
0 3 6 7 8 9 10 11 14 17
应该输出 9 

10 22
0 7 14 21 28 35 42 49 56 63


先想 n^2.考虑暴力连边，拓扑求最短路数量
但边数可以达到 n^2 量级，对每个起点拓扑一次是 n^3
考虑线段树维护disis和cnt
复杂度 n^2 log n，5000得跑 2.5e7 * log n = 3.25e8，能否相信ccf机？

思考 A 性质。显然每个点单向连边数量 <= 1 则 ans = 0
单向边数量为 2:
dis = 3 -> yes
dis = 4 -> no
dis = 5 -> no，有221,212,122三种
单向边数量为 k 时，只有 dis = 2k-1 的点对才算入答案
A solved

B: 中间的一段中枢将岛屿划分为左右段
显然左右两段内部的dis都为1，不能计入答案
那么对于一个在左，一个在右，它们dis不超过2
只有它们dis = 2，且交集恰好为 2 个点时才计入
可以双指针，O(n)
B solved

那么，解法是什么呢？
对于前向连0个的，我们可以将序列在此断开

如果我们从左往右加点，并实时统计前面有几个点与当前点计入ans
发现一个点距离当前点的最短路长度只增不减；

答案点对似乎就是两个 
 
16:38（第二次上厕所回来）:
 O(n^2) geted! 拓扑排序每次只需要向上一个点没有转移的点转移
 赶紧写了，目前已经获得前14个点 
16:48 笑点解析：show宏里没在第一个__VA_ARGS__前面加# 
 
16:54 NO!假了！这个方法只能正确求出dis，不能求cnt
然而我们可以略加修改：如果这个j相比上一个，dis没有变化，那么 

17:30 赌对了！我们对拓扑最短路计数的理解有误，应该 += cnt[源点] 而非 += 1，成功通过 n <= 300的样例
然而还有一个小问题：cnt是否会溢出？ 
借鉴CSP-J 2025 T4，我们在做加法时将所有 >= 3的cnt限制为3 

17:54 写完性质 A, AC对应样例
18:01 写完性质 B 

*/























