#include<bits/stdc++.h>
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define ROF(i,r,l) for(int i=r;i>=l;i--)
#define cmax(x,y) x=max(x,y)
#define cmin(x,y) x=min(x,y)
#define all(x) x.begin(),x.end()
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-48;
		c=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int N = 1e6+10,inf=0x3f3f3f3f;
typedef pair<int,int> pii;
vector<int> vc[N];
int dep[N],dfn[N],tot,fa[N],logg[N];
pii st[N][20];
void dfs(int x, int f){
	fa[x]=f;dfn[x]=++tot;
	st[tot][0]={dep[x]=dep[f]+1,x};
	for(auto j:vc[x])if(j!=f)dfs(j,x);
}
inline int lca(int x, int y){
	if(x==y)return x;
	x=dfn[x],y=dfn[y];
	if(x>y)swap(x,y);
	x++;
	int p=logg[y-x+1];
	return fa[min(st[x][p],st[y-(1<<p)+1][p]).se];
}
inline int dis(int x, int y){
	return dep[x]+dep[y]-dep[lca(x,y)]*2;
}
int n,k;
namespace Sub1{
	pii mxd[N];
	int vis[N],stk[N];
	pair<int,pii> D;
	void dfs1(int x, int f){
		mxd[x]={dep[x],x};
		pii smx={0,0};
		for(auto j:vc[x]){
			if(j!=f){
				dfs1(j,x);
				if(mxd[j]>mxd[x])smx=mxd[x],mxd[x]=mxd[j];
				else cmax(smx,mxd[j]);
			}
		}
		cmax(D,make_pair(mxd[x].fi-dep[x],make_pair(mxd[x].se,x)));
		cmax(D,make_pair(mxd[x].fi+smx.fi-dep[x]*2,make_pair(mxd[x].se,smx.se)));
	}
	int ds,DS[N],tot;
	void dfs(int x, int f,int d){
		cmax(ds,d); 
		for(auto j:vc[x]){
			if(!vis[j]&&j!=f)dfs(j,x,d+1);
		}
	} 
	bool check(int x){
		int L=1,R=tot;
		FOR(i,1,tot){
			if(x<DS[i])return 0; 
			cmax(L,i-(x-DS[i]));
			cmin(R,i+(x-DS[i]));
		}
		FOR(i,1,tot){
			int l=i-(x-DS[i]),r=i+(x-DS[i]);
			if(!(l<=L&&L<=r)&&!(l<=R&&R<=r))return 0;
		}
		return 1;
	}
	void solve(){
		D.fi=-inf;
		dfs1(1,1);
		int x=D.se.fi,y=D.se.se;
		int p=lca(x,y);
		tot=dis(x,y)+1;
		int LL=dep[x]-dep[p];
		FOR(i,1,LL){
			stk[i]=x;
			x=fa[x];
		}
		LL=dep[y]-dep[p]+1;
		FOR(i,1,LL){
			stk[tot+1-i]=y;
			y=fa[y];
		}
		FOR(i,1,n)vis[i]=0;
		FOR(i,1,tot)vis[stk[i]]=1;
		FOR(i,1,tot){
			ds=0;
			dfs(i,i,0);
			DS[i]=ds; 
		}
//		FOR(i,1,tot)cout<<stk[i]<<" ";
//		cout<<"\n";
//		FOR(i,1,tot)cout<<DS[i]<<" ";
//		cout<<"\n";
		int l=0,r=n,mid,ans;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<"\n";
	}
}
void solve(){
	n=read(),k=read();logg[0]=-1;
	
	// clear 
	FOR(i,1,n)vc[i].clear(),logg[i]=logg[i/2]+1;
	tot=0;
	
	FOR(i,1,n-1){
		int u=read(),v=read();
		vc[u].push_back(v);
		vc[v].push_back(u); 
	}
	dfs(1,1); 
	FOR(j,1,logg[n])FOR(i,1,n-(1<<j)+1)st[i][j]=min(st[i][j-1],st[i+(1<<j-1)][j-1]);
	if(n<=10){
		int up=1<<n,ans=N;
		FOR(s,0,up-1){
			if(__builtin_popcount(s)==k){
				int mx=0,ct=0;
				FOR(i,1,n)FOR(j,i+1,n){
					int d=dis(i,j);
					if(d==1&&(s&(1<<i-1))&&(s&(1<<j-1)))ct++;
				}
				FOR(i,1,n)if(!(s&(1<<i-1))){
					int mn=N;
					FOR(j,1,n)if(s&(1<<j-1))cmin(mn,dis(i,j));
					cmax(mx,mn);
				}
				if(ct>=k-2)cmin(ans,mx);
			}
		}
		cout<<ans<<"\n";		
	}else Sub1::solve();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--)solve();
	return 0;
}

