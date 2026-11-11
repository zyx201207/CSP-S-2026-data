#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+7,M=15000000,INF=(LONG_LONG_MAX>>2);
int c,T,n,d,ans,ds[N],cnt[N],dis[N],vis[N];
int head[N],nxt[M],to[M],tot;
inline void add(int x,int y){
	nxt[++tot]=head[x];head[x]=tot;to[tot]=y;
}
inline void spfa(int s){
	for(int i=0;i<=n;i++){
		cnt[i]=vis[i]=0;
		dis[i]=INF;
	}
	queue<int>qq;
	dis[s]=0;vis[s]=1;
	qq.push(s);cnt[s]=1;
	while(qq.size()){
		int x=qq.front();
		qq.pop();vis[x]=0;
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(dis[y]>=dis[x]+1){
				cnt[y]+=cnt[x];
				if(dis[y]>dis[x]+1){
					dis[y]=dis[x]+1;
					if(!vis[y]){
						vis[y]=1;
						qq.push(y);
					}
				}
			}
		}
	}
}
inline void clear(){
	for(int i=0;i<=n;i++)
		head[i]=ds[i]=cnt[i]=dis[i]=vis[i]=0;
	for(int i=0;i<=tot;i++)
		nxt[i]=to[i]=0;
	tot=ans=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		clear();
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&ds[i]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ds[j]-ds[i]>d)break;
				add(i,j);
			}
		}
		for(int i=1;i<=n;i++){
			spfa(i);
			for(int j=i;j<=n;j++){
				if(cnt[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}