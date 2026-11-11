//CSP-S 2026 C 
//Last change time:18:22:15
//E(Points):40
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
const long long N=2e6+5,M=5e3+5,inf=LLONG_MAX/2;
long long c,t,n,d,x[N],lst[N],pre[N],dis[M][M],vis[M],cnt[M][M];
queue<long long>q;queue<pair<long long,long long> >qu; 
void bfs(long long s){
	for(long long i=1;i<=n;i++)dis[s][i]=inf,vis[i]=0;
	dis[s][s]=0;q.push(s);vis[s]=1;
	while(!q.empty()){
		long long u=q.front();q.pop();
		for(long long i=pre[u];i<=lst[u];i++){
			if(!vis[i]){
				dis[s][i]=dis[s][u]+1;
				q.push(i);vis[i]=1;
			}
		}
	}
}
void bfd(long long s){
	for(long long i=1;i<=n;i++)vis[i]=0,cnt[s][i]=0;
	qu.push({s,0});cnt[s][s]=1;vis[s]=1;
	while(!qu.empty()){
		long long u=qu.front().first,de=qu.front().second;qu.pop();
		for(long long i=pre[u];i<=lst[u];i++){
			if(dis[s][i]==de+1&&u!=i){
				cnt[s][i]+=cnt[s][u];
				if(!vis[i])qu.push({i,de+1}),vis[i]=1;
			}
		} 
	}
}
void solve(){
	long long ans=0;
	n=read(),d=read();x[n+1]=inf;x[0]=-inf;
	for(long long i=1;i<=n;i++)x[i]=read();
	for(long long i=1;i<=n;i++){
		long long L=i,R=n+1;
		while(L<=R){
			long long mid=(L+R)>>1;
			if(x[mid]-x[i]<=d)lst[i]=mid,L=mid+1;
			else R=mid-1; 
		}L=0,R=i;
		while(L<=R){
			long long mid=(L+R)>>1;
			if(x[i]-x[mid]<=d)pre[i]=mid,R=mid-1;
			else L=mid+1;
		}
	}
	for(long long i=1;i<=n;i++)bfs(i);
	for(long long i=1;i<=n;i++)bfd(i);
	for(long long i=1;i<=n;i++)
		for(long long j=i+1;j<=n;j++)
			ans+=(cnt[i][j]==2);
	write(ans);el;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();while(t--)solve();
	return 0;
}
