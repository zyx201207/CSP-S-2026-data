#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000100,M = 10010,O = 1010;

int c,n,m,d,q,ts[N];
int x,y;

int idx,h[N],e[N],ne[N],w[N];
bool st[M];
int t[M][O];//第i个点站台到j站厅的时间 
int p[M][O];//第i个点在第j条轨道上的后继 
bool cnt[M][O];//第i个点所在的轨道编号 
ll ans; 

void add(int a,int b)
{
	e[idx] = b,ne[idx] = h[a],h[a] = idx ++;
}
void dfs(int rd,int cur,int pr,ll res) //当前轨道，当前节点，当前总时间 
{	
	if(cur == y){
 
		ans = min(res + t[cur][rd],ans);
		return;
	}
	
	for(int i = h[cur];i != -1;i = ne[i])
	{
		int u = e[i];
		
		if(st[u])continue;
		
		
		if(u != p[cur][rd])
		{

			for(int j = 1;j <= n;j ++)
				if(cnt[cur][j] && j != rd)
				{
					if(p[cur][j] == u)
					{
						st[u] = true;
						dfs(j,u,cur,res + t[cur][j] + t[cur][rd]);
						st[u] = false; 
					}
				}
		}
		if(u == p[cur][rd]){
			
			st[u] = true;
			dfs(rd,u,pr,res);
			st[u] = false;
		}
	}
	return;
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++)cin >> ts[i];
	
	memset(h,-1,sizeof h);
	
	for(int i = 1;i <= n;i ++)
	{
		int k,pr;
		cin >> k;
		for(int j = 1;j <= k;j ++)
		{
			int b,c;
			cin >> b >> c;
			t[b][i] = c;
			p[pr][i] = b; 
			p[b][i] = pr;
			cnt[b][i] = true;
			if(j != 1)
			{
				add(pr,b);
				add(b,pr);
			}
			pr = b;
		} 
	}
	while(q--)
	{
		ans = 1e18;
		memset(st,0,sizeof st);
		
		cin >> x >> y;
		st[x] = true;
		for(int i = 1;i <= n;i ++)
		{
			if(t[x][i] == 0)continue;
			dfs(i,x,0,t[x][i]);
		}
		cout << ans + ts[x] + ts[y] << endl;
	}
	
	return 0;
}
