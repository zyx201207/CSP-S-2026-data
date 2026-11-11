#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);i++)
#define DEP(i,a,b) for(int i=(a);i>=(b);i--)
#define REPc(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define DEPc(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
#define MOD(a) (((a)%mod+mod)%mod)
#define ADD(a,b) (a)=(mod+(a)+(b))%mod
#define SUB(a,b) (a)=(mod+(a)-(b))%mod
#define MUL(a,b) (a)=(1ll*(a))*((b)%mod)%mod
#define MAX(a,b) (a)=max((a),(b))
#define MIN(a,b) (a)=min((a),(b))
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 2000000000000000000
using namespace std;
namespace WuJy{
	#define epb emplace_back
	#define pil pair<int,long long>
	const int N=505,M=5e5+5;
	int useless,n,m,d,q;
	ll cst[M];
	vector<pil>sta[M];
	ll dis[N][N];
	void main(){
		cin>>useless>>n>>m>>d>>q;
		REP(i,1,m)cin>>cst[i];
		REP(i,1,n){
			REP(j,1,n)dis[i][j]=(i!=j)*INF;
			int k;cin>>k;
			while(k--){
				int u;ll w;cin>>u>>w;
				sta[u].epb(i,w);
			}
		}
		REP(i,1,m){
			int num=SZ(sta[i]);
			REP(j,0,num-1)REP(k,j+1,num-1){
				int u=sta[i][j].fi,v=sta[i][k].fi;
				ll val=sta[i][j].se+sta[i][k].se;
				MIN(dis[u][v],val),MIN(dis[v][u],val);
			}
		}
		REP(k,1,n)REP(i,1,n)REP(j,1,n)
			MIN(dis[i][j],dis[i][k]+dis[k][j]);
		while(q--){
			int u,v;ll ans=INF;cin>>u>>v;
			REP(i,0,SZ(sta[u])-1)REP(j,0,SZ(sta[v])-1)
				MIN(ans,cst[u]+cst[v]+sta[u][i].se+sta[v][j].se+dis[sta[u][i].fi][sta[v][j].fi]);
			cout<<ans<<'\n';
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)WuJy::main();
	return 0;
}
