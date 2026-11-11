#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int> 
#define for1(l,r,name) for(int name = l;name <= r;name++)
#define for2(r,l,name) for(int name = r;name >= l;name--)
using namespace std;
const int N = 405,S = 1e6;
int cas,n,m,d,q,w[N],k[505],tmp,u,v,cnt,h[S],dis[S],l,r;
vector<int> a[505],t[505];
bool vis[S];
struct node{
	int v,w,nxt;
}e[2 * S];
priority_queue<PII,vector<PII>,greater<PII>> pq;
void add(int u,int v,int w)
{
	e[++cnt] = {v,w,h[u]};
	h[u] = cnt;
}
void dij(int uu)
{
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	dis[uu] = 0;
	pq.push({0,uu});
	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = h[u];i;i = e[i].nxt)
		{
			int v = e[i].v,w = e[i].w;
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				pq.push({dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> cas >> n >> m >> d >> q;
	for1(1,m,i) cin >> w[i];
	for1(1,n,i)//第i条线路
	{
		cin >> k[i];
		for1(1,k[i],j)
		{
			cin >> tmp;
			a[i].push_back(tmp);
			cin >> tmp;
			t[i].push_back(tmp);
		}
	}
	//建图
	for1(1,n,i)//第i条线路
	{
		for1(0,k[i] - 1,j)
		{
			u = (i + 1) * m + a[i][j];
			add(a[i][j],u,t[i][j]);
			add(u,a[i][j],t[i][j]);
			if(j > 0)
			{
				v = (i + 1) * m + a[i][j - 1];
				add(u,v,0);
				add(v,u,0);
			}
		}
	}
	while(q--)
	{
		cin >> l >> r;
		dij(l);
		cout << w[l] + dis[r] + w[r] << '\n';
	}
	return 0;
}