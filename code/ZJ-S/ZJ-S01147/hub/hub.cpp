#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int c , T , n , k , h[N] , fa[N];
bool b[N];
struct point
{
	int u , v , nxt;	
};
point p[N];
int cnt = 0;

void adde(int u , int v)
{
	p[++cnt].u = u; p[cnt].v = v;
	p[cnt].nxt = h[u]; h[u] = cnt;
}

void dfs(int u)
{
	for(int i = h[u] ; i ; i = p[i].nxt)
	{
		int v = p[i].v; if(v == fa[u]) continue;
		fa[v] = u; dfs(v);
	}
}

void find(int u , int &now , int &ans)
{
	for(int i = h[u] ; i ; i = p[i].nxt)
	{
		int v = p[i].v; if(v == fa[u]) continue;
		int num = 0 , res = 0;
		find(v , num , res);
		if(!b[u]) now = max(now , num + 1) , res = max(now , res);
		else now = 0;
		ans = max(ans , res);
		
	}
}

signed main()
{
	freopen("hub.in" , "r" , stdin);
	freopen("hub.out" , "w" , stdout);
	scanf("%d %d" , &c , &T);
	while(T--)
	{
		scanf("%d %d" , &n , &k);
		for(int i = 1 ; i <= n ; i++)
		{
			int u , v; scanf("%d %d" , &u , &v);
			adde(u , v); adde(v , u);
		} dfs(1);
		int ans = N + 10;
		for(int key = 1 ; key <= 1 << n ; key++)
		{
			int cnt = 0;
			for(int i = 1 ; i <= n ; i++) if((1 << (i - 1)) & key) b[i] = 1 , cnt++;
			if(cnt != k) continue;
			int x = 0 , res = 0; find(1 , x , res);
			ans = min(ans , res);
			cout << ans << '\n';
		}
		printf("%d\n" , ans);
	}
	return 0;
}
