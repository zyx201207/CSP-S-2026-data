#include<bits/stdc++.h>
using namespace std;
#define int long long

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 
const int N=1e6+5;

int n,k;
vector<int> e[N];

int li[N],tot;
int vis[N],dep[N],d2[N];
int f[N][21];
int s,t;
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>dep[s])s=u;
	f[u][0]=fa;
	for(int i=1;i<=20;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa){
	d2[u]=d2[fa]+1;
	if(d2[u]>d2[t])t=u;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
	}
}
int flag;
void dfs3(int u,int fa){
	if(u==t){
		flag=1;
		li[++tot]=u;
		return;
	}
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs1(v,u);
		if(flag){
			li[++tot]=u;
			return;
		}
	}
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y])
			x=f[x][i];
	if(x==y)return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int dis(int x,int y){
	int lc=lca(x,y);
	return dep[x]+dep[y]-2*dep[lc];
}
int dl[N];
void dfs4(int u,int fa){
	d2[u]=d2[fa]+1;dl[u]=0;
	for(auto v:e[u]){
		if(vis[v]||v==fa)continue;
		dfs4(v,u);
		dl[u]=max(dl[u],dl[v]+1);
	}
}

int pre[N],suf[N];

int solve(){
	flag=tot=0;
	dfs1(1,0);dfs2(s,0);dfs3(s,0);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=tot;i++)vis[li[i]]=1;
	for(int i=1;i<=tot;i++)dfs4(li[i],0);
	
}
//k=2
int solve1(){
	flag=tot=0;
	dfs1(1,0);dfs2(s,0);dfs3(s,0);
	for(int i=1;i<=n;i++)vis[i]=0;
	for(int i=1;i<=tot;i++)vis[li[i]]=1;
	for(int i=1;i<=tot;i++)dfs4(li[i],0);
	for(int i=1;i<=tot;i++)pre[i]=max(pre[i-1],i-1+dl[i]);
	suf[n+1]=0;
	for(int i=tot;i>=1;i--)suf[i]=max(suf[i+1],i-1+dl[i]);
	int res=1e18;
	for(int i=1;i<tot;i++)
		res=min(res,max(pre[i]-1,suf[i+1]-1)/2+1);
	return res;
}

//baoli

void dfs5(int u,int fa){
	vis[u]=2;
	for(auto v:e[u]){
		if(v==fa||vis[u]!=1)continue;
		dfs5(v,u);
	}
}
int solve2(){
	for(int i=1;i<=n;i++)
		for(int s=0;s<=20;s++)
			f[i][s]=0;
	dfs1(1,0);
	int ans=1e18;
	for(int ms=0;ms<(1<<n);ms++){
		if(__builtin_popcount(ms)!=k)continue;
		for(int i=1;i<=n;i++)vis[i]=((ms>>i-1)&1);
		int ct=0;
		for(int i=1;i<=n;i++)if((ms>>i-1)&1){
			if(vis[i]==1){
				dfs5(i,0);
				ct++;
			}
			if(ct>2)break;
		}
		if(ct>2)continue;
		int res=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==2)continue;
			int tmp=1e18;
			for(int j=1;j<=n;j++){
				if(vis[j]==2)
					tmp=min(tmp,dis(i,j));
			} 	
			res=max(res,tmp);
		}
//		printf("%lld ",ms);
//		for(int i=1;i<=n;i++)printf("%lld ",vis[i]);puts("");
		ans=min(ans,res);
	}
//	puts("");
	return ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read();int T=read();

	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			e[u].push_back(v);
			e[v].push_back(u);
		}
		
		if(k==2)printf("%lld\n",solve1());
		else printf("%lld\n",solve2());
//		else printf("%lld\n",solve());
	}
	
	
	return 0;
}
