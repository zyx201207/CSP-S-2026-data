// RP ++;
// by MLE_Automaton
// subscribe MLE_Automaton please
// jodio9 yao bao sha wo le
#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a),END##i=(b);i<=END##i;++i)
#define pre(i,a,b) for(int i=(a),END##i=(b);i>=END##i;--i)
#define pb push_back
using namespace std;
typedef long long ll;
template<typename T> inline void chmin(T &x, T y) { x = min(x, y); }
template<typename T> inline void chmax(T &x, T y) { x = max(x, y); }
// am i gonna ac T3?
constexpr int N = 2e6 + 5;
constexpr ll INF = 0x3f3f3f3f3f3f3f3fll;
int T, n, nxt[N], lst[N], nn[N], nn1[N] ll m, a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	scanf("%*d%d", &T);
	while (T --)
	{
		scanf("%d%lld", &n, &m);
		rep(i, 1, n) scanf("%lld", &a[i]);
		a[0] = -INF;
		a[n + 1] = INF;
		rep(i, 0, n + 1) lst[i] = nxt[i] = nn[i] = nn1[i] = 0;
		int j1 = 1, j2 = 1;
		rep(i, 1, n)
		{
			while (j1 <= n && a[j1] < a[i] - m) ++ j1;
			while (j2 <= n && a[j2 + 1] <= a[i] + m) ++ j2;
			lst[i] = j1; nxt[i] = j2;
		}
//		rep(i, 1, n) printf("%d %d\n", lst[i], nxt[i]);
		// wei yi neng zou dao na
//		llen[0] = nlen[n + 1] = 0;
//		rep(i, 1, n) llen[i] = nxt[i - 1] == i ? llen[i - 1] + 1 : 1;
//		pre(i, n, 1) nlen[i] = lst[i + 1] == i ? nlen[i + 1] + 1 : 1;
		// these are wrong
		// jump over greedily and how to check the path is unique?
		// 1. if dist is in its range then its unique
		// 2. if it can make a unique jump then dist's dist is also the solution
		// 3. else? if nxt - 1 cant reach somewhere nxt can reach then its great.
		// 4. anymore? how to implement?
		// the first layer is a point and the second layer is a range, how about the third layer?
		// it is also a range. but are the layers connected? nope.
		// maybe a dp, f[i][j] is now to i, j is the count of double paths
		// lets try it
		// do we need a segt to maintain the dp array?
		// f[i][0] -> every f[j][0] that i can reach j uniquely
		// wait. how do i transfer this?
		// i -> i + 1 -> i + 2 and i can go to i + 2
		// i -> points that nxt[i] can reach but nxt[i - 1] cant reach?
		// nope.
		// we notice that a unique jump is i->nxt[i]->nxt[nxt[i]]...->any point can be reached
		// is it correct?
		// no.
		// i can jump to j uniquely and go pass 3 points only when nxt[i] == lst[j]?
		// its correct!
		// so my original idea is correct?
		// the bottleneck is how to find the point i can go to uniquely
		// keep jumping to nxt[i] == lst[j] and for every middle point k+1 to nxt[k] is also can be chosen
		// i think this is right.
		// its wrong.
		// only the right point of the range can be considered
		// but how can i calculate those who have same lsts?
		// im wrong i can only jump to lst[k] == i like these
		lst[0] = nxt[0] = lst[n + 1] = nxt[n + 1] = 0;
		j1 = j2 = n;
		pre(i, n, 1)
		{
//			if (nxt[i] == nxt[i + 1])
//			{
//				nl[i] = nl[i + 1];
//				nr[i] = nr[i + 1];
//				nn[i] = nn[i + 1] + 1; // i can be the dist
//				continue;
//			}
			while (j1 && lst[j1] > i) -- j1; // j1: last lst <= i
			while (j2 && lst[j2] >= i) -- j2; // j2: last lst < i 
//			nl[i] = j1; nr[i] = j2; nn[i] = 1;
//			int pl = nl[i], pr = nr[i];
//			while (pr <= n)
//			{
//				nn[i] += pr - pl + 1;
//				pl = max(nl[pl], pr + 1); pr = nr[pr];
//			}
//			nn[i] += pr - pl;
			if (j1 > j2) nn[i] = nn[j1] + j1 - j2;
			else nn[i] = 1;
		}
		j1 = j2 = 1;
		rep(i, 1, n)
		{
			while (j1 <= n && nxt[j1] < i) ++ j1; // first nxt >= i
			while (j2 <= n && nxt[j2] <= i) ++ j2; // first nxt > i
//			if (n == 5 && m == 3 && i == 2) printf("%d %dqwq\n", j1, j2);
			if (j1 < j2) nn1[i] = nn1[j1] + j2 - j1;
			else nn1[i] = 1
		}
//		int lll = 1;
//		rep(i, 2, n)
//		{
//			if (lst[i] != lst[i - 1])
//			{
//				rep(j, lll, i - 1) qq[j] = i - 1;
//				lll = i;
//			}
//		}
//		rep(j, lll, n) qq[j] = n;
//		rep(i, 1, n) printf("%d%c", qq[i], " \n"[i == n]);
//if (n == 5 && m == 3)
//{
//	rep(i, 1, n) printf("%d %d\n", nn[i], nn1[i]);
//}
		j1 = j2 = 1; ll ans = 0;
		rep(i, 1, n)
		{
			while (j1 <= n && (j1 <= nxt[i] || lst[j1] < nxt[i] - 1)) ++ j1;
			while (j2 <= n && (j2 <= nxt[i] || lst[j2] <= nxt[i] - 1)) ++ j2;
			if (nxt[i] > i + 1 && j1 < j2)
			{
				ans += 1ll * nn1[i] * (j2 - j1 - 1 + nn[j2 - 1]);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
6 3
0 1 2 3 4 7
5 5 5 5 6 6
1 1 1 1 2 5
it has no pair
why does my program outputs 2?
*/
/*
6 4
-3 0 1 2 3 4
3 6 6 6 6 6
1 1 1 2 2 2
its 3 but i output 1
*/
/*
5 3
-3 0 2 3 4
2 4 5 5 5
1 1 2 2 3
/*
/*
8 3
0 1 2 4 8 10 11 13
3 4 4 4 7 8 8 8
1 1 1 2 5 5 5 6
*/
