#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=30,M=100,INF=(LONG_LONG_MAX>>2);
int c,T,n,k,ans,co[N],gg[N],vis[N],cnt;
int head[N],nxt[M],to[M],tot;
inline void add(int x,int y){
	nxt[++tot]=head[x];head[x]=tot;to[tot]=y;
}
inline int get_cnt(int x){
	int ret=0;
	for(;x;x-=x&-x)ret++;
	return ret;
}
void dfs(int x){
	co[x]=cnt;
	for(int i=head[x];i;i=nxt[i]){
		if(!gg[to[i]]||co[to[i]])continue;
		dfs(to[i]);
	}
}
inline bool ck(int x){
	cnt=0;
	memset(gg,0,sizeof(gg));
	memset(co,0,sizeof(co));
	if(get_cnt(x)!=k)return false;
	for(int i=1;i<=n;i++)if(x&(1<<i-1))gg[i]=1;
	for(int i=1;i<=n;i++)if(gg[i]&&!co[i]){
		cnt++;dfs(i);
	}
	if(cnt>2)return false;
	return true;
}
inline int bfs(){
	int ret=0;
	queue<pair<int,int> >qq;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++){
		if(gg[i]){
			qq.push(make_pair(i,0));
			vis[i]=1;
		}
	}
	while(qq.size()){
		int x=qq.front().first;
		int vv=qq.front().second;
		ret=max(ret,vv);
		qq.pop();
		for(int i=head[x];i;i=nxt[i]){
			int y=to[i];
			if(vis[to[i]])continue;
			vis[to[i]]=1;qq.push(make_pair(to[i],vv+1));
		}
	}
	return ret;
}
inline void clear(){
	ans=INF;tot=0;
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	memset(to,0,sizeof(to));
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		clear();
		scanf("%lld%lld",&n,&k);
		for(int i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y),add(x,y),add(y,x);
		for(int i=0;i<(1<<n);i++){
			if(!ck(i))continue;
			ans=min(ans,bfs());
		}
		printf("%lld\n",ans);
	}
	return 0;
}