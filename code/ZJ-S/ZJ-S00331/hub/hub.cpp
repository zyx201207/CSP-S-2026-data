//hub 17.17
#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(),(x).end()
using namespace std;
const int N=4005,INF=1e9;
int __,_,n,m,x,y,mx,d[N],h[N],sz[N],f[N][N][2],g[N][N][2],ff[N][2],gg[N][2];
basic_string<int> ve[N];
inline void cmn(int &x,int y){y<x&&(x=y);}
void dfs1(int u,int fa){
	d[u]=d[fa]+1,h[u]=0,sz[u]=1;
	for(int v:ve[u])if(v!=fa){
		dfs1(v,u);
		if(h[v]>h[u])h[u]=h[v];
		sz[u]+=sz[v];
	}
	h[u]++;
}
void dfs2(int u,int fa){
	for(int v:ve[u])if(v!=fa)dfs2(v,u);
	int siz=1,hh=0;
	for(int i=1;i<=sz[u];i++){
		f[u][i][0]=f[u][i][1]=INF;
		g[u][i][0]=g[u][i][1]=0;
	}
	g[u][1][0]=1;
	for(int v:ve[u])if(v!=fa){
		for(int i=1;i<=sz[u];i++)
			ff[i][0]=ff[i][1]=INF,gg[i][0]=gg[i][1]=0;
		if(h[v]<=mx){
			for(int i=1;i<=sz[u];i++){
				gg[i][0]=g[u][i][0];
				gg[i][1]=g[u][i][1];
			}
		}
		for(int i=1;i<=siz;i++){
			for(int j=1;j<=sz[v];j++){
				gg[i+j][0]|=(g[u][i][0]&&g[v][j][0]);
				gg[i+j][1]|=(g[u][i][0]&&f[v][j][0]-d[u]<=mx*2);
				gg[i+j][1]|=(g[u][i][0]&&g[v][j][1]);
				gg[i+j][1]|=(g[u][i][1]&&g[v][j][0]);
			}
		}
		for(int i=1;i<=sz[v];i++){
			if(g[v][i][0]&&hh+1<=mx)
				cmn(ff[i][0],d[u]+1);
			if(hh+(f[v][i][0]-d[u])<=mx)
				cmn(ff[i][0],f[v][i][0]);
			if(g[v][i][1]&&hh+1<=mx)
				cmn(ff[i][1],d[u]+1);
			if(hh+(f[v][i][1]-d[u])<=mx)
				cmn(ff[i][1],f[v][i][1]);
			for(int j=1;j<=siz;j++){
				if(g[v][i][0]&&(f[u][j][0]-d[u])+1<=mx)
					cmn(ff[i][1],d[u]+1);
				if((f[u][j][0]-d[u])+(f[v][i][0]-d[u])<=mx)
					cmn(ff[i][1],min(f[u][j][0],f[v][i][0]));
			}
		}
		for(int i=1;i<=siz;i++){
			if(f[u][i][0]+h[v]<=mx)
				cmn(ff[i][0],f[u][i][0]);
			if(f[u][i][1]+h[v]<=mx)
				cmn(ff[i][1],f[u][i][1]);
		}
		siz+=sz[v];
		hh=max(hh,h[v]);
		for(int i=1;i<=siz;i++){
			f[u][i][0]=ff[i][0];
			f[u][i][1]=ff[i][1];
			g[u][i][0]=gg[i][0];
			g[u][i][1]=gg[i][1];
		}
	}
	//cout<<"Node "<<u<<'\n';
	//for(int i=1;i<=sz[u];i++)cout<<g[u][i][1]<<' ';
	//cout<<'\n';
}
inline bool chk(int x){
	//cout<<"Check "<<x<<'\n';
	mx=x,dfs2(1,0);
	for(int i=1;i<=m;i++){
		if(g[1][i][0]||g[1][i][1])return 1;
		if(f[1][i][0]<INF||f[1][i][1]<INF)return 1;
	}
	return 0;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>__>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>x>>y;
			ve[x].pb(y),ve[y].pb(x);
		}
		dfs1(1,0);
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(chk(mid))r=mid;
			else l=mid+1;
		}
		cout<<l<<'\n';
		for(int i=1;i<=n;i++)ve[i].clear();
	}
	return 0;
}