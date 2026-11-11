#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,l,r) for(int i=(l),num##i=(r);i<=num##i;++i)
#define per(i,r,l) for(int i=(r),num##i=(l);i>=num##i;--i)
#define fileI(x) freopen(x,"r",stdin)
#define fileO(x) freopen(x,"w",stdout)
#define ML printf("\n.2lf MB\n",(&M2-&M1)/1024.0/1024)
#define TL printf("\n.2lf s\n",1.0*clock()/CLOCKS_PER_SEC)
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define pq priority_queue
//bool M1;
namespace IO{
	const int SIZE=1<<20;
	char buf[SIZE],*p1=buf,*p2=buf;
	inline char gc(){ return p1==p2&&(p2=(p1=buf)+fread(buf,1,SIZE,stdin), p1==p2)?EOF:*p1++; }
	void read(int &x){
		x=0;
		char ch=gc();
		while(ch<'0'||ch>'9')ch=gc();
		while(!(ch<'0'||ch>'9'))x=(x<<3)+(x<<1)+(ch^48),ch=gc();
	}
}
using IO::read;
const int N=505,M=5e5+5,DMAX=22,Q=1e5+5;
//int read(){
//	int x=0;
//	char ch=getchar();
//	while(ch<'0'||ch>'9')ch=getchar();
//	while(!(ch<'0'||ch>'9'))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
//	return x;
//}
const ll INF = 0x3f3f3f3f3f3f3f3f;
int bianhao,n,m,dmx,q,w[M];
vector<pii > G[M];
ll dis[N][N];
void Ckmin(ll &x,ll y){ if(x>y)x=y; }
//bool M2;
int main(){
	fileI("subway.in");
	fileO("subway.out");
//	scanf("%d%d%d%d%d",&bianhao,&n,&m,&dmx,&q);
	read(bianhao),read(n),read(m),read(dmx),read(q);
//	rep(i,1,m)scanf("%d",&w[i]);
	rep(i,1,m)read(w[i]);
//	TL;
	rep(i,1,n){
		int k;
		read(k);
//		scanf("%d",&k);
		rep(j,1,k){
			int a,t;
			read(a),read(t);
//			scanf("%d%d",&a,&t);
			G[a].pb({i,t});
		}
	}
	rep(i,1,n)rep(j,1,n)if(i!=j)dis[i][j]=INF;
//	cerr << 1.0*clock()/CLOCKS_PER_SEC << '\n';
	rep(num,1,m){
		int sz=G[num].size();
		rep(i,0,sz-1){
			pii ii=G[num][i];
			rep(j,i+1,sz-1){
//				if(ii.fi>G[num][j].fi)printf("Wa1\n");
				Ckmin(dis[ii.fi][G[num][j].fi],ii.se+G[num][j].se);
			}
		}
	}
	rep(i,1,n){
		rep(j,i+1,n){
			dis[j][i]=dis[i][j];
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			rep(k,1,n){
				Ckmin(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		read(x),read(y);
		ll ans=w[x]+w[y],tmp=INF;
		for(pii xi : G[x]){
			for(pii yi : G[y]){
				Ckmin(tmp,xi.se+dis[xi.fi][yi.fi]+yi.se);
			}
		}
		ans+=tmp;
		printf("%lld\n",ans);
	}
//	cerr << (&M2-&M1)/1024.0/1024 << '\n';
	return 0;
}
/*
同一条线路不会重复经过同一个地铁站
每个地铁站最多有 d 条线路经过。
任意两个地铁站都可以通过若干条线路互相到达

*/