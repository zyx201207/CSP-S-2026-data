#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,M=1e3+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+c-48;
		c=getchar();
	}
	return x*f;
}
int c,T,n,k,ans,p[N],dis[M][M];
struct edge{
	int to,val;
};
vector<edge>e[N];
inline void add(int x,int y,int z){
	e[x].push_back((edge){y,z});
	return;
}
void get_dis(int s,int u,int fa,int ds){
	dis[s][u]=ds;
	for(edge v:e[u]){
		if(v.to==fa)continue;
		get_dis(s,v.to,u,ds+1);
	}
	return;
}
void dfs(int now,int cnt){
	if(now==n&&cnt<k)return;
	if(cnt==k){
		int res=1e18;
		for(int i=1;i<=n;i++){
			res=1e18;
			if(p[i])continue;
			for(int j=1;j<=n;j++)if(p[j])res=min(res,dis[i][j]);
			if(res>ans){
				ans=res;
//				for(int i=1;i<=n;i++)printf("%lld ",p[i]);
//				puts("");
			}
		}
//		ans=max(ans,res);
		return;
	}
	p[now+1]=1;
	dfs(now+1,cnt+1);
	p[now+1]=0;
	dfs(now+1,cnt);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),k=read();ans=0;
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			add(x,y,1);
			add(y,x,1);
		}
		for(int i=1;i<=n;i++)get_dis(i,i,0,0);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				printf("%lld ",dis[i][j]);
//			}
//			puts("");
//		}
		dfs(0,0);
		printf("%lld\n",ans);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=0;
		for(int i=1;i<=n;i++)p[i]=0;
	}
	return 0;
}
