//CSP-S 2026 D
//Last change time:18:21:36
//E(Points):15
#include<bits/stdc++.h>
#define ps putchar(32)
#define el putchar(10)
using namespace std;
long long read(){
	long long f=1,x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch==45)f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
	return (f==1)?x:-x;
}
void write(long long x){
	if(x<0){putchar(45);x=-x;}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const long long N=200,inf=LLONG_MAX/2; 
long long c,t,n,k,head[N],cnt,dis[N][N],vis[N],ans[N],fa[N],vi[N],res;
struct edge{long long to,nxt;}e[N];struct gdee{long long u,v;}g[N];
void add(long long u,long long v){e[++cnt]={v,head[u]};head[u]=cnt;}
void d(){for(long long i=1;i<=n;i++)vis[i]=0;} 
void dfs1(long long ro,long long now,long long dep){
	vis[now]=1;dis[ro][now]=dep;
	for(long long i=head[now];i;i=e[i].nxt)
		if(!vis[e[i].to])dfs1(ro,e[i].to,dep+1);
}
long long find(long long x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
bool merge(long long u,long long v){
	u=find(u),v=find(v);
	if(u==v)return false;
	fa[u]=v;return true;
}
void dfs(long long now,long long num){
	if(now==n+1){
		long long anss=0;
		for(long long i=1;i<=n;i++)fa[i]=i;
		for(long long i=1;i<n;i++)
			if(vi[g[i].u]&&vi[g[i].v])anss+=merge(g[i].u,g[i].v);
		if(anss>=k-2){
			long long tmp=0;
			for(long long i=1;i<=n;i++){
				long long ttmp=inf;
				for(long long j=1;j<=k;j++)
					ttmp=min(ttmp,dis[i][ans[j]]);
				tmp=max(tmp,ttmp);
			}res=min(res,tmp);
		}return;
	}
	if(num<k){
		ans[num+1]=now;vi[now]=1;
		dfs(now+1,num+1);
		ans[num+1]=0;vi[now]=0;
	}
	if(n-now+1>k-num)dfs(now+1,num);
} 
void solve(){
	n=read(),k=read();cnt=0;
	for(long long i=1;i<=n;i++)head[i]=0;
	for(long long i=1;i<n;i++){
		long long u=read(),v=read();
		add(u,v);add(v,u);g[i]={u,v};
	}
	for(long long i=1;i<=n;i++)d(),dfs1(i,i,0);
	res=inf;dfs(1,0);write(res);el;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=read(),t=read();while(t--)solve();
	return 0;
}

