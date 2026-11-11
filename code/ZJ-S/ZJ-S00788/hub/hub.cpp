#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=1e6+6,M=1e3+6,INF=2e9;
// int n,m,f[M][M][3][2],tmpf[M][3][2],sz[N],son[N],dep[N],mxh[N],mxh2[N],mxp[N],mxp2[N];
// vector<int> e[N];
// void dfs1 (int u,int fu) {
//     sz[u]=1,dep[u]=dep[fu]+1;
//     for (int v:e[u]) {
//         dfs1(v,u);
//         sz[u]+=sz[v]; 
//         if (mxh[v]+1>mxh[u]) mxp2[u]=mxp[u],mxh2[u]=mxh[u],mxp[u]=v,mxh[u]=mxh[v]+1; else if (mxh[v]+1>mxh2[u]) mxh2[u]=mxh[v]+1,mxp2[u]=v;
//         if (sz[v]>sz[son[u]]) son[u]=0;
//     }
// } 
// void dfs(int u,int fu,int fi,int mx) {
//     f[u][1][1][1]=max(mx,mxh[u]);
//     f[u][0][0][0]=INF;
//     if (son[u]) {
//         dfs(son[u],u,(fi?fi:son[u]),max(mx+1,(son[u]==mxp[u]?mxh2[u]:mxh[u])+1));
//         for (int i=0;i<=m;++i) for (int j=0;j<=2;++j) f[u][i][j][0]=min(f[son[u]][i][j][0],f[son[u]][i][j][1]);
//         int ans=max(mx,(son[u]==mxp[u]?mxh2[u]:mxh[u]));
//         for (int i=1;i<=m;++i) for (int j=1;j<=2;++j) f[u][i][j][1]=min({f[son[u]][i-1][j][1],ans,f[son[u]][i-1][j-1][0]});
//     }
//     int siz=sz[son[u]];
//     for (int v:e[u]) {
//         if (v==fu || v==son[u]) continue;
//         dfs(v,u,(fi?fi:v),max(mx+1,(v==mxp[u]?mxh2[u]:mxh[u])));
//         int ans=(v==mxp[u]?mxh2[u]:mxh[u]); ans=max(ans,mx);
//         for (int i=0;i<=(siz+sz[v]);++i) for (int j=0;j<=2;++j) for (int k=0;k<2;++k) tmpf[i][j][k]=1e9;
//         for (int i=0;i<=(siz+sz[v]);++i) for (int j=0;j<=2;++j) for (int ni=0;ni<=i;++ni) for (int nj=0;nj<=j;++nj) tmpf[i][j][0]=min(tmpf[i][j][0],min({f[v][ni][nj][0],f[v][ni][nj][1],f[u][i-ni][j-nj][0]}));
//         for (int i=1;i<=(siz+sz[v]+1);++i) for (int j=1;j<=2;++j) for (int ni=0;ni<i;++ni) for (int nj=0;nj<=j;++nj) tmpf[i][j][1]=min({tmpf[i][j][1],ans,f[u][i-ni][j-nj][1],f[v][ni][nj][0]});
//         for (int i=1;i<=(siz+sz[v]+1);++i) for (int j=1;j<=2;++j) for (int ni=0;ni<i;++ni) for (int nj=0;nj<=j;++nj) tmpf[i][j][1]=min({tmpf[i][j][1],ans,})
//     }
// }
int n,m,a[N];
vector<int> e[N];
ll res;
ll dist(int u,int b,int lst) {
	if (u==b) return 0;
    for (int v:e[u]) {
        if (v==lst) continue;
        int ans=dist(v,b,u);
        if (ans==-1) continue;
        return ans+1;
    }
    return -1;
}
int flag[N];
bool ina (int x) {
	for (int i=1;i<=m;++i) if (a[i]==x) return 1;
	return 0;
}
void dfs2(int u,int f) {
	for (int v:e[u]) if (v!=f && ina(v)) flag[v]=1,dfs2(v,u);  
}
bool check() {
	int cnt=0;
	for (int i=1;i<=m;++i) {
		if (!flag[a[i]]) dfs2(a[i],0),++cnt;
	}
	for (int i=1;i<=n;++i) flag[i]=0;
	return cnt<=2;
}
ll solve() {
    ll res=-INF;
    if (!check()) return INF;
    for (int i=1;i<=n;++i) {
        ll ans=INF;
        for (int j=1;j<=m;++j) {
        	//cout<<i<<" "<<a[j]<<"\n";
        	ans=min(ans,dist(i,a[j],0));
		}
        res=max(res,ans);
    }
    return res;
}
void dfs(int step,int cnt) {
    if (cnt==m) {
    	//cout<<"1\n"; 
    	int ans=solve();
        res=min(res,solve());
        return ;
    }
    if (step>n) return;
    dfs(step+1,cnt);
    a[cnt+1]=step;
    dfs(step+1,cnt+1);
}
void Solve() {
    // dep[0]=-1;
    // for (int i=1;i<=n;++i) son[i]=0,mxh[i]=mxh2[i]=-1;
    res=INF;
    cin>>n>>m;
    for (int i=1;i<=n;++i) e[i].clear();
    for (int i=1,a,b;i<n;++i) cin>>a>>b,e[a].push_back(b),e[b].push_back(a);
    dfs(1,0);
	cout<<res<<"\n"; 
    // dfs1(1,0); dfs(1,0,0,0);
}
signed main() {
     freopen("hub.in","r",stdin);
     freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c,T=1; cin>>c>>T;
    while (T--) Solve();
    return 0;
}

