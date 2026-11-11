#include<bits/stdc++.h>
#define fir first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template <typename ty>
inline void read(ty &x) {
	x=0; bool f=0; char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	if(f) x=-x;
}
template <typename ty,typename ...T>
inline void read(ty &x,T &...te) {
	read(x); read(te...);
}
//const int N=1e6+5,M=2e6+5;
const int N=4005,M=2e6+5;
int head[N],nxt[M],to[M],num;
void add(int u,int v) {
	++num; nxt[num]=head[u]; to[num]=v; head[u]=num;
}
int dep[N],mxdep[N];
int cnt[N<<1][N]; 
int ans,mid;
int n,k;
void dfs0(int u,int fa,int eid) {
	mxdep[u]=0;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		dfs0(v,u,eid);
		mxdep[u]=max(mxdep[u],mxdep[v]+1);
	}
	cnt[eid][mxdep[u]]++;
}
void dfs(int u,int fa) {
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		memset(cnt[i],0,sizeof(cnt[i])); dfs0(v,u,i);
//		for(int j=0;j<=n;j++) printf("%d ",cnt[num][j]); puts("??");
		memset(cnt[i^1],0,sizeof(cnt[i^1])); dfs0(u,v,i^1);
		dfs(v,u);
	}
}
void dfs2(int u,int fa) {
	mxdep[u]=0;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs2(v,u);
		mxdep[u]=max(mxdep[u],mxdep[v]+1);
	}
}
bool flag;
void dfs1(int u,int fa,int eid1,int eid2,int lim) {
	if(lim<0) return ;
//	printf("?%d %d %d %d lim:%d cnt1:%d cnt2:%d mid:%d\n",u,fa,eid1,eid2,lim,cnt[eid1][mid],cnt[eid2][mid],mid);
	if(max(cnt[eid1][mid],1)+max(cnt[eid2][mid],1)<=k) flag=true;
	int mx=-1,mxid=-1,smx=-0x3f3f3f3f;
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		if(mxdep[v]>mx) {
			smx=mx;
			mx=mxdep[v],mxid=v;
		}else smx=max(smx,mxdep[v]);
	}
	for(int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if(v==fa) continue;
		int val;
		if(v==mxid) val=smx;
		else val=mx;
//		printf("%d->%d val:%d %d %d %d\n",u,v,val,mx,mxid,smx);
		int llim;
		llim=lim-1;
		if(val+dep[u]+1<=mid) ;
		else llim=min(llim,mid-val-2);
		dfs1(v,u,eid1,i,llim);
	}
}
bool check() {
	flag=false;
	for(int x=1;x<=n;x++) {
//		printf("rt:%d\n",x);
		dep[x]=0;
		dfs2(x,-1);
		for(int i=head[x];i;i=nxt[i]) {
			int v=to[i];
			dfs1(v,x,i^1,i,0x3f3f3f3f);
		}
//		if(x==1) {
//			int cnt=0;
////			for(int i=1;i<=n;i++) if(mxdep[i]>=mid)
////				cnt++;
//			if(cnt<=k) flag=true;
//		}
	}
	return flag;
}
void solve() {
	read(n,k);
	for(int i=1;i<=n;i++) head[i]=0; num=1;
	for(int i=1;i<n;i++) {
		int u,v;
		read(u,v);
		add(u,v);
		add(v,u);
	}
	dfs(1,-1);
	for(int i=1;i<=num;i++) {
		for(int j=n-1;j>=0;j--) cnt[i][j]+=cnt[i][j+1];
//		for(int j=0;j<=n;j++) printf("%d ",cnt[i][j]); puts("");
	}
	mid=0;
//	cerr<<"check:"<<check()<<endl;
	int l=0,r=n,ans=n+1;
	while(l<=r) {
		mid=l+r>>1;
		if(check()) r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	read(c,T);
	while(T--) solve();
	return 0;
}
