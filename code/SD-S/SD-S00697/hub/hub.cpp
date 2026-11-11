#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
void read(int &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
void read(ll &a){
	a=0;char c=getchar();bool ff=0;
	while(c<'0'||'9'<c){if(c=='-') ff=1;c=getchar();}
	while('0'<=c&&c<='9'){a=(a<<3)+(a<<1)+(c^48);c=getchar();}
	if(ff) a=-a;
}
namespace SHEEP{
	const int N=1e6+5;
	int n,k,d[N],mxd[N],pw[N],F[N];
	vector<int> e[N];int f[N],df[N],w[N];
	void dfs1(int u,int fa,bool ff=0){
		mxd[u]=d[u];F[u]=fa;
		for(auto v:e[u]) if(v!=fa){
			d[v]=d[u]+1;dfs1(v,u,ff);
			mxd[u]=max(mxd[u],mxd[v]);
		}
	}
	void dfs2(int u,int fa){
		int mx1=pw[u],mx2=0;
		for(auto v:e[u]) if(v!=fa){
			int w=mxd[v]-d[u];
			if(mx1<w){mx2=mx1;mx1=w;}
			else if(mx2<w) mx2=w;
		}
		for(auto v:e[u]) if(v!=fa){
			int w=mxd[v]-d[u];
			if(mx1==w) pw[v]=mx2+1;
			else pw[v]=mx1+1;
			dfs2(v,u);
		}
	}
	void dfs3(int u,int fa,int x){
		f[u]=0;
		int cnt=0;
		for(auto v:e[u]) if(v!=fa){
			dfs3(v,u,x);
			if(f[v]) cnt++;
		}
		if(mxd[u]-d[u]<x){
			w[u]=0;
			return ;
		}
		if(cnt==0){f[u]=1;df[u]=0;}
		if(cnt==1){
			int maxx=0;
			for(auto v:e[u]) if(v!=fa){
				if(!f[v]) maxx=max(maxx,mxd[v]-d[u]);
				else f[u]=f[v],df[u]=df[v]+1;
			}
			if(df[u]+maxx>x){
				int w=df[u]+maxx-x;
				f[u]+=w;df[u]-=w;
			} 
		}
		if(cnt>=2){f[u]=1;df[u]=0;
			for(auto v:e[u]) if(v!=fa){
				if(f[v]){
					f[u]+=f[v]+df[v]-1;
				}
			}
		}
		w[u]=f[u];
	}
	bool chk(int x){
		for(int i=2;i<=n;i++){
			dfs1(i,F[i]);
			dfs2(i,F[i]);
			dfs3(i,F[i],x);
			dfs1(F[i],i);
			dfs2(F[i],i);
			dfs3(F[i],i,x);
			if(max(f[i],1)+max(f[F[i]],1)<=k) return 1;
		}return 0;
	}
	void work(){
		read(n);read(k);
		for(int i=1;i<=n;i++) e[i].clear(),pw[i]=0;
		for(int i=1,u,v;i<n;i++){
			read(u);read(v);
			e[u].emplace_back(v);
			e[v].emplace_back(u);
		}d[1]=0;dfs1(1,0,1);dfs2(1,0);
		if(k==n){
			printf("0\n");
			return ;
		}
		int l=1,r=n,mid;
		while(l<r){
			mid=(l+r)>>1;
			if(chk(mid)) r=mid;
			else l=mid+1;
		}printf("%d\n",l);
	}
}

int main(){
//	int _=clock();
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T=1,c;
	read(c);
	read(T);
	while(T--) SHEEP::work();
//	cerr<<clock()-_<<endl;
	return 0;
} 
