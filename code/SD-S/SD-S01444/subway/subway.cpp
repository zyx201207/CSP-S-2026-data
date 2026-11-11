#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,Q;
int w[N];
int k[N];
int jz[N];
int ai = 0;
vector<int> cz[N];
int vis[N];
ll dis[N];
int sk[N],top;
struct node
{
	int v,nxt;
	ll w;
}e[N<<1];//这个也是 
int tot,h[N];//这么大显然是小的 
struct nod
{
	int u;
	ll w;
	bool operator < (const nod& b) const
	{
		return w>b.w;	
	};
};
int read()
{
	char c = getchar();
	int x = 0,f = 1;
	while(c < '0' || c > '9')
	{
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9')
	{
		x = (x<<1) + (x<<3) + (c^48);
		c = getchar();
	}
	return x*f;
}
void add(int x,int y,ll w)
{
//	cout<<x<<" "<<y<<" "<<w<<endl;
	e[++tot].nxt = h[x];
	e[tot].v = y;
	e[tot].w = w;
	h[x] = tot;
}
ll dij(int st,int ed)
{
//	memset(dis,0x3f,sizeof dis);//可以优化，即只改被改过的
//	memset(vis,0,sizeof vis);
	while(top)
	{
		dis[sk[top]] = INF;
		vis[sk[top]] = 0;
		top--;	
	} 
	priority_queue<nod> q;
	while(!q.empty()) q.pop();
	sk[++top] = st;
	q.push({st,0}); 
	dis[st] = 0;
	while(!q.empty())
	{
		nod u = q.top();
		q.pop();
		if(u.u == ed)
			return dis[u.u];
		if(vis[u.u]) continue;
		vis[u.u] = 1;
		for(int i = h[u.u];~i;i = e[i].nxt)
		{
			int v = e[i].v;
			ll w = e[i].w;
		//	cout<<u<<" "<<v<<" "<<dis[u.u]<<
			if(dis[u.u] + w < dis[v])
			{
				dis[v] = dis[u.u] + w;
				sk[++top] = v;
				q.push({v,dis[v]});
			}
		}
	}
	return INF;
}
int main()
{
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(dis,0x3f,sizeof dis);//可以优化，即只改被改过的
	memset(vis,0,sizeof vis);
	memset(h,-1,sizeof h);
	c = read();
	n = read();
	m = read();
	d = read();
	Q = read();
	for(int i = 1;i <= m;++i)
		w[i] = read();
	for(int i = 1;i <= n;++i)
	{
		k[i] = read();
		for(int j = 1;j <= k[i];++j)
		{
			int x,y;
			x = read();
			y = read();
			ai++;
			for(int p = 0;p < cz[x].size();++p)
			{
				int u = cz[x][p];
				add(u,ai,1ll*(y+jz[u])),add(ai,u,1ll*(y+jz[u]));
			}
			cz[x].push_back(ai);	
			if(j != 1) 
			{
				add(ai-1,ai,0);
				add(ai,ai-1,0);
			}
			jz[ai] = y;
		}
		add(ai,ai-(k[i])+1,0);
		add(ai-k[i]+1,ai,0);
	}
	while(Q--)
	{
		int x,y;
		x = read();
		y = read();
		ll ans = INF;
		for(int i = 0;i < cz[x].size();++i)
		{
			for(int j = 0;j < cz[y].size();++j)
			{
				ll oo = dij(cz[x][i],cz[y][j]);
				oo = oo + jz[cz[x][i]] + jz[cz[y][j]];
			//	cout<<cz[x][i]<<" "<<cz[y][j]<<" "<<oo<<endl;
				if(oo<ans) ans = oo;
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
//	cout<<cz[123].size()<<" "<<cz[131].size()<<endl;
//	cout<<w[123]<<" "<<w[131]<<endl;
	return 0;
} 

