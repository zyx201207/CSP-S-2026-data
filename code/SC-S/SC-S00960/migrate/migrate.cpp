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
bool M1;
const int N=305,INF=0x3f3f3f3f;
int n;
pii dis[N][N];
pii operator + (const pii &a,const pii &b){
	if(a.fi!=b.fi)return a.fi<b.fi?a:b;
	return {a.fi,min(a.se+b.se,3)};
}
ll lim,x[N];
int bianhao;
void Sol(){
	scanf("%d%lld",&n,&lim);
	rep(i,1,n)scanf("%lld",&x[i]);
	rep(i,1,n)rep(j,1,n)dis[i][j]={INF,0};
//	rep(i,1,n)dis[i][i]={0,1};
	for(int i=1,l=1,r=1;i<=n;++i){
		while(r<=n&&x[r]-x[i]<=lim)++r;
		while(x[i]-x[l]>lim)++l;
//		cerr<<l<<' '<<r-1<<'\n';
//		dmx[i]=r-1,dmi[i]=l;
		rep(j,l,r-1)if(i!=j){
			dis[i][j]=dis[j][i]={1,1};
		}
	}
	rep(i,1,n){
		rep(j,1,n){
			rep(k,1,n){
				pii tmp = {dis[i][k].fi+dis[k][j].fi,min(1LL*dis[i][k].se*dis[k][j].se,3LL)};
				if(tmp.fi<dis[i][j].fi){
					dis[i][j]=tmp;
				}
				else if(tmp.fi==dis[i][j].fi){
					dis[i][j].se=min(dis[i][j].se+tmp.se,3);
				}
			}
		}
	}
	ll ans=0;
	rep(i,1,n){
		rep(j,i+1,n)if(dis[i][j].se==2){
			++ans;
		}
	}
	printf("%lld\n",ans);
}
bool M2;
int main(){
	fileI("migrate.in");
	fileO("migrate.out");
	int T;
	scanf("%d%d",&bianhao,&T);
	while(T--)Sol();
	return 0;
}