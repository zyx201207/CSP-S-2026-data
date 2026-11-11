#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int read(){
	char ch=getchar();int x=0;
	while(ch<'0' || ch>'9')ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int c,t,n,k;
vector<int> g[1000005];
int p[1000005],cnt;
bool vis[1000005];
int mxid,mx,fa[1000005];
void dfs(int u,int dep){
//	printf("%d %d\n",u,dep);
	for(int v:g[u]){
		if(fa[u]==v)continue;
		fa[v]=u;
		dfs(v,dep+1);
	}
	if(dep>mx)mxid=u,mx=dep;
}
int mxdep[1000005];
void work(int u,int fat,int dep){
	mxdep[u]=dep;
	for(int v:g[u]){
		if(vis[v] || v==fat)continue;
		work(v,u,dep+1);
		mxdep[u]=max(mxdep[v],mxdep[u]);
	}
}
int ssum=0;
void calc(int u,int fat,int dep,int x){
	if(mxdep[u]-dep>=x)ssum++;
	for(int v:g[u]){
		if(vis[v] || v==fat)continue;
		calc(v,u,dep+1,x);
	}
}
bool check(int x){
	int ll=cnt,rr=1;
	for(int i=1;i<=cnt;i++)
		ll=min(ll,i+max(x-mxdep[p[i]],0));
	for(int i=cnt;i>=0;i--)
		rr=max(rr,i-max(x-mxdep[p[i]],0));
//	if(x==1)printf("%d %d\n",ll,rr);
	if(ll>rr)return 1;
	ssum=0;
	for(int i=ll;i<=rr;i++)calc(p[i],0,0,x);
	if(ssum<=k)return 1;
	for(int l=ll+1;l<=rr-1;l++)
		for(int r=l;r<=rr-1;r++){//[ll,l-1],[r+1,rr]
			bool pp=0;
			for(int i=l;i<=r;i++){
//				if(x==1)printf("%d %d\n",x-mxdep[p[i]],min(i-l+1,r+1-i));
				if(x-mxdep[p[i]]<min(i-l+1,r+1-i))
					pp=1;
			}
			if(pp)break;
			ssum=0;
			for(int i=ll;i<l;i++)calc(p[i],0,0,x);
			for(int i=r+1;i<=rr;i++)calc(p[i],0,0,x);
//			if(x==1 && ssum<=k)printf("***%d %d\n",l,r);
			if(ssum<=k)return 1;
		}
	return 0;
}
void init(){
	cnt=0;
	for(int i=1;i<=n;i++)g[i].clear(),vis[i]=0,p[i]=0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read();t=read();
	while(t--){
		init();
		n=read();k=read();
		for(int i=1;i<n;i++){
			int u,v;u=read();v=read();
			g[u].pb(v);g[v].pb(u);
		}
		mx=0;mxid=0;
		dfs(1,0);
		int rt=mxid;for(int i=1;i<=n;i++)fa[i]=0;
		mx=0;mxid=0;
		dfs(rt,0);
		while(1){
			if(mxid==0)break;
			p[++cnt]=mxid;
			vis[mxid]=1;mxid=fa[mxid];
		}
		for(int i=1;i<=cnt;i++)work(p[i],0,0);
//		for(int i=1;i<=cnt;i++)printf("%d ",p[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",mxdep[i]);puts("");
		if(c<=8){
			int l=0,r=n,res=n;
			while(l<=r){
				int mid=(l+r>>1);
				if(check(mid))r=mid-1,res=mid;
				else l=mid+1;
			}
			printf("%d\n",res);
		}
	}
	return 0;
} 
