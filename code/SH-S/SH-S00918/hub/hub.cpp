#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+4;
int t,n,cnt,l,k;
int d[N],ans;
vector <int> a[N];
bool f[N];
int kind[N];

void dfs(int u,int fa,int l)
{
	if(d[u]) return;
	d[u] = l;
	for(int i=u; i<a[u].size(); i++)
	{
		int v = a[u][i];
		if(v == fa) continue;
		dfs(v,u,l);
	}
}

signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&t,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1; i<n; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		for(int i=1; i<=n; i++)
			if(!d[i])
				dfs(i,i,++l);
		for(int i=1; i<1<<(n+1); i++)
		{
			cnt = 0;
			for(int j=1; j<=n; j++)
				cnt += i&(1<<j),f[i] = i&(1<<j);
			if(cnt != k) continue;
			for(int j=1; j<=n; j++)
				if(f[j])
					kind[d[j]]++;
			cnt = 0;
			for(int i=1; i<=l; i++)
				cnt += (kind[i]!=0);
			if(cnt <= 2)
			{
				ans = n;
			}
		}
		cout << ans << "\n";
		cout << "\n";
		memset(d,0,sizeof(d));
		memset(kind,0,sizeof(kind));
		l = 0;
		for(int i=1; i<=n; i++) a[i].clear();
	}

	
	return 0;
}
