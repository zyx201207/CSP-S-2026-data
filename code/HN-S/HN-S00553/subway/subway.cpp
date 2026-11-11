#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
const int NR=505,MR=5e5+5;
int c,n,m,d,q,w[MR],k[NR],x,y; 
ll Dis[NR][NR],ans=0;
struct Lix{
	int id,t;
};
vector<Lix>R[MR];
void P1() {
	cin>>c>>n>>m>>d>>q;
	rep(i,1,m)cin>>w[i];
	memset(Dis,0x3f,sizeof(Dis));
	rep(i,1,n) {
		int p,t;
		cin>>k[i];
		rep(j,1,k[i]) {
			cin>>p>>t;
			R[p].push_back({i,t});
		}
	}
	rep(i,1,n)
		Dis[i][i]=0;
	rep(p,1,m) {
		rep(i,0,(int)R[p].size()-1) {
			rep(j,i+1,(int)R[p].size()-1) {
				Lix u=R[p][i],v=R[p][j];
				Dis[u.id][v.id]=min(Dis[u.id][v.id],(ll)u.t+v.t);
			}
		}
	}
	rep(i,1,n)rep(j,1,n)Dis[i][j]=min(Dis[i][j],Dis[j][i]);
}
void P2() { //Floyd
	rep(k,1,n) 
		rep(i,1,n)
			rep(j,1,n)
				Dis[i][j]=min(Dis[i][j],Dis[i][k]+Dis[k][j]);
}
void P3() {
	while(q--) {
		cin>>x>>y;
		ans=w[x]+w[y];
		ll dis_sum=inf;
		for(Lix o_0:R[x]) 
			for(Lix o_1:R[y]) 
				dis_sum=min(dis_sum,(ll)o_0.t+(ll)o_1.t+Dis[o_0.id][o_1.id]);
		ans+=dis_sum;
		cout<<ans<<'\n';
	}
}
signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	P1();
	P2();
	P3();
	return 0;	
}