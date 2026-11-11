#include<bits/stdc++.h>
#define rep(i,x,y) for(long long i=x;i<=y;++i)
#define repp(i,x,y) for(long long i=x;i>=y;--i)
using namespace std;
const int N=500,M=5e5;
int c,n,m,d,q;
int w[M+10];
long long dis[N+10][N+10];
struct P {int x,y;};
int le[M+100];
P v[M+100][45];
int st,ed;
long long min(long long x,long long y) {
	return x>y?y:x;
}
char ch;
int read() {
	int x=0ll;
	ch=getchar();
	while(ch!=' '&&ch!='\n') x=x*10+ch-'0',ch=getchar();
	return x;
}
void solve() {
	st=read(),ed=read();
	long long ans=LONG_LONG_MAX;
	rep(i,1,le[st])
		rep(j,1,le[ed])
			ans=min(ans,(long long)v[st][i].y+(long long)v[ed][j].y+dis[v[st][i].x][v[ed][j].x]);
	printf("%lld",ans+w[st]+w[ed]),putchar('\n');
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	rep(i,1,m) w[i]=read();
	int k,x,y;
	P p;
	rep(i,1,n) {
		k=read();
		rep(j,1,k) {
			x=read(),y=read();
			p.x=i,p.y=y;
			v[x][++le[x]]=p;
		}
	}
	memset(dis,0x3f3f3f,sizeof dis);
	rep(i,1,n) dis[i][i]=0ll;
	rep(i,1,m) {
		rep(j,1,le[i])
			rep(k,1,le[i])
				if(j!=k)
					dis[v[i][j].x][v[i][k].x]=min(dis[v[i][j].x][v[i][k].x],(long long)(v[i][j].y)+v[i][k].y);
	}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--) solve();
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/