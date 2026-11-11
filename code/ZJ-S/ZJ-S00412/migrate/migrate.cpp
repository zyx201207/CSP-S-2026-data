#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2000005,INF=1ll<<60;
int c,T,n,d,a[maxn],l[maxn],r[maxn],vis[maxn],dis[maxn],cnt;
inline int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f^=!(ch^'-'),ch=getchar();
	while( isdigit(ch)){
		ret=(ret<<3)+(ret<<1)+(ch^48);
		ch=getchar();
	}
	return ret*(f-(f^1));
}
void bfs(int st){
	for(int i=1;i<=n;i++) dis[i]=0,vis[i]=0;
	queue <int> q;
	q.push(st);
	vis[st]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=l[u];i<=r[u];i++){
			if(i==u||i==st) continue;
			if(dis[i]==dis[u]+1){
				vis[i]+=vis[u];
//				printf("OK%d %d %d\n",st,u,i);
			}
			if(dis[i]) continue;
			dis[i]=dis[u]+1;
			vis[i]=vis[u];
			q.push(i);
		}
	}
}
void print(int prt[]){
	for(int i=1;i<=n;i++) printf("%d%c",prt[i],i==n?'\n':' ');
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		n=read();d=read();cnt=0;
		for(int i=1;i<=n;i++) a[i]=read();
		a[n+1]=INF;
		for(int i=1;i<=n;i++){
			int L=a[i]-d,R=a[i]+d;
			l[i]=lower_bound(a+1,a+n+2,L)-a;
			r[i]=upper_bound(a+1,a+n+2,R)-a-1;
		}
		for(int i=1;i<=n;i++){
			bfs(i);
//			print(dis);
			for(int j=i+1;j<=n;j++) if(vis[j]==2) cnt++;
		}
//		printf("vis:::\n");for(int i=1;i<=n;i++) bfs(i),print(vis);
		printf("%d\n",cnt);		
	}
	return 0;
}