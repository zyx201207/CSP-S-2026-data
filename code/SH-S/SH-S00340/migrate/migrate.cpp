#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 2e6+5, M = 5e3+5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll n, d;
ll a[N];
bool vis[N];
ll ans;

inline ll rd()
{
	ll x=0,f=1; char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}

ll find_st_len(int u, int v, ll cnt=0)
{
//	printf("finding\n");
	if (u >= v) return cnt;
	int mx = upper_bound(a+u, a+n+1, a[u]+d)-a-1;
	if (mx == u) return -1;
	return find_st_len(mx, v, cnt+1);
}

ll dfs(int u, int v, ll st_len, int len=0)
{
//	printf("searching\n");
	if (len > st_len || u > v) return 0;
	if (u == v && len <= st_len) return 1;
	ll cnt = 0;
	for (int i = u+1; i <= v; i++)
	{
		if (a[i]-a[u] <= d)
		cnt += dfs(i, v, st_len, len+1);
		if (cnt > 2) break;
	}
	return cnt;
}

inline ll dist(int u, int v) { return a[v]-a[u]; }

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c=rd(), t=rd();
	c=11;
	while (t--)
	{
		n=rd(), d=rd();
//		printf("%lld %lld ", n, d);
		for (int i = 1; i <= n; i++)
		{
			a[i] = rd();
		}
		if (c == 11 || c == 12)
		{ // case A
			ll gc = a[2]-a[1];
			if (n < 2*d/gc-1 || d <= gc)
			{
				printf("0\n");
//				continue;
			}
			printf("%lld\n", n-2*d/gc+1);
//			continue;
		}
//		if (c == 13 || c == 14)
//		{ // case B
//			ans = 0;
//			ll lf = a[1], rt = a[n];
//			if (a[n]-a[1] <= d) { printf("0\n"); continue; }
//			int u = 1, v = upper_bound(a+1, a+n+1, a[u]+d)-a;
//			for (int u = 1; u <= n; u++)
//			{
//				int v = upper_bound(a+u, a+n+1, a[u]+d)-a;
//				if (v > n) break;
//				for (int i = v; i <= n; i++)
//				{
//					if (i-u>3 || dist(u,u+2)>d || dist(u+1, i)>d) break;
//					if (i-u<3) continue;
//					printf("%d %d\n", u, i);
//					ans++;
//				}
//			}
//			printf("%lld\n", ans);
//			continue;
//		}
		// BF
		ans = 0;
		for (int u = 1; u < n; u++)
		{
			for (int v = u+1; v <= n; v++)
			{
				ll st_len = find_st_len(u, v);
				if (st_len == -1) break;
				if (dfs(u, v, st_len) == 2) ans++;
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}
/*
rp++
15:47 start
16:26 8pts A
16:52 12pts 1-2,11-12
17:53 giveup B
*/

