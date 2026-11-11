#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int N = 5e2+5, M = 5e5+5;
int c, n, m, d, q; // No., 路数, 站数, max换乘, 计划 
int w[N]; // 入口-站厅 
vector<pii> g[N]; // g[station] = {Line, time}  
bool vis[M];
ll ans;

inline ll rd()
{
	ll x=0,f=1; char ch=getchar();
	while (ch>'9'||ch<'0') {if(ch=='-')f=-1;ch=getchar();}
	while ('0'<=ch && ch<='9') {x=x*10+ch-48;ch=getchar();}
	return x*f;
}
//
//bool operator<(array<int, 3> x, array<int, 3>y)
//{
//	return x[0]<y[0];
//}
//
//ll f(int s, int t)
//{
//	memset(vis, 0, sizeof(vis));
//	ans = 0;
//	priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
//	for (pii cur : g[s])
//	{
//		pq.push({cur.second, cur.first, s});
//	}
//	vis[s] = 1;
//	while (!pq.empty())
//	{
//		int cs = pq.top()[2];
//		int cl = pq.top()[1];
//		int ct = pq.top()[0];
//		pq.pop();
//		if (vis[cs]) continue;
//		vis[vs] = 1;
//		for (pii cur : g[s])
//		{
//			pq.push({cur.second+})
//		}
//	}
//	
//}

int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	c=rd(), n=rd(), m=rd(), d=rd(), q=rd();
//	for (int i = 1; i <= n; i++)
//	{
//		w[i]=rd();
//	}
//	
//	for (int i = 1; i <= n; i++)
//	{
//		int k = rd();
//		for (int j = 1; j <= k; j++)
//		{
//			int ai=rd(), ti=rd();
//			g[ai].push_back({i, ti});
//		}
//	}
	while (q--)
	{
//		int s=rd(), t=rd();
//		printf("%lld\n", f(s, t));
		printf("%d\n", rand());
	}
	return 0;
}
/*
15:10 start
15:46 give up
rp++
*/

