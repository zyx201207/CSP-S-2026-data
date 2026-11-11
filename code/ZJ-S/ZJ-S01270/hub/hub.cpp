#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10,M = 20;
vector<int> e[N];
int f[N][M],dep[N];
void dfs(int u,int fa)
{
	f[u][0] = fa;
	for(int i = 1; i <= 19; i ++) f[u][i] = f[f[u][i - 1]][i - 1];
	dep[u] = dep[fa] + 1;
	for(auto x : e[u])
	{
		if(x == fa) continue;
		dfs(x,u);
	}
}
int lca(int x,int y)
{
	if(dep[x] < dep[y]) swap(x,y);
	for(int i = 19; i >= 0; i --)
		if(dep[x] - dep[y] >= (1 << i)) x = f[x][i];
	if(x == y) return x;
	for(int i = 19; i >= 0; i --)
		if(f[x][i] != f[y][i]) x = f[x][i],y = f[y][i];
	return f[x][0];
}
int dis(int x,int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x,y)];
}
int st[N];
int n,m;
void col(int u,int k)
{
	st[u] = k;
	for(auto x : e[u])
		if(st[x] == 1) col(x,k);
}
bool check(int x)
{
	if(m == 2)
	{
		for(int i = 1; i <= n; i ++)
			for(int j = i + 1; j <= n; j ++)
			{
				int flag = 1;
				for(int k = 1; flag && k <= n; k ++)
					if(min(dis(k,i),dis(k,j)) > x)flag = 0;
				if(flag) return 1;
			}
		return 0;
	}
	if(m <= 10)
	{
		for(int i = 1; i < (1 << n); i ++)
		{
			if(__builtin_popcount(i) != m) continue;
			for(int j = 1; j <= n; j ++) st[j] = i >> (j - 1) & 1;
			int cc = 1;
			for(int j = 1; j <= n; j ++)
				if(st[j] == 1) col(j,++ cc);
			if(cc <= 3)
			{
				int ok = 1;
				for(int j = 1; ok && j <= n; j ++)
					if(!st[j])
					{
						int flag = 0;
						for(int k = 1; !flag && k <= n; k ++)
							if(st[k] && dis(k,j) <= x) flag = 1;
						if(!flag) ok = 0;
					}
				if(!ok) continue;
				return 1;
			}
		}
		return 0;
	}
//	for(int i = 1; i <= n; i ++)
//		for(int j = i + 1; j <= n; j ++)
//		{
//			for(int k = 1; k <= n; k ++)
//				if(min(dis(k,i),dis(k,j)) > x) 
//		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int id,t;
	cin>>id>>t;
	while(t --)
	{
		cin>>n>>m;
		for(int i = 1,x,y; i < n; i ++) cin>>x>>y,e[x].push_back(y),e[y].push_back(x);
		dfs(1,0);
		int l = 0,r = n;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(check(mid)) r = mid;
			else l = mid + 1;
		}
		cout<<l<<'\n';
		for(int i = 1; i <= n; i ++) e[i].clear(),e[i].shrink_to_fit();
	}
	return 0;
}
//16:55 15pts
//dfz?

/*
其实我自己装了搜狗但是太卡了 
weishenmenizongshikansibujingyidehushi
woqueyizhiduininameguzhi
huibuhuizhebenlaijiushiyigerendegushi
zhibuguotouxialenideyingzi
niyexuhuifaxianwohaoxiangzongshiwusuoshishi
qishikanzheyigerenyijingchengweixiguandezishi
jimozhongkanzhenizaishenbiandemeitiandouhaoxiangjieri
kanzhenideshihouzongshiganjuebudaoshijianfeishi
wozhidaonitoulaiyipieyouyipiewoqueqidaizhushi
wobuxiangtingdaonaixezuoweijiekoudedanshi
rangwomenhuidaonaxiedanchunderizilinapazhishichangshi


*/
