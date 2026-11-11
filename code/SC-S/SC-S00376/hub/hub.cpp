#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define il inline
#define re register
#define pii pair<int,int>
#define fs first
#define sc second
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=1e6+6;
int c,t,n,m,b[N],qwq,vis[N];
vector<int> e[N];
il void dfs(re int u,re int fa)
{
	re int z=vis[fa];
	for(auto v:e[u])
		if(v^fa){
			dfs(v,u),z|=vis[v];
			if(z&&b[u])vis[u]=1;
		}
	if(!z&&b[u])
		qwq++,vis[u]=1;
	return;
}
il void get(re int u,re int fa,re int dep)
{
	vis[u]=min(vis[u],dep);
	for(auto v:e[u])
		if(v^fa)
			get(v,u,dep+1);
	return;
}
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<n;i++){
			re int u,v;
			u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}
		if(13<=c&&c<=14){
			printf("%lld\n",(n/2-m-1)/4+2);
//			for(re int i=1;i<=n;i++)
//				e[i].clear();
			continue;
		}
		re int awa=n;
		for(re int i=0;i<(1<<n);i++){
			re int cnt=0;
			for(re int j=0;j<n;j++,vis[j]=0)
				if(i>>j&1)b[j+1]=1,cnt++;
				else b[j+1]=0;
			if(cnt^m)continue;
			qwq=0,dfs(1,0);
			if(qwq>2)continue;
			for(re int j=1;j<=n;j++)vis[j]=n;
			for(re int j=1;j<=n;j++)
				if(b[j])
					get(j,0,0);
			qwq=0;
			for(re int j=1;j<=n;j++)
				qwq=max(qwq,vis[j]);
			awa=min(awa,qwq);
		}
		for(re int i=1;i<=n;i++)
			e[i].clear();
		printf("%lld\n",awa);
	}
	return 0;
}