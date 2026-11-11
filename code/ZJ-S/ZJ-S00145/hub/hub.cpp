#include<bits/stdc++.h>
#define int long long
namespace IO{
	using namespace std;
	#define gc getchar
	int readint(){
		int ret=0;bool f=1;char c=gc();
		while(!isdigit(c)){if(c=='-')f=0;c=gc();}
		while(isdigit(c))ret=ret*10+(c&15),c=gc();
		return f?ret:-ret;
	}
}
namespace c1_3{
	using namespace IO;
	const int MAXN=110;
	int n,k,ans,f[MAXN][MAXN];
	int U[MAXN],V[MAXN],G[2*MAXN],deg[MAXN];
	bool vis[MAXN];int fa[MAXN];
	int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
	void merge(int x,int y){
		int fx=getfa(x),fy=getfa(y);
		if(fx==fy)return;
		fa[fy]=fx;
	}
	void DFS(int u,int cnt){
		if(u>n){
			for(int i=1;i<=n;i++)if(vis[i])fa[i]=i;else fa[i]=0;
			for(int i=1;i<n;i++)if(vis[U[i]]&&vis[V[i]])merge(U[i],V[i]);
			int cnt=0;
			for(int i=1;i<=n;i++)if(vis[i]&&getfa(i)==i)cnt++;
			if(cnt>2)return;
			int cur=0;
			for(int i=1;i<=n;i++)if(!vis[i]){
				int cc=n;
				for(int j=1;j<=n;j++)if(vis[j])cc=min(cc,f[i][j]);
				cur=max(cur,cc);
			}
			ans=min(ans,cur);
		}
		if(cnt<k){
			vis[u]=1;
			DFS(u+1,cnt+1);
			vis[u]=0;
		}
		if(k-cnt<=n-u)DFS(u+1,cnt);
	}
	void solve(){
		n=readint(),k=readint();ans=n-k;
		memset(deg,0,sizeof deg);
		memset(f,0x3f,sizeof f);
		for(int i=1;i<=n;i++)f[i][i]=0;
		for(int i=1;i<n;i++)U[i]=readint(),V[i]=readint(),deg[U[i]]++,deg[V[i]]++,f[U[i]][V[i]]=f[V[i]][U[i]]=1;
		for(int i=1;i<=n;i++)deg[i+1]+=deg[i];
		for(int i=1;i<n;i++)G[deg[U[i]]--]=V[i],G[deg[V[i]]--]=U[i];
		for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
		DFS(1,0);
		cout<<ans<<'\n';
	}
	void Main(){
		int T=readint();
		while(T--)solve();
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=IO::readint();
	c1_3::Main();
	return 0;
}

