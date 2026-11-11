#include<bits/stdc++.h>
#define rep(i,a,b) for(long long i=(a);i<=(b);++i)
#define debug(a) cout<<#a<<"="<<a<<"\n";
using namespace std;
const long long N=20+7;
int n,m,k,a[N],b[N],vis[N],h[N],f[N][21],ans;
vector<int> g[N];
int lca(int x,int y){
	if(h[x]<h[y]) swap(x,y);
	for(int i=20;i>=0;i--){
		if(h[f[x][i]]>=h[y]) x=f[x][i];
	}
	if(x==y) return x;
	for(int i=20;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		} 
	}
	return f[x][0];
}
void dfs(int x,int fa){
	h[x]=h[fa]+1;
	f[x][0]=fa;
	for(int i=0;i<g[x].size();++i){
		int j=g[x][i];
		if(j==fa) continue;
		dfs(j,x);
	}
}
int find(int x){
	if(b[x]!=x) b[x]=find(b[x]);
	return b[x];
}
bool check(int x){
	int s=(1<<n)-1;
	rep(i,0,s){
		k=0;
		rep(j,1,n){
			vis[j]=0;
			if(i&(1<<(j-1))) a[++k]=j,vis[j]=1;
		}
		if(k>m) continue;
		rep(j,1,k) b[j]=j;
		rep(j,1,k){
			for(auto u:g[a[j]]){
				if(vis[u]==0) continue;
				int p=find(a[j]),q=find(u);
				if(p!=q) b[p]=q;
			}
		}
		int ss=0;
		rep(j,1,k) if(find(j)==j) ss++;
		if(ss>2) continue;
		ans=1;
		rep(j,1,n){
			bool f=1;
			rep(kk,1,k){
				if(h[j]+h[a[kk]]-h[lca(j,a[kk])]*2<=x) f=0;
			}
			if(f) ans=0;
		}
		if(ans) return 1;
	}
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int id,T;
	scanf("%d%d",&id,&T);
	while(T--){
		scanf("%d%d",&n,&m);
		rep(i,1,n) g[i].clear();
		rep(i,1,n-1){
			int u,v;
			scanf("%d%d",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		rep(j,1,20){
			rep(i,1,n) f[i][j]=f[f[i][j-1]][j-1];
		}
		int l=0,r=n;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid)) r=mid;
			else l=mid+1; 
		}
		printf("%d\n",l);
	}
    return 0;
}
