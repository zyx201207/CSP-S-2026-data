#include <bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,INF=2e9;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while ('0'>ch||ch>'9'){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch&&ch<='9'){
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}return f*x;
}
int c,t,n,k,fa[maxn],dis[maxn];
bool flag[maxn];
vector<int>g[maxn];
int find(int x){return (fa[x]==x)?x:(fa[x]=find(fa[x]));}
void merge(int u,int v){
	int fu=find(u),fv=find(v);
	if (fu==fv) return;
	return fa[fv]=fu,void();
}
void dfs(int u,int fa){
	if (flag[u]){
		dis[u]=0;
		for (int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if (v==fa) continue;
			dfs(v,u);
		}return;
	}else{
		dis[u]=dis[fa]+1;
		for (int i=0;i<(int)g[u].size();i++){
			int v=g[u][i];
			if (v==fa) continue;
			dfs(v,u);
			dis[u]=min(dis[u],dis[v]+1);
		}return;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();
	while (t--){
		n=read(),k=read();
		int ans=INF;
		for (int i=1;i<=n;i++) g[i].clear();
		for (int i=1,u,v;i<n;i++){
			u=read(),v=read();
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for (int i=1;i<(1<<n);i++){
			if (__builtin_popcount(i)!=k) continue;
			for (int k=1;k<=n;k++) fa[k]=k;
			for (int k=0;k<22;k++) flag[k+1]=((i>>k)&1);
			for (int i=1;i<=n;i++)
				if (flag[i])
					for (int j=0;j<(int)g[i].size();j++){
						int v=g[i][j];
						if (flag[v]) merge(i,v);
					}
			int cnt=0,bel1=0,bel2=0;
			bool sym=false;
			for (int i=1;i<=n;i++)
				if (flag[i]){
					int f=find(i);
					if (cnt==0) bel1=f,cnt++;
					else if (cnt==1&&f!=bel1) bel2=f,cnt++;
					else if (cnt==2&&f!=bel1&&f!=bel2){
						sym=true;break; 
					}
				}
			if (sym) continue;
			for (int i=1;i<=n;i++) dis[i]=INF;
			dfs(1,1);
			int res=0;
			for (int i=1;i<=n;i++) res=max(res,dis[i]);
			ans=min(ans,res);
		}cout<<ans<<'\n';
	}
	return 0;
}
//I love CCF!Please give me 15pts or more!!!11
