#include<stdio.h>
#include<vector>
#include<array>
#include<algorithm>
#define M 1000005
using namespace std;
vector<int> G[M];
int C,n,k,md,rt,fa[M],p,q;
int vc[M],t,mc[M];
bool vis[M];
int ban;
void dfs(int x,int f,int d){
	if(d>md) md=d,rt=x;
	fa[x]=f;
	for(int y:G[x]) if(y!=f&&y!=ban) dfs(y,x,d+1);
}
void cal(int x,int f){
	mc[x]=0;
	for(int y:G[x]) if(y!=f&&!vis[y]) cal(y,x),mc[x]=max(mc[x],mc[y]+1);
}
int D,mx[M],c1[M],c2[M];
int v1[M];
void dfs2(int x,int f,int ct[]){
	mx[x]=0,ct[x]=0;
	for(int y:G[x]) if(y!=f) dfs2(y,x,ct),mx[x]=max(mx[x],mx[y]+1),ct[x]+=ct[y];
	ct[x]+=mx[x]>=D;
	// printf("%d: %d\n",x,ct[x]);
}
int cald(int x,int f){
	mx[x]=0;int c=0;
	for(int y:G[x]) if(y!=f&&y!=ban) c+=cald(y,x),mx[x]=max(mx[x],mx[y]+1);
	c+=mx[x]>=D;
	return c;
}
int calc(int u,int v){
	int p,q;
	ban=u,md=0,rt=v,dfs(v,0,0),q=rt,md=0,dfs(q,0,0),p=rt;
	for(int i=0;i<md/2;++i) p=fa[p];
	return max(1,cald(p,0));
}
bool chk(int d){
	D=d;
	int mn=1e9;
	if(C<=8){
		for(int i=1;i<=n;++i) for(int j:G[i]) if(i<j) mn=min(mn,calc(i,j)+calc(j,i));
		return mn<=k;
	}
	int cen=vc[t/2+1];
		// printf("%d\n",cen);
	dfs2(cen,0,c1);
	for(int i=1;i<=t;++i){
		int x=vc[i];
		for(int y:G[x]) if(!vis[y]) mn=min(mn,c1[cen]-c1[y]+calc(x,y));
	}
	dfs2(q,0,c1),dfs2(p,0,c2);
	// printf("%d %d\n",p,q);
	int pp=1+d;
	for(int i=1+d;i<t-d;++i){
		pp=max(pp,i-max(0,d-mc[vc[i]]));
		v1[i]=c1[vc[pp]];
	}
	pp=t-d;
	mn=min(mn,c1[vc[t/2]]+c2[vc[t/2+1]]);
	for(int i=t-d;i>1+d;--i){
		pp=min(pp,i+max(0,d-mc[vc[i]]));
		mn=min(mn,v1[i-1]+c2[vc[pp]]);
	}
	return mn<=k;
}
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) G[i].clear(),vis[i]=0;
	for(int i=1,u,v;i<n;++i)
		scanf("%d%d",&u,&v),G[u].push_back(v),G[v].push_back(u);
	ban=0,md=0,rt=1,dfs(1,0,0),q=rt,md=0,dfs(q,0,0),p=rt;
	t=0;
	for(int x=p;x;x=fa[x]) vc[++t]=x,vis[x]=1;
	for(int i=1;i<=t;++i) cal(vc[i],0);
	int l=0,r=(t-1)/2,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid)) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int T;scanf("%d%d",&C,&T);
	while(T--) solve();
}