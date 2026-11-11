#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll M = 1e3 + 7;
constexpr ll N = 5e2 + 7;
ll W[M];
ll K[N];
ll A[N][M];
ll T[N][M];
vector <ll> Edges[M];
ll dis[M];
ll book[N][M];
struct node
{
	ll v,dis,id;
	bool operator <(const node& x)const
	{
		return dis > x.dis;
	}
};
priority_queue <node> Q;
void dijkstra(ll s)
{
	memset(book,0,sizeof(book));
	memset(dis,0x3f,sizeof(dis));
	dis[s] = 0;
	Q.push((node){s,W[s],0});
	while (Q.size())
	{
		node t = Q.top();
		Q.pop();
		ll u = t.v;
//		if (t.id == 1 && u == 1) printf("yes");
		if (book[t.id][u]) continue;
		book[t.id][u] = 1;
		for (ll Edge : Edges[u])
		{
			ll d = 0;
			for (ll i = 1; i <= K[Edge]; i ++)
			{
				ll v = A[Edge][i];
				if (Edge != t.id) d = T[t.id][u] + T[Edge][u];
//				printf("%lld %lld %lld %lld %lld %lld %lld %lld\n",t.dis,t.id,u,Edge,v,T[t.id][u],T[Edge][u],d);
				if (dis[v] > t.dis + d + T[Edge][v] + W[v])
				{
					dis[v] = t.dis + d + T[Edge][v] + W[v];
					Q.push((node){v,t.dis + d,Edge});
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ll n,m,q;
	scanf("%*lld%lld%lld%*lld%lld",&n,&m,&q);
	for (ll i = 1; i <= m; i ++) scanf("%lld",&W[i]);
	for (ll i = 1; i <= n; i ++)
	{
		scanf("%lld",&K[i]);
		for (ll j = 1; j <= K[i]; j ++) scanf("%lld",&A[i][j]),scanf("%lld",&T[i][A[i][j]]),Edges[A[i][j]].push_back(i);
	}
	while (q --)
	{
		ll u,v;
		scanf("%lld%lld",&u,&v);
		dijkstra(u);
		printf("%lld\n",dis[v]);
	}
	return 0;
}
/*

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

*/
