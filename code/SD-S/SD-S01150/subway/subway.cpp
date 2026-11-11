#include<bits/stdc++.h>
#define pll pair<int,int>
#define eb emplace_back
#define mkp make_pair
using namespace std;
const int N=8e5+1;
const int M=505;
int c,n,m,d,q,idx,dep[N],f[N][36],b[N],cnt[N],id_zt[N],id_zk[N],dis[5001][5001];
vector<pll> g[N];
//站i的第j个站台  (i-1)*d+j 
//站i的站厅       (i-1)*d+d-1
//站i的站口       (i-1)*d+d
struct station{
	int t[M];//a[i].t[j]为站 i 的第 j 个站台的编号 
}a[N];


inline void dfs(int u,int fa){
	f[u][0]=fa; dep[u]=dep[fa]+1;
	for(int j=1;j<=35;j++) f[u][j]=f[f[u][j-1]][j-1];
	for(pll t:g[u]){
		int v=t.first;
		int w=t.second;
		if(v==fa) continue;
		b[v]=b[u]+w;
		dfs(v,u);
	}
}
inline int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=35;i>=0;i--){
		if(dep[f[u][i]]>=dep[v]) u=f[u][i];
	}
	if(u==v) return u;
	for(int i=35;i>=0;i--){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}

inline void floyd(){
	for(int i=1;i<=idx;i++) dis[i][i]=0;
	for(int k=1;k<=idx;k++){
		for(int i=1;i<=idx;i++){
			for(int j=1;j<=idx;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin>>c>>n>>m>>d>>q;
	for(int i=1,w;i<=m;i++){
		cin>>w;
		id_zk[i]=++idx;
		id_zt[i]=++idx;
		
		//站厅到站口 
		int k1=id_zt[i];
		int k2=id_zk[i];
		g[k1].eb(mkp(k2,w));
		g[k2].eb(mkp(k1,w));
		if(m<=1000) dis[k1][k2]=dis[k2][k1]=w;
	}
	for(int i=1;i<=n;i++){
		int k,t,u,v;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>u>>t;
			cnt[u]++;
			a[u].t[cnt[u]]=++idx;
			
			//站台到站厅 
			int k1=a[u].t[cnt[u]];
			int k2=id_zt[u];
			g[k1].eb(mkp(k2,t));
			g[k2].eb(mkp(k1,t));
			if(m<=1000) dis[k1][k2]=dis[k2][k1]=t;
			
			if(j!=1){
				//站台到站台 
				int k1=a[u].t[cnt[u]];
				int k2=a[v].t[cnt[v]];
				g[k1].eb(mkp(k2,0));
				g[k2].eb(mkp(k1,0));
				if(m<=1000) dis[k1][k2]=dis[k2][k1]=0;
			}
			v=u;
		}
	}
	if(m<=1000)	floyd();
	else dfs(1,0);
	while(q--){
		int x,y;
		cin>>x>>y;
		int kx=id_zk[x];
		int ky=id_zk[y];
		if(m<=1000) cout<<dis[kx][ky]<<'\n';
		else{
			int t=lca(kx,ky);
			cout<<b[kx]+b[ky]-2*b[t]<<'\n';
		}
	}
	return 0;
}
