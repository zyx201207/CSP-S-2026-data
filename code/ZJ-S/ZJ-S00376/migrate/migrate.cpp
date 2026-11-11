#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF=1ll<<62;
int c,t,n,hed[5005],cnt;
bool vis[5005];
ll a[5005],d,dis[5005],ans,g[5005];
struct edge{
	int t,nt;
}e[12500005];
void add_e(int x,int y){
	e[++cnt]=(edge){y,hed[x]};
	hed[x]=cnt;
}
ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
void BFS(int s){
	for(int i=1;i<=n;i++)
		dis[i]=INF,g[i]=0,vis[i]=0;
	dis[s]=0,g[s]=1;
	queue<int> q;q.push(s);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(vis[x]) continue;
		vis[x]=1;
//		if(x==4) printf("743724\n");
		for(int i=hed[x];i;i=e[i].nt){
			if(dis[e[i].t]>dis[x]+1){
				dis[e[i].t]=dis[x]+1;
				g[e[i].t]=g[x];
			}else
			if(dis[e[i].t]==dis[x]+1)
				g[e[i].t]+=g[x];
			q.push(e[i].t);
		}
	}
	for(int i=1;i<=n;i++)
		ans+=(g[i]==2);
//	printf("%d\n",dis[4]);
}
void solve(){
	cnt=0,ans=0;
	for(int i=1;i<=n;i++) hed[i]=0;
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n==1){
		printf("0\n");
		return;
	}
//	sort(a+1,a+1+n);
	for(int i=1,x=0;i<=n;i++){
		while(a[x+1]-a[i]<=d&&x+1<=n) x++;
//		x--;
		for(int j=i+1;j<=x;j++) add_e(i,j);
	}
	for(int i=1;i<=n;i++) BFS(i);
	printf("%lld\n",ans);
}
void solve2(){
	n=read(),d=read();
	for(int i=1;i<=n;i++) a[i]=read();
	printf("0\n");
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	if(c<=10){
		while(t--) solve();
		return 0;
	}
	if(c<=14){
		while(t--) solve2();
		return 0;
	}
	return 0;
}
