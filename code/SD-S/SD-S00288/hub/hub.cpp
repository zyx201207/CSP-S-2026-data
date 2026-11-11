#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int testid,n,k;
vector<int> vc[N];
namespace baoli
{
	bool iskey[N],vis[N];
	inline void D(int u,int fa)
	{
		vis[u]=1;
		for(int v:vc[u])
			if(v!=fa&&iskey[v]) D(v,u);
	}
	int dfs(int u,int fa,int d)
	{
		if(iskey[u]) return d;
		int ans=100;
		for(int v:vc[u])
			if(v^fa) ans=min(ans,dfs(v,u,d+1));
		return ans;
	}
	
	void solve()
	{
		int ans=100;
		for(int S=0;S<(1<<n);S++)
		{
			if(__builtin_popcount(S)!=k) continue;
			for(int i=0;i<n;i++) if(S>>i&1) iskey[i+1]=1;
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(iskey[i]&&!vis[i]) cnt++,D(i,0);
			if(cnt<=2)
			{
				int mx=0;
				for(int i=1;i<=n;i++) mx=max(mx,dfs(i,0,0));
				ans=min(ans,mx);
			}
			for(int i=1;i<=n;i++) vis[i]=0;
			for(int i=0;i<n;i++) if(S>>i&1) iskey[i+1]=0;
		}
		printf("%d\n",ans);
	}
}

namespace A
{
	bool iskey[N],vis[N];
	void solve()
	{
		int m=n/2,ln=k/2,rn=k-ln,ans=1e5;
		int lp=m/4,rp=m/4*3;
		for(int i=max(1,lp-4);i<=min(m+1,lp+4);i++)
			for(int j=max(1,rp-4);j<=min(m+1,rp+4);j++)
			{
				int tlp=max(1,i-ln/2);
				for(int p=tlp;p<=min(m,tlp+ln-1);p++) iskey[p]=1;
				int trp=max(1,j-rn/2);
				for(int p=trp;p<=min(m,trp+rn-1);p++) iskey[p]=1;
				queue<pair<int,int> > q;
				for(int i=1;i<=n;i++)
					if(iskey[i]) q.push({i,0}),vis[i]=1;
				int maxd=0;
				while(q.size())
				{
					int u=q.front().first,d=q.front().second;q.pop();
					maxd=max(maxd,d);
					for(int v:vc[u])
						if(!vis[v]) vis[v]=1,q.push({v,d+1});
				}
				ans=min(ans,maxd);
				for(int i=1;i<=n;i++) iskey[i]=vis[i]=0;
			}
		swap(ln,rn);
		for(int i=max(1,lp-4);i<=min(m+1,lp+4);i++)
			for(int j=max(1,rp-4);j<=min(m+1,rp+4);j++)
			{
				int tlp=max(1,i-ln/2);
				for(int p=tlp;p<=min(m,tlp+ln-1);p++) iskey[p]=1;
				int trp=max(1,j-rn/2);
				for(int p=trp;p<=min(m,trp+rn-1);p++) iskey[p]=1;
				queue<pair<int,int> > q;
				for(int i=1;i<=n;i++)
					if(iskey[i]) q.push({i,0}),vis[i]=1;
				int maxd=0;
				while(q.size())
				{
					int u=q.front().first,d=q.front().second;q.pop();
					maxd=max(maxd,d);
					for(int v:vc[u])
						if(!vis[v]) vis[v]=1,q.push({v,d+1});
				}
				ans=min(ans,maxd);
				for(int i=1;i<=n;i++) iskey[i]=vis[i]=0;
			}
		printf("%d\n",ans);
	}
}

namespace luangao
{
	void solve()
	{
		cerr<<-1<<endl;
		//ÖÂ¾´´«Ææ cerr<<-1;
	}
}

void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) vc[i].clear();
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		vc[u].push_back(v);
		vc[v].push_back(u);
	}
	if(n==k) return puts("0"),void();
	if(testid<=3) baoli::solve();
	if(testid==13||testid==14) A::solve();
	else luangao::solve();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;scanf("%d%d",&testid,&T);
	while(T--) solve();
	return 0;
}
//ºìºìºìºÚ£¿£¿£¿ 
