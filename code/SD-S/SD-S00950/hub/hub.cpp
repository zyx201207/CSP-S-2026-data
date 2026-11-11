#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,C,T,k,d[1000009],dep[1000009],c[1000009],g[4009][4009],dfn[1000009],t,dp[1000009],st[21][1000009];
vector<int> a[1000009];
void dfs(int u,int fa,int x) {
	dep[u]=dep[fa]+1;
	if(dep[u]>=x) d[u]=1;
	for(auto v:a[u]) {
		if(v==fa) continue;
		dfs(v,u,x);
	}
}
void dfs1(int u,int x) {
	d[u]=x;
	for(auto v:a[u])
		if(d[v]==1) dfs1(v,x);
}
void dfs2(int u,int fa) {
	st[0][dfn[u]=++t]=fa;
	dp[u]=dp[fa]+1;
	for(auto v:a[u]) {
		if(v==fa) continue;
		dfs2(v,u);
	}
}
int get(int u,int v) {
	return dfn[u]<dfn[v] ? u:v;
}
int lca(int u,int v) {
	if(u==v) return 0;
	int uu=u,vv=v;
	if((u=dfn[u])>(v=dfn[v])) swap(u,v);
	int l=(v-u++);
	int fa=get(st[l][u],st[l][v-(1<<l)+1]);
	return dp[uu]-dp[fa]+dp[vv]-dp[fa];
}
struct aa {
	int u,v,w;
} p[1000009];
bool cmp(aa a,aa b) {
	return a.w<b.w;
}
int find(int x) {
	return x==c[x] ? x:c[x]=find(c[x]);
}
int cheak(int x) {
	dep[0]=-1;
	for(int i=1; i<=n; i++) d[i]=0;
	for(int i=1; i<=n; i++) if(!d[i]) dfs(i,0,x);
	cout<<x<<endl;
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	cout<<endl;
	int cnt=1;
	for(int i=1; i<=n; i++) if(d[i]==1) dfs1(i,++cnt);
	for(int i=1; i<=n; i++) c[i]=i;
	int e=cnt-2;
	int ans=0,k=0;
	for(int i=1; i<=n; i++) if(d[i]) ans++;
	if(e<=1) return ans;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(d[i]!=d[j]&&d[i]!=0&&d[j]!=0)
				g[d[i]][d[j]]=1e7;
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(d[i]!=d[j]&&d[i]!=0&&d[j]!=0)
				g[d[i]][d[j]]=min(g[d[i]][d[j]],get(i,j));
	for(int i=2; i<=cnt; i++)
		for(int j=i+1; j<=cnt; j++)
			p[++k]= {i,j,g[i][j]};
	sort(p+1,p+k+1,cmp);
	for(int i=1; i<=k; i++) {
		int u=find(p[i].u),v=find(p[i].v);
		if(u!=v) {
			c[u]=v;
			ans+=p[i].w-1;
			e--;
		}
		if(e==1) break;
	}
	return ans;
}
signed main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--) {
		cin>>n>>k;
		for(int i=1; i<n; i++) {
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
			a[v].push_back(u);
		}
		dfs2(1,0);
		for(int i=1; i<=log2(n); i++)
			for(int j=1; j+(1<<i)-1<=n; i++)
				st[i][j]=get(st[i-1][j],st[i-1][j+(1<<i-1)]);
		int l=0,r=n-1,ans=0;
		while(l<=r) {
			int mid=(l+r)/2;
			if(cheak(mid)<=k) ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<endl;
		for(int i=1; i<=n; i++) a[i].clear();
	}
	return 0;
}
