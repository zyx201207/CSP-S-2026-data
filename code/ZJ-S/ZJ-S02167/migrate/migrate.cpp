#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=300;
int n;
long long d;
long long a[N+100];
int dis[N+10][N+10],ans=0;
struct Vector {
	int u,v,next;
}vt[N*N*2+100];
int cnt,head[N+100];
void add(int u,int v) {
	vt[++cnt].u=u,vt[cnt].v=v,vt[cnt].next=head[u];
	head[u]=cnt;
}
int st,ed;
int sum=0;
void dfs(int u,int pre,int d) {
	if(sum>2) return ;
	if(d>dis[st][ed]) return ;
	if(u==ed&&d==dis[st][ed]) {
		++sum;
		return ;
	}
	for(int i=head[u];i!=0;i=vt[i].next) {
		int v=vt[i].v;
		if(v==pre) return ;
		dfs(v,u,d+1);
	}
}
void solve() {
	scanf("%d%lld",&n,&d);
	cnt=ans=0;
	rep(i,1,n) head[i]=0;
	rep(i,1,n) scanf("%lld",a+i);
	sort(a+1,a+1+n);
	memset(dis,0x3f3f3f,sizeof dis);
	rep(i,1,n) dis[i][i]=0;
	rep(i,1,n)
		rep(j,i+1,n)
			if(a[j]-a[i]<=d)
				dis[i][j]=dis[j][i]=1,add(i,j),add(j,i);
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(st=1;st<=n;++st)
		for(ed=st+1;ed<=n;++ed) {
			sum=0,dfs(st,0,0);
			if(sum==2) ++ans;
		}
	printf("%d\n",ans);
}
int main () {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d%d",&c,&T);
	while(T--) solve();
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/