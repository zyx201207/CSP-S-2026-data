#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 505,M = 5e5 + 5;
ll c,n,m,d,a[M],q,fg[N],dis[N][N];
struct node
{
	ll pos,w;
};
vector <node> e[N],b[M];
void init()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(i == j)
			{
				dis[i][i] = 0;
				continue;
			}
			dis[i][j] = 1e18;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		for(node j : b[i])//floyd不会写 
		{
			for(node k : b[i])//O((q+m)*d^2+n^3)希望能过 
			{
				if(j.pos == k.pos)
				{
					continue;
				}
				dis[j.pos][k.pos] = min(dis[j.pos][k.pos],j.w + k.w);
				dis[k.pos][j.pos] = dis[j.pos][k.pos];
			}
		}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j < i;j++)
		{
			for(int k = 1;k <= n;k++)
			{
				if(k == i || k == j)
				{
					continue;
				}
				dis[j][i] = dis[i][j] = min(dis[i][j],dis[i][k] + dis[j][k]);
			}
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(ll i = 1;i <= m;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(ll i = 1;i <= n;i++)
	{
		ll k;
		scanf("%lld",&k);
		for(ll j = 1;j <= k;j++)
		{
			ll x,y;
			scanf("%lld%lld",&x,&y);
			e[i].push_back({x,y});
			b[x].push_back({i,y});
		}
	}
	init(); 
	while(q--)
	{
		ll x,y,ans = 1e18;
		scanf("%lld%lld",&x,&y);
		for(node i : b[x])
		{
			for(node j : b[y])
			{
				ans = min(ans,a[x] + a[y] + dis[i.pos][j.pos] + i.w + j.w);
			}
		}
		printf("%lld\n",ans);
	}
}
