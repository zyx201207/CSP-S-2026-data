#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
const int inf=0x3f3f3f3f3f3f3f3f;
int op,T,n,k,tot,head[20],c[20],vis[20],d[20],now,ans;
struct node{
	int v,nxt;
}a[40];
void add(int u,int v){
	a[++tot]=node{v,head[u]};
	head[u]=tot;
}
void dfs1(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		int y=a[i].v;
		if(y==fa||vis[y]) continue;
		if(c[y]){
			vis[y]=1;
			dfs1(y,x);
		}
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=a[i].nxt){
		int y=a[i].v;
		if(y==fa||vis[y]||c[y]) continue;
		vis[y]=1;
		d[y]=min(d[y],d[x]+1);
		dfs2(y,x);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&op,&T);
	while(T--){
		ans=inf,tot=0;
		memset(head,0,sizeof head);
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			add(u,v);
			add(v,u);
		}
		for(int i=0;i<(1ll<<n);i++){
			int x=i,cnt=0,p=0;
			now=0;
			memset(c,0,sizeof c);
			while(x){
				p++;
				if(x&1){
					cnt++;
					c[p]=1;
				}
				x>>=1;
			}
			if(cnt!=k) continue;
			cnt=0;
			for(int j=1;j<=n;j++){
				if(!vis[j]&&c[j]){
					vis[j]=1;
					dfs1(j,0);
					cnt++;
				}
			}
			if(cnt>2) continue;
			memset(vis,0,sizeof vis);
			memset(d,0x3f,sizeof d);
			for(int j=1;j<=n;j++) if(c[j]) d[j]=0;
			for(int j=1;j<=n;j++){
				if(c[j]&&!vis[j]){
					dfs2(j,0);
				}
			}
			for(int j=1;j<=n;j++) if(!c[j]) now=max(now,d[j]);
			ans=min(ans,now);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

