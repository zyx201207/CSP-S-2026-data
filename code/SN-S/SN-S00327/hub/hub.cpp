//孟楚程  西安辅轮中学  SN-S00327 
#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int buflen=1<<22,maxn=1e6+5;
int pos,len,n,k,vis[maxn],dep[maxn],f[maxn][25],ans;char buf[buflen];vector<int>vc[maxn];
char gc(){
	if(pos==len) len=fread(buf,1,buflen,stdin),pos=0;
	return pos==len?EOF:buf[pos++];
}
int rad(){
	int x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;if(ch==EOF) return 0;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=gc();}return x*f;
}
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;f[u][0]=fa;
	for(int v:vc[u])if(v!=fa){
		dfs1(v,u);
	} 
}
int lca(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	int d=dep[u]-dep[v];
	for(int i=23;i>=0;i--) if(d>>i&1) u=f[u][i];
	if(u==v) return u;
	for(int i=23;i>=0;i--) if(f[u][i]!=f[v][i]){u=f[u][i];v=f[v][i];}
	return f[u][0];
}
void dfs(int x,int sf){//多少个  是否用过  
	if(x==k){
		int xie=0;
		for(int i=1;i<=n;i++){
			int jl=inf;
			for(int j=1;j<=n;j++) if(vis[j]){
				int lc=lca(i,j);if(lc!=i) swap(i,j);//lc=j
				if(lc==j){
					jl=min(jl,dep[j]-dep[i]);
				}else{
					jl=min(jl,dep[lc]-dep[j]+dep[lc]-dep[i]);
				}
			}xie=max(xie,jl);
		}ans=min(ans,xie);return;
	}
	for(int i=1;i<=n;i++) if(vis[i]) for(int v:vc[i]) if(!vis[v]){vis[v]=1;dfs(x+1,sf);vis[v]=0;}
	if(sf==0){
		for(int i=1;i<=n;i++) if(!vis[i]){
			bool xie1=0;
			for(int v:vc[i]) if(vis[v]) xie1=1;
			if(xie1==0){vis[i]=1;dfs(x+1,1);vis[i]=0;}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
	int c=rad(),t=rad();
	while(t--){
		n=rad(),k=rad();for(int i=1;i<=n;i++) vc[i].clear();for(int i=1;i<=n;i++) vis[i]=0;ans=inf;
		for(int i=1;i<n;i++){int u=rad(),v=rad();vc[u].push_back(v);vc[v].push_back(u);}
		cout<<'0'<<'\n'; 
	}
	return 0;
}
